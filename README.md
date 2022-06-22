# PC_SOFT_Test_CPP

## Contexte
Pour ce test, j'ai choisi de faire le suject conseille: le sujet 1.

La documentation peut etre entirerement generee via Doxygene. Depuis la racine du projet effectuer la commande `doxygen ./doc/Doxyfile`. N'ayany pas d'indication quant a la langue des commentaires, la documentation a ete rediger en anglais afin d'etre comprehensible par le plus grand nombre. Cela confirme egalement ma capaciter a lire (et rediger) de la documentation technique en anglais comme demande dans l'offre de poste.

Le dossier `lib` est un sous module git. Cette lib est ma librairie personelle avec quelques modifications pour fonctionner en C++. Malgre le fait que je n'ai pas utilise d'avantages de fonctionnalites de git, ce projet a ete creer dans le but de pouvoir etre maintenu avec ce dernier.

N'ayant pas le droit aux containers de la STL, ceci m'a mis un doute concernant l'utilisation des smart pointer. N'etant pas certain que ces derniers soient autorises j'ai prefere ne pas les utiliser. Cependant j'ai ajouter un commentaire titre `Info` a l'endroit ou leur utilisation aurait ete necessaire pour des questions de performance notamment.

J'ai choisis d'utiliser g++ couple a un Makefile pour la compilation, ces derniers etant utilises dans la grande majorites de mes projets.

Pour ce qui est du debug ainsi que des memory leak, j'ai prefere utiliser valgrind.

J'ai developpe et teste ce projet sur une machine Manjaro 21.3.0
N'ayant pas beaucoup d'experience en developpement Windows et Make etant difficilement compatible, je n'ai pas eu l'occasion de tester sur cet environnement.
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


