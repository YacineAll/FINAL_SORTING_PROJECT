#ifndef __Grille__
#define __Grille__
#include "Solution.h"


// Type struct d une case d une grille
typedef struct
{
  
  int fond;   // Entier couleur de 0 a nbcoul-1
  
  int piece;  // Entier couleur de 0 a nbcoul-1 si piece presente
              // -1 si pas de piece
  
  int robot;  // -2 si pas de robot sur cette case
              // -1 si robot present mais sans piece
              // Entier couleur de 0 a nbcoul-1 si robot present avec piece
} CCase;


typedef struct
{
  // Un couple (i,j) donne des coordonnees ieme ligne, jeme colonne
  
  int m;          // Nb de lignes
  
  int n;          // Nb de colonnes
  
  int nbcoul;     // Nb de couleurs
  
  CCase ** T;     // Tableau a deux dimensions de la grille
  
  int ir, jr;     // Coordonnee du robot sur une case (dite case courante)
  
  int cptr_noire; // Compteur de cases noires
  
} Grille;

int distanceEtreDeuxPoint(int x1,int y1,int x2,int y2);

void algorithme_naif(Grille *G, Solution *S);
void RechercheCaseNaif(Grille *G, int c, int i, int j, int *k, int *l);
void RecherchePieceNaif(Grille *G,int i,int j,int *k,int *l);

void algorithme_circulaire(Grille *G, Solution *S);
void RechercheCaseCirculaire_c(Grille *G,int c,int i,int j,int *K,int *L);
void RechercheCaseCirculaire_nn(Grille *G,int i,int j,int *K,int *L);

void Grille_allocation(Grille *G);
void Gene_Grille(Grille *G, int graine);
void changement_case(Grille *G, int i, int j);
void swap_case(Grille *G);
void AfficheGrille(Grille *G);
void freeGrille(Grille *G);
int est_noir(CCase c);
int is_black(CCase c);
int robot_with_piece(CCase c);
int coleur_of_robot (CCase c);



#endif
