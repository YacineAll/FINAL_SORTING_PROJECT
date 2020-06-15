#ifndef __AVL__
#define __AVL__

typedef struct Node {
  int j;
  int height;
  struct Node *left;
  struct Node *right;
}AVL;

typedef struct tab{
  AVL ***M;
}Tableau;

Tableau *initTab(Grille *G);
AVL* insert(AVL* Noeud, int j);
void updateHeight(AVL *root);
int getBalance(AVL *N);
AVL *rightRotate(AVL *x);
int max(int a, int b);
AVL *droitRotation(AVL *racine);
int height(AVL *N);
AVL* newNoeud(int j);
void PieceLaPlusProche(Tableau *t, Grille *G, int *i, int j, int *k);
void CaseLaPlusProche(Tableau *t, Grille *G, int c, int *i, int j, int *k);
int CaseLaPlusProcheInLigne(AVL *avl, int *dis, int j, int *k) ;
void preOrder(AVL *root);
void freeTree(AVL *root);
int isAVL(AVL *root);
void freeTab(Tableau *tab,int n,int nbcoul);
void algorithme_AVL(Grille *G, Solution *S);
AVL *getMin(AVL * root);
AVL *deleteNode(AVL * root, int j);
#endif
