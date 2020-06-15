#ifndef __SOLUTION__
#define __SOLUTION__

typedef struct cell_char{  
  char a;
  struct cell_char *suiv;
} Cell_char;


// Liste simplement chainee
// avec insertion en fin de liste en O(1)
typedef struct{
    
    int cptr_pas;   // Compteur des cases parcourues
    
    Cell_char * prem; // Liste des actions
    Cell_char * dern;  // Pointeur sur dernier element
    
} Solution;

void Solution_init(Solution *S);
void Ajout_action(Solution *S, char a);
void Affiche(Solution *S);
void PlusCourtChemin(Solution *S, int i, int j, int k, int l);
void freeSolution(Solution *S);
void Ecriture_Disque(int m, int n, int nbcoul, int graine, Solution *S);           

#endif
