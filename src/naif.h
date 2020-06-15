#ifndef __NAIF__
#define __NAIF__
#include "Grille.h"


/*
algorithme naif qui trouvé la solution du jeu en fessant appel aux differentes fonctions de recherches des cases non noirs , et en fesant bouger le robot vers les differents cases de la grille.

*/
void algorithme_naif(Grille *G, Solution *S);

/*

algorithme qui prend en paramétre la grille une couleur, les coordonées de la case et deux coordonnées passé en parametre et renvoie la case la plus proche du robot qui a le meme fond  que la piéce du robot 
*/
void RechercheCaseNaif(Grille *G, int c, int i, int j, int *k, int *l);

/*
algorithme qui prend en paramétre la grille,les coordonnées de la case du robot et deux varibale passées par pointeurs et enregistre dedant les coordonnées de la piéce la plus proche non noir du robot 
*/
void RecherchePieceNaif(Grille *G,int i,int j,int *k,int *l);


#endif
