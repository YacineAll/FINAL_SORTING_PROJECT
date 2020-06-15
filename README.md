# Sorting-Robot

## Introduction:

Le jeu dit du Sorting Robot, se compose d’une grille de jeu et d’un robot pouvant se d ́eplacer sur la grille de jeu. Chaque case posséde une couleur de fond et peut comporter  une  piéce  colorée.  Le  but  du  jeu  consiste  à  déplacer  le  robot  de  sorte  que  chaque  piéce  soit rangée sur une case de meme couleur. A chaque fois qu’une pièce est ameée sur une case de méme couleur, la case devient noire. Le but est donc d’obtenir un écran noir.

* *Grille de jeu*

Le jeu se d ́eroule sur une grille de *m* lignes et *n* colonnes (potentiellement, *m* peut valoir 1 et la grille est alors une seule ligne de *n* colonnes). Dans tout le jeu, le noir correspond à une absence de couleur. Sur l’exemple ci-dessous, une grille de 3 lignes et 4 colonnes contient donc 12 cases. Chaque case peut contenir 0 ou 1 piéce. Une case posséde une couleur de fond et peut posséder une piéce représentée par un rectangle au milieu de la case. Une pi`ece poss`ede une couleur. Si une case ne comporte pas de piéce, elle comporte alors un rectangle noir.

Les lignes sont numérotées de 0 à *m* - 1  et les colonnes de 0 à *n* - 1. Dans l’exemple, la case (1,0) est de fond bleu fonc ́e et contient une piece (rectangulaire) de couleur bleu-ciel. La piece bleu ciel doit aller en case (0,1) 1) qui contient elle une piece mauve qui doit aller en case (0,4),... La case (2,2) est noire car elle est de mˆeme couleur que la piece qu’elle contient : il n’y a donc rien à faire pour cette case.

* *Actions du robot*
