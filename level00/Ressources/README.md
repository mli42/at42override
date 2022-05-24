# level00

On voit que le binaire attend en entrée un int

Si cet int est égal à `0x149c` (`5276` en décimal), on nous donne un shell, sinon on n'est pas authentifié.

Ainsi:
```
$ ./level00
***********************************
*            -Level00 -           *
***********************************
Password:5276

Authenticated!
$ cat /home/users/level01/.pass
uSq2ehEGT6c9S24zbshexZQBXUGrncxn5sD5QfGL
```
