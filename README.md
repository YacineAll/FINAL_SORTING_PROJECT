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
    
    
Il est important de noter que le robot choisit librement d’effectuer l’une ou l’autre des actions : en particulier, rien ne l’oblige à dèposer une pièce sur une case de mème couleur (mème si c’est à terme son objectif final).

Le but du jeu est de dèplacer le robot et d’effectuer des èchanges de manière à ce que toutes les piéces soient placèes sur une case de mème couleur. La case devient alors noire : à la fin du jeu, la grille entière doit donc ètre noire. L’objectif pour gagner est en plus de rèaliser cela avec un nombre de pas le plus petit possible (le nombre d’échanges n’est pas pris en compte).

Une séquence d’actions du robot peut donc s’écrire comme une suite de lettres parmi L, R, U, D et S. Par exemple, la grille ci-dessous est obtenue à partir de la grille initiale plus haut par la séquence d’actions (’D’, ’S’, ’R’, ’U’, ’S’, ’R’, ’R’,’S’). A l’issue de cette séquence, la case (1,0) n’a plus de pièce, les cases (0,1) et (0,4) sont devenues noires. Le robot est à présent sur la case (0,4) et porte une pièce rouge.

- *Instances de grille*
  
  On distingue deux types d’instances de grille :
  - les instances ou il y a plusieurs cases par méme couleur.
  - les instances ou il y a une seule case par couleur.
 
Dans le cas de la grille ci-dessus, le robot a par exemple la possibilité de choisir d’aller déposer sa pièce rouge en case (0,0) ou en case (2,4) (notez qu’il peut aussi choisir de dèposer sa pièce ailleurs temporairement).

- *Mais alors quand est-ce qu’on gagne ?*
Si le jeu se limitait à dèterminer une sèquence d’actions qui mènent à une grille toute noire, le jeu serait trés facile. L’objectif est d’utiliser un nombre minimal de pas. Mais dans ce cas, comment peut-on savoir si on a mal ou bien joué ?
