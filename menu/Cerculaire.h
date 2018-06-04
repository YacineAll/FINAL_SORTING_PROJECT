#ifndef __CERCULAIRE__
#define __CERCULAIRE__
#include "Grille.h"

void algorithme_circulaire(Grille *G, Solution *S);
void RechercheCaseCirculaire_c(Grille *G,int c,int i,int j,int *K,int *L);
void RechercheCaseCirculaire_nn(Grille *G,int i,int j,int *K,int *L);


#endif
