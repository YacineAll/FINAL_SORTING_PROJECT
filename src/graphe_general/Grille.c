#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<math.h>
#include"Solution.h"
#include"Grille.h"



//le nombre de pas entre deux cases
int distanceEtreDeuxPoint(int x1,int y1,int x2,int y2){
  return abs(x2 - x1)+abs(y2 - y1);
}
//return true si la case es noir
int est_noir(CCase c){
  return c.fond == c.piece;
}
//return true si la piece est noir
int is_black(CCase c){
  return c.piece == -1;
}
//return true si la robot est avec une piece NON NOIR
int robot_with_piece(CCase c){
  return c.robot != -1;
}
//return la couleur de la piece de Robot
int coleur_of_robot (CCase c){
  return c.robot;
}
//Allocation de la grille
void Grille_allocation(Grille *G){
  int i;
  
  G->T=(CCase **) malloc(sizeof(CCase*)*G->m);
  for (i=0;i<G->m;i++){
    G->T[i]=(CCase *) malloc(sizeof(CCase)*G->n);
  }
}
//Generer une Grille
void Gene_Grille(Grille *G,int graine){
  int i,j,k,ip,jp,tmp,l,r,rr,alpha;
  
  srand(graine);
  
  // Affecte au moins 1 case par couleur
  k=0;
  i=0; j=0;
  while (k<G->nbcoul){
    G->T[i][j].fond=k;  // remplit le fond et la piece de meme couleur
    G->T[i][j].piece=k;
    j++;
    if (j==G->n){
      i++;
      j=0;
    }
    k++;
  }
  // Complete le reste de la grille avec des couleurs en quantite
  // aleatoire (mais selon un principe algorithmique)
  alpha=(G->m*G->n)/(G->nbcoul*1.0);
  l=0;
  while (k<G->m*G->n){
    r=1+rand()%(2*alpha);
    rr=0;
    while ((k<G->m*G->n)&&(rr<r)){
      G->T[i][j].fond=l;
      G->T[i][j].piece=l;
      j++;
      if (j==G->n){
	i++;
	j=0;
      }
      k++;
      rr++;
    }
    l++;
    if (l==G->nbcoul) l=0;
  }
  
  
  // Permute aleatoirement les pieces sur la grille
  for (i=0;i<G->m;i++)
    for (j=0;j<G->n;j++){
      ip=rand()%G->m;
      jp=rand()%G->n;
      tmp=G->T[i][j].piece;
      G->T[i][j].piece=G->T[ip][jp].piece;
      G->T[ip][jp].piece=tmp;
    }
  
  
  // Comptabilise combien de piece sont sur une case de meme couleur
  // au depart
  G->cptr_noire=0;
  for (i=0;i<G->m;i++)
    for (j=0;j<G->n;j++)
      if (G->T[i][j].piece==G->T[i][j].fond)
	G->cptr_noire++;
  
  // Place le robot en case 0,0
  for (i=0;i<G->m;i++)
    for (j=0;j<G->n;j++)
      G->T[i][j].robot=-2;
  G->T[0][0].robot=-1;
  
  G->ir=0;
  G->jr=0;
  
  
}
//Change les coordonne de robot vers la case Donne en argument
void changement_case(Grille *G, int i, int j){
  int tmp=G->T[G->ir][G->jr].robot;
  G->T[G->ir][G->jr].robot=-2;
  G->ir=i;
  G->jr=j;
  G->T[G->ir][G->jr].robot=tmp;
}
//changer la piece de robot avec la piece de la case et la mettre en noir si la case et la piece
//sont de la meme coleur
void swap_case(Grille *G){
  
  if (G->T[G->ir][G->jr].fond!=G->T[G->ir][G->jr].piece){
    int tmp=G->T[G->ir][G->jr].robot;
    G->T[G->ir][G->jr].robot=G->T[G->ir][G->jr].piece;
    G->T[G->ir][G->jr].piece=tmp;
    if (G->T[G->ir][G->jr].fond==G->T[G->ir][G->jr].piece)
      G->cptr_noire++;
  }
  
}
//afficher la grille dans la grille console "JUSTE POUR DEBUGUER"
void AfficheGrille(Grille *G){
  if (!G) {
    fprintf(stderr, "%s\n","La Grille est en NULL");
    return;
  }
  for (int i = 0; i < G->m; i++) {
    for (int j = 0; j < G->n; j++) {
      if (est_noir(G->T[i][j]))
        printf("%d  ",-1);
      else
        printf(" %d  ",G->T[i][j].fond);
    }
    printf("\n");
  }
}
//librer l espace memoire de la grille 
void freeGrille(Grille *G){
  int i=0;
  if (G) {
    for (i=0;i<G->m;i++){
      free(G->T[i]);
    }
    free(G->T);
    free(G);
  }
}
