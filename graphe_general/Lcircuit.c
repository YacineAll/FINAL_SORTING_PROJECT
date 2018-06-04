#include<stdlib.h>
#include<stdio.h>
#include"Lcircuit.h"

Cell_Circuit* LC_creerCellule(LDC *ldc){
  Cell_Circuit* e =(Cell_Circuit *)malloc(sizeof (Cell_Circuit));
  e->prec=NULL;
  e->suiv=NULL;
  calculJminJmax(ldc,&e->jmin,&e->jmax);
  e->ldc=ldc;
  return e;
}

void Lcircuit_Initialise(Lcircuit *lc){
  lc->premier=NULL;
  lc->dernier=NULL;
  lc->nb_circuit=0;
}

int LCircuit_Vide(Lcircuit* lc){
  return (lc->premier==NULL);
}

void LC_InsererEnTete(Lcircuit * lc, LDC* ldc){
  Cell_Circuit * nouv=LC_creerCellule(ldc);
  nouv->prec=NULL;
  if (LCircuit_Vide(lc)) 
    lc->dernier=nouv;
  else 
    lc->premier->prec=nouv;
  nouv->suiv=lc->premier;
  lc->premier=nouv;
}


void LC_Inserer_En_Fin(Lcircuit* lc, LDC *ldc){
  Cell_Circuit* nouv=LC_creerCellule(ldc);
  nouv->prec=lc->dernier;
  if (LCircuit_Vide(lc)) 
    lc->premier=nouv;
  else 
    lc->dernier->suiv=nouv;
  nouv->suiv=NULL;
  lc->dernier=nouv;
}
void CalculJminJmax(Lcircuit* lc){
  if(!lc || LCircuit_Vide(lc) ){
    return ;
  }
  
  Lcircuit* newLc=(Lcircuit *)malloc (sizeof(Lcircuit));
  Lcircuit_Initialise(newLc);
  
  while(!LCircuit_Vide(lc)){
    LC_Inserer_En_Fin(newLc,cell_min_ciruit(lc)->ldc);
  }
  *lc=*newLc;
}

Cell_Circuit *cell_min_ciruit(Lcircuit *lc){

  Cell_Circuit* cour=lc->premier;
  Cell_Circuit* min=lc->premier;

  while(!cour){
    if(cour->jmin < min->jmin){
      min=cour;
    }
    cour=cour->suiv;
  }

  LC_Enlever_Circuit(lc, min);
  return min;
}


void LC_afficher(Lcircuit * lc){
  printf("Circuits : \n");
  Cell_Circuit* cour= lc->premier;
  while(cour != NULL) {
    printf("(jmin=%d,jmax=%d)  ;",cour->jmin,cour->jmax);
    LDCafficher(cour->ldc);
    cour=cour->suiv;
  }
  printf("\n");
}



void LC_Enlever_Cell(Lcircuit* lc, Cell_Circuit* c){
  Cell_Circuit* precC=c->prec;
  Cell_Circuit* suivC=c->suiv;
  if (precC==NULL) 
    lc->premier=suivC;
  else 
    precC->suiv=suivC;
  if (suivC==NULL) 
    lc->dernier=precC;
  else 
    suivC->prec=precC;
}




void LC_desalloue(Lcircuit *lc){
  Cell_Circuit* cour= lc->premier;
  while(cour != NULL) {
    Cell_Circuit *suiv =cour->suiv;;
    LDCdesalloue(cour->ldc);
    free(cour);
    cour=suiv;
  }
  free(lc);
}

void LC_Enlever_Circuit(Lcircuit *lc, Cell_Circuit* c){

  Cell_Circuit* precC=c->prec;
  Cell_Circuit* suivC=c->suiv;

  if (precC==NULL) 
    lc->premier=suivC;
  else 
    precC->suiv=suivC;

  if (suivC==NULL) 
    lc->dernier=precC;
  else 
    suivC->prec=precC;
}
