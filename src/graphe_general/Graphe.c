#include<stdlib.h>
#include"Graphe.h"
#include<stdio.h>


void Graphe_init(Graphe *H, int m, int n){
  int i,j;
  
  H->m=m;
  H->n=n;
  H->Tsom=(Sommet***)malloc(m*sizeof(Sommet**));
  for (i=0;i<m;i++){
    H->Tsom[i]=(Sommet**)malloc(n*sizeof(Sommet*));
    for (j=0;j<n;j++)
      H->Tsom[i][j]=(Sommet*)malloc(sizeof(Sommet));
  }

  for (i=0;i<m;i++)
    for (j=0;j<n;j++){
      H->Tsom[i][j]->i=i;
      H->Tsom[i][j]->j=j;
      H->Tsom[i][j]->Lsucc=NULL;
      H->Tsom[i][j]->visit=-1;
    }
  
  
}

void Graphe_ajout_arc(Graphe *H, int i1, int j1, int i2, int j2){
  Arc *a=(Arc*) malloc(sizeof(Arc));
  a->succ=H->Tsom[i2][j2];
  a->suiv=H->Tsom[i1][j1]->Lsucc;
  H->Tsom[i1][j1]->Lsucc=a;  
}


void Graphe_creation(Grille *G, Graphe *H){
  
  int i,j,k;
  CelluleLDC *cour1,*cour2;
  
  Graphe_init(H,G->m,G->n);
  
  LDC* TC=(LDC*) malloc(sizeof(LDC)*G->nbcoul);
  
  for (i=0;i<G->m;i++)
    for (j=0;j<G->n;j++)
      if (G->T[i][j].fond!=G->T[i][j].piece)
	LDCInsererEnTete(&TC[G->T[i][j].fond],i,j);
  
  for (k=0;k<G->nbcoul;k++){
    cour1=TC[k].premier;
    while(cour1!=NULL){
      cour2=TC[G->T[cour1->i][cour1->j].piece].premier;
      while (cour2!=NULL){
	Graphe_ajout_arc(H,cour1->i,cour1->j,cour2->i,cour2->j);
	cour2=cour2->suiv;
      }      
      cour1=cour1->suiv;
    }
  }
  
  for (k=0;k<G->nbcoul;k++)
    LDCdesalloue(&(TC[k]));
  
}


void Graphe_affiche(Graphe *H){
  int i,j;
  Arc *cour;
  
  printf("Graphe H :\n");
  for (i=0;i<H->m;i++)
    for (j=0;j<H->n;j++){
      printf("(%d,%d) ",i,j);
      if (H->Tsom[i][j]->Lsucc==NULL)
	printf(" noir\n");
      else{
	printf(" arc vers ");
	cour=H->Tsom[i][j]->Lsucc;
	while (cour!=NULL){
	  printf("(%d,%d) ", cour->succ->i, cour->succ->j);
	  cour=cour->suiv;
	}
	printf("\n");
      }
      
    }
  
}

Lcircuit *Rech_Circuit(Graphe *H){
  Lcircuit *lc =(Lcircuit *) malloc(sizeof(Lcircuit));
  Lcircuit_Initialise(lc);
  for(int i=0;i<H->m;i++)
    for(int j=0;j<H->n;j++){
      if(H->Tsom[i][j]->visit==-1){
	LDC *ldc = (LDC *) malloc (sizeof(LDC));
	LDCInitialise(ldc);
	if(detect_circuits(H->Tsom[i][j],i,j,ldc)){
	  LC_Inserer_En_Fin(lc,ldc);
	}
      }
    }
  return lc;
}

int detect_circuits (Sommet *s,int i,int j,LDC* ldc){
  Arc *cour = s->Lsucc;
  s->visit=0;
  while(cour){
    Sommet *next =plus_proche(s);
    if(!next)
      next=cour->succ;
    if(next->visit==-1){
      LDCInsererEnFin(ldc, next->i,next->j);
      if(detect_circuits(next,i,j,ldc)){
	return 1;
      }
    }else{
      
      if (next->visit==0 && i==next->i && j==next->j){
	LDCInsererEnTete(ldc, next->i,next->j);
	LDCInsererEnFin(ldc,next->i,next->j);
	return 1;
      }
    }
    cour=cour->suiv;
  }
  s->visit=1;
  return 0;
}

Sommet *plus_proche(Sommet *s){
  Arc *tmp=s->Lsucc;
  int distance = 500;

  Sommet *som=tmp->succ;
  Arc *par=tmp;
  int bol=0;

  while (par){
    int dis= distanceEtreDeuxPoint(s->i,s->j,par->succ->i,par->succ->j);
    if(dis <= distance && par->succ->visit==-1){
      if(dis == distance && ( par->succ->j >  s->j)){
	som=som;
      }else
	{
	  distance = dis;
	  som=par->succ;
	}
      bol=1;
    }
    par=par->suiv;
  }
  if(!bol){
    return NULL;
  }
  return som;
}

void algo_general_graph(Grille *G,Solution *s){

  Graphe *H;
  H=(Graphe *)malloc(sizeof(Graphe));
  Graphe_creation(G,H);

  Lcircuit *lc = Rech_Circuit(H);
  CalculJminJmax(lc);

  Cell_Circuit *cour=lc->premier;
  while(cour!=NULL){
    parcour_ldc(G,cour->ldc,s);
    cour=cour->suiv;
  } 
}


void parcour_ldc(Grille *G,LDC *ldc,Solution *S){
  CelluleLDC* cour= ldc->premier;
  int k,l;
  
  while (cour!=NULL)
    {
      swap_case(G);
      k=cour->i;
      l=cour->j;
      PlusCourtChemin(S,G->ir, G->jr, k, l);
      Ajout_action(S, 'S');
      changement_case(G, k, l);
      cour=cour->suiv;
    }
}
