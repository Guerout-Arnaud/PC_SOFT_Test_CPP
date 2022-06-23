# PC_SOFT_Test_CPP

## Contexte
Pour ce test, j'ai décidé de faire le sujet conseillé: le sujet 1.

J'ai choisi d'utiliser g++ couplé à un Makefile pour la compilation, ces derniers étant utilisés dans la grande majorité de mes projets.

Pour ce qui est du debug ainsi que des fuites de mémoire, j'ai préféré utiliser valgrind.

J'ai développé et testé ce projet sous Manjaro 21.3.0. N'ayant pas beaucoup d'expérience en développement Windows et Make étant difficilement compatible, je n'ai pas eu l'occasion de tester sur cet environnement.

N'ayant pas le droit aux containers de la STL, ceci m'a mis un doute concernant le droit d'utiliser des smart pointers. N'étant pas certain que ces derniers soient autorisés j'ai préféré ne pas les utiliser. Cependant, j'ai ajouté un commentaire titré `Info` à l'endroit où leur utilisation aurait été nécessaire pour des questions de performance notamment.

Le dossier `lib` est un sous module git. Cette lib est[ma librairie personnelle](https://github.com/Guerout-Arnaud/C_Lib) avec quelques modifications pour fonctionner en C++. Malgré le fait que je n'ai pas utilisé d'avantages de fonctionnalités de `GIT`, ce projet a été créé dans le but de pouvoir être maintenu avec ce dernier.

La documentation peut être entirèrement générée via [Doxygen](https://doxygen.nl/). Depuis la racine du projet effectuer la commande `doxygen ./doc/Doxyfile`. N'ayant pas d'indication quant à la langue devant être utilisée pour les commentaires, la documentation a été rédigée en anglais afin d'être compréhensible par le plus grand nombre. Cela confirme également ma capacité à lire (et rédiger) de la documentation technique en anglais comme demandé dans l'offre de poste.

<br/>
<br/>

## **Sujet** (Sujet 1 effectué)
SUJET 1 (Sujet conseillé)
Sujet de test en C++
« Indexation de document texte »

Objectif
Ecrire un programme qui prend un chemin de répertoire sur la ligne de commande.
Ce programme doit alors parcourir ce répertoire ainsi que tous ses sous-répertoires pour rechercher tous les fichiers texte (extension .txt).
Pour chaque fichier texte rencontré, réaliser une indexation en mémoire des mots contenu dans ce fichier.
Une fois cette indexation terminée, le programme doit demander la saisie d’un mot et retourner la liste des fichiers contenant ce mot.
Le programme sera en C++ (compilateur au choix). Ne pas utiliser de librairie tierce (conteneurs de la STL, BOOST, etc.).
Le but étant de concevoir soi-même les structures de données.
Concevoir la structure pour une efficacité maximum, pour être évolutif et facilement maintenable.
Les sources doivent être commentés de manière efficace.
La durée totale de développement est de 1 journée. A réaliser seul, bien-sûr.

SUJET 2
Sujet de test en C++
« Analyse lexicale simplifiée »

Objectif
Ecrire quelques procédures en langage C++ pour analyser le contenu d'une phrase.
Les fonctionnalités demandées sont les suivantes:

1. Afficher la même phrase en inversant l'ordre des mots
      (ex: "développez 10 fois plus vite" * "vite plus fois 10 développez")
2. Afficher le nombre d'occurrence de chaque lettre (ex: d=1, e=3, é=1, v=2, l=2, o=2, etc...) trié sur les lettres
3. Afficher le nombre d'occurrence de chaque lettre, trié sur les occurrences

Règles à respecter :
1. Les phrases peuvent contenir de 0 à 1000 mots
2. Un mot est composé de 1 à 50 caractères
3. Le séparateur de mots est l'espace (ex: "l'ordre des mots" contient 3 mots)
4. Les sources doivent être commentés de manière efficace.
5. Le programme sera en C ou C++, en ligne de commande pour Windows ou Linux (compilateur au choix).
6. La partie affichage sera aussi dépouillée que possible, mais lisible.
7. Faire très simple mais très clair, fiable, évolutif et maintenable!


