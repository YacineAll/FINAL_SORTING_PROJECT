#ifndef __LISTE_CIRCUIT__
#define __LISTE_CIRCUIT__

#include <stdio.h>
#include <stdlib.h>
#include "ListeDC.h"

typedef struct cell_circuit {
  LDC *L;
  int jmin, jmax;
  struct cell_circuit *suiv;
} Cell_circuit;

typedef struct {
  int nb_circuit;
  Cell_circuit *premier;
  Cell_circuit *dernier;
} Lcircuit;

Cell_circuit *LCCreerCellule(LDC *L, int jmin, int jmax);
void LCInitialise(Lcircuit *lc);
int LCvide(Lcircuit *lc);
void LCInsererEnTete(Lcircuit* lc, LDC *L, int jmin, int jmax);
void LCInsererEnFin(Lcircuit *lc, LDC *L, int jmin, int jmax);
void LCEnleverCellule(Lcircuit *lc, Cell_circuit *cel);
void LCDesalloue(Lcircuit *lc);
void LCAfficher(Lcircuit *lc);
#endif