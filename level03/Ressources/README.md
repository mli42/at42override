# level03

Note: Ce niveau a `Canary found`, c'est un `Buffer overflow protection`

On voit qu'on peut rentrer un nombre qui sera soustrait par `0x1337d00d` dans la fonction test.

Le résultat doit être entre `0` et `0x15` (`21`) car dans l'asm c'est une instruction `ja` (jump above, unsigned).

Sinon il essayera un decrypt random.

On peut donc bruteforce la solution en essayant les 22 possibilités (de 0 à 21) avec [le script shell](./bruteforce.sh) dans les ressources.

On trouve que la clé est `18`:
```bash
(python -c "print (0x1337d00d - 18)"; cat) | ./level03
```
