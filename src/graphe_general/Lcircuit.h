#ifndef __LCIRCUIT_H__
#define __LCIRCUIT_H__
#include "ListeDC.h"
// Structure de liste doublement chainee
// contenant deux entiers i et j

typedef struct Cell_circuit{
  LDC *ldc; // Elements stockes dans la liste
  int jmin , jmax;
  struct Cell_circuit* prec; /* pointeur sur l'element precedent de la liste */
  struct Cell_circuit* suiv; /* pointeur sur l'element suivant de la liste */
} Cell_Circuit;

typedef struct {
  int nb_circuit;
  Cell_Circuit* premier;  /* Pointeur sur element en tete */
  Cell_Circuit* dernier;  /* Pointeur sur element en fin */
}Lcircuit;



/* Alloue et retourne une cellule */
Cell_Circuit* LC_creerCellule(LDC *ldc);

void Lcircuit_Initialise(Lcircuit *lc);

/* Test si liste vide */
int LCircuit_Vide(Lcircuit * lc);

void LC_InsererEnTete(Lcircuit * lc, LDC* ldc);

void LC_Inserer_En_Fin(Lcircuit* lc, LDC* ldc);

void LC_afficher(Lcircuit* lc);

void LC_desalloue(Lcircuit *lc);

void LC_Enlever_Circuit(Lcircuit* lc, Cell_Circuit* c);

void LC_Enlever_Circuit(Lcircuit *lc, Cell_Circuit* c);

void CalculJminJmax(Lcircuit* lc);

Cell_Circuit *cell_min_ciruit(Lcircuit *lc);


#endif
