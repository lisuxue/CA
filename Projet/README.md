# Projet CA : Mini-ZAM

Projet numéro 1 de l'UE de Master STL Compilation Avancée
Fait Par XAVIER Julien et LI Suxue

## Structure

parser.ml : Parsing des fichiers .txt en triplet d'information -> Label/Instruction/Arguments

minizam.ml : Interprétation des données et évaluation d'un programme .txt

main_direct.ml : Affichage du résultat en sortie standard Out et du Resultat en fin de programme Res

main_trace.ml : Evaluation détaillée de chaque instruction en montrant ainsi l'évolution du pointeur *pc*, de l'accumulateur *accu*, de la pile *stack*, de l'environnement de la fermeture courante *env*, du contexte stocké lors d'appel de fonctions *extra_args* et de la position du rattrapeur d’exceptions *trap_sp*.

MakeFile : fichier à run pour compiler l'interpréteur.

tests/ : tests afin de tester la mini-ZAM

rapport/ : rapport écrit du projet en laTeX.

## Compilation et lancement d'un test
### Main Direct
```sh
$ make
$ ./main_direct tests/chemin_du_fichier_à_tester.txt
```

### Main Détaillé
```sh
$ make
$ ./main_trace tests/chemin_du_fichier_à_tester.txt
```
### Clean du projet
```sh
$ make clean
```
