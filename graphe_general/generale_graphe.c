#include <stdlib.h>
#include<time.h>
#include<stdio.h>
#include"Graphe.h"
#include"Lcircuit.h"

int main(int argc, char ** argv)
{
  
  if (argc!=5 || atoi(argv[3]) > (atoi(argv[1])*atoi(argv[2]) )  )
    {
      fprintf(stderr, "%s\n","ERREUR");
      return EXIT_FAILURE;
    }
  
  //Creation de la liste de Solution
  Solution *S= (Solution *)malloc(sizeof(Solution));
  Solution_init(S);
  
  //Creation de la grille
  Grille *G = (Grille *)malloc(sizeof(Grille));
  G->m=atoi(argv[1]);
  G->n=atoi(argv[2]);
  G->nbcoul=atoi(argv[3]);
  Grille_allocation(G);
  Gene_Grille(G,atoi(argv[4]));
  
  double  temps;
  clock_t t1, t2;

  t1 = clock();
  algo_general_graph(G,S);
  t2 = clock();

  temps = (double)(t2-t1)/CLOCKS_PER_SEC;

  printf("\n\t temps=%fs\n",temps);

  printf("\n\t nombre de pas: %d\n",S->cptr_pas);
  Ecriture_Disque(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]),S);

  //Liberer la memoir de la grille
  freeGrille(G);
  
  //liberer la memoir de la liste de solution
  freeSolution(S);
  
  return EXIT_SUCCESS;
}
