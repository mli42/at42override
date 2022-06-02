# level06

Après avoir lu le code source, \
On voit qu'il attend un login et un mot de passe

Le mot de passe est calculé dans `auth()` à partir du login qu'on a donné

En allant chercher à la fin de la boucle qui determine le mot de passe (`<auth+286>`) on peut chopper le resultat final attendu pour le login donné

Dans gdb on met un breakpoint avant le call de ptrace (`0x080487b5 <auth+109>`) \
On met également un breakpoint à la comparaison (`0x08048866 <auth+286>`) \
Arrivé au 1er breakpoint, on jump pour ne pas avoir la protection ptrace, `jump * 0x80487ed` \
Arrivé au 2e breakpoint, on imprime la valeur de `ebp-0x10`:
```
(gdb) x/x $ebp-0x10
0xffffd5b8:     0x005f1ae1
```

Pour `coucou` en login on doit donner `6232801` en password

On obtient un shell et puis comme d'habitude:
```bash
$ cat /home/users/level07/.pass
# GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8
```
