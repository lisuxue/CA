Explication des programmes principaux mis à votre disposition 

* TP1 * 
1) test_decoupage_fonction.cpp : montre les fonctions du programme passé en paramètre (fichier)
2) test_decoupage_bb.cpp : pour tester le decoupage des blocs de base des fonctions du programme paramètre. Construit les BB de chaque fonction, et les affiches. 

3) test_liens_bb.cpp : pour tester la construction des blocs successeurs et prédécesseurs des BB des fonctions du programme. Construit les BB de chaque fonction, calcul les liens entre les BB puis crée un fichier .dot, dans le répertoire tmp à la racine, pour chaque CFG associé à une focntion. Un CFG représente liens de précédence entre les BB d'une fonction.

* TP2 *

1) test_dominants.cpp : pour tester calcul des blocs dominants dans un CFG / fonction du programme. Ce programme calcule les BB de chaque fonction, leur liens, puis détermine les blocs dominants pour chaque BB et les affiche. Ce programme crée un fichier .dot pour chaque CFG (dans le répertoire tmp à la racine), permettant de confronter les résultats de l'analyse de dominance avec une analyse manuelle et visuelle.

2) test_loops.cpp : pour tester le calcul des boucles des fonctions, affiche les boucles et les blocs les compoants pour chaque fonction du programme paramètre

* TP3 * 
1) test_dependance_instr.cpp : calcule les dependances entre les instructions de chaque BB de chaque fonction et affiche celles-ci, génère un DAG du BB visualisable. Le DAG montre les dépendances entre les instructions d'un BB. 
2) test_nbcycles.cpp : calcul et montre le nombre de cycles pour chaque BB de chaque fonction. 
3) test_scheduling.cpp : on peut utiliser le scheduling pour voir ce que l'on pourrait gagner à réordonnancer les BB en terme de performance.

* TP4 * 
3) test_def_use_bb.cpp : calcule les ensemble USE et DEF pour chaque BB de chaque fonction et affiche le resultat
4) test_live_var.cpp : calcule les registres vivants en entrée et en sortie de chaque BB de chaque fonction

	
* TP5 et projet *
1) test_defliveout.cpp : calcule les définitions vivantes en sortie des BB et les affiche
2) test_renommage.cpp : renomme les registres des BB et affiche les BB renommés, ensuite recalcule les dependances entre instructions, génère  un DAG représentant les dependances des instructions dans le BB renommés, et exporte dans un fichier .dot du DAG dans le répertoire tmp à la racine) 
3) test_renommage_gain.cpp : calcule le gain en nb de cycles du renommage 
4) test_renommage_scheduling.cpp : affiche le nb de cycles de chaque BB, renomme les registres des BB, réordonnance les BB renommés, puis montre le nombre de cycles après renommage et ordonnacement ainsi que le gain obtenu 
5) test_all_together.cpp : programme qui permet de voir le nb de cycles des BB au départ, après schéduling, après renommage du bloc réordonnancé, apres reordonnancement du bloc renommé. Utile pour la toute fin du projet.


 ----- Pour visualiser un fichier fichier.dot ----

Générer un pdf avec la commande suivante :
dot -Tpdf -o fichier.pdf fichier.dot

Visualiser le pdf avec votre application préférée 

			

