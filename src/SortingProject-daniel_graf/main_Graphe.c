#include "Grille.h"
#include "Graphe.h"
#include "stdio.h"
#include "stdlib.h"


int main(int argc, char** argv){
    
    if (argc < 5){
        printf("nombre d'arguments insuffisant ! Format : <m> <n> <nbcoul> <graine>\n");
        return 1;
    }

    Grille G;
    Graphe H;
    Solution S;
    Solution_init(&S);
    int graine;

    G.m=atoi(argv[1]);
    G.n = atoi(argv[2]);
    G.nbcoul = atoi(argv[3]);
    graine = atoi(argv[4]);

    Grille_allocation(&G);  
    Gene_Grille(&G,graine);
    algorithme_circuit_CasLigne1x1(&G , &S);
    printf("nombre de pas est: %d\n",S.cptr_pas);
    Ecriture_Disque(G.m , G.n , G.nbcoul , graine , &S);
    
    return 0;
}
