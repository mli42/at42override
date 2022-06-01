# level06

pour le level on lit le code source,

On voit qu'il attend un login et un mot de passe


Le mot de passe est calculé dans auth à partir du login qu'on à donné

En allant chercher à la fin de la boucle qui determine le mot de passe <auth+286> on peut chopper le resultat final attendu pour le login donné

pour `coucou` en login on doit donner `6232801`
