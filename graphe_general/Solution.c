#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <unistd.h>
#include "Grille.h"
#include "Solution.h"


void PlusCourtChemin(Solution *S, int i, int j, int k, int l){
    if (j<l) {
        while(j < l){
            Ajout_action(S,'R');
            j++;
        }
    }else{
        while(j > l) {
            Ajout_action(S,'L');
            j--;
        }
    }
    if (i<k) {
        while(i < k) {
            Ajout_action(S,'D');
            i++;
        }
    }else{
        while(i > k) {
            Ajout_action(S,'U');
            i--;
        }
    }
}

void Solution_init(Solution *S){
    
    S->prem=NULL;
    S->dern=NULL;
    S->cptr_pas=0;
}

void Affiche(Solution *S){
    Cell_char *cour=S->prem;
    printf("Nombre de pas: %d\n",S->cptr_pas);
    printf("Section jouee: ");
    while (cour!=NULL){
        printf("%c ",cour->a);
        cour=cour->suiv;
    }
    printf("\n");
}

void Ajout_action(Solution *S, char a){
    Cell_char *nouv=(Cell_char*) malloc(sizeof(Cell_char));
    nouv->a=a;
    nouv->suiv=NULL;
    if (S->prem==NULL){  // Si Liste vide
        S->prem=nouv;
        S->dern=nouv;
    }
    else{
        S->dern->suiv=nouv;
        S->dern=nouv;
    }
    if (a!='S') S->cptr_pas++;
}

void Ecriture_Disque(int m, int n, int nbcoul, int graine, Solution *S){
    char filename[104];
    char inttochar[6];
    
    strcpy(filename,"Robot_");
    sprintf(inttochar,"%d",m);
    strcat(filename,inttochar);
    strcat(filename,"_");
    sprintf(inttochar,"%d",n);
    strcat(filename,inttochar);
    strcat(filename,"_");
    sprintf(inttochar,"%d",nbcoul);
    strcat(filename,inttochar);
    strcat(filename,"_");
    sprintf(inttochar,"%d",graine);
    strcat(filename,inttochar);
    strcat(filename,".sol");
    
    FILE *f=fopen(filename,"w");
    fprintf(f,"%d %d %d %d\n", m, n, nbcoul, graine);
    
    Cell_char *cour=S->prem;
    while (cour!=NULL){
        fprintf(f,"%c ",cour->a);
        cour=cour->suiv;
    }
    fprintf(f,"0\n");
    
    fclose(f);
}
void freeSolution(Solution *S){
    if (!S) {
        return;
    }
    while (S->prem) {
        Cell_char *suivant=S->prem->suiv;
        free(S->prem);
        S->prem=suivant;
    }
    free(S);
}
