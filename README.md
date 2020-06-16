# Sorting-Robot

## Introduction:

Le jeu dit du Sorting Robot, se compose d’une grille de jeu et d’un robot pouvant se d ́eplacer sur la grille de jeu. Chaque case posséde une couleur de fond et peut comporter  une  piéce  colorée.  Le  but  du  jeu  consiste  à  déplacer  le  robot  de  sorte  que  chaque  piéce  soit rangée sur une case de meme couleur. A chaque fois qu’une pièce est ameée sur une case de méme couleur, la case devient noire. Le but est donc d’obtenir un écran noir.

- *Grille de jeu*

Le jeu se d ́eroule sur une grille de *m* lignes et *n* colonnes (potentiellement, *m* peut valoir 1 et la grille est alors une seule ligne de *n* colonnes). Dans tout le jeu, le noir correspond à une absence de couleur. Sur l’exemple ci-dessous, une grille de 3 lignes et 4 colonnes contient donc 12 cases. Chaque case peut contenir 0 ou 1 piéce. Une case posséde une couleur de fond et peut posséder une piéce représentée par un rectangle au milieu de la case. Une pièce possède une couleur. Si une case ne comporte pas de piéce, elle comporte alors un rectangle noir.

Les lignes sont numérotées de 0 à *m* - 1  et les colonnes de 0 à *n* - 1. Dans l’exemple, la case (1,0) est de fond bleu fonc ́e et contient une piece (rectangulaire) de couleur bleu-ciel. La piece bleu ciel doit aller en case (0,1) 1) qui contient elle une piece mauve qui doit aller en case (0,4),... La case (2,2) est noire car elle est de mˆeme couleur que la piece qu’elle contient : il n’y a donc rien à faire pour cette case.

- *Actions du robot*

Le robot est au depart en case (0,0) : il est represente par un petit rectangle colore qui est entouré de blanc. Au départ, le robot ne porte pas de piéce et le robot est alors noir. S’il porte une piéce de couleur *c* , il devient un rectangle de couleur *c* entouré de blanc. 

Un robot peut effectuer les actions suivantes :
  
  1. *Faire un pas à gauch* 'L', à droite 'R', en haut 'U' ou en bas 'D': pour passer à une case à gauche, à droite, au-dessus ou au-dessous (sans sortir de la grille) 
  
  2. *Faire un èchange* (ou swap, en anglais) 'S' : cette action a plusieurs configurations :
    
    1. Si le robot est sans pièce et qu’il est sur une case avec une pièce : il prend alors la pièce.
    
    2. Si le robot porte pièce et qu’il est sur une case sans pièce : il dèpose alors sa pièce; le robot a une pièce et il est sur une case avec pièce : il èchange sa pièce avec celle de la case.
    
    3. Si un robot est sans pièce sur une case sans pièce ou sur une case noire, il ne se passe rien.
