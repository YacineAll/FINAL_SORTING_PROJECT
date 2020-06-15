#ifndef __LDC__
#define __LDC__

//declaration de la  structure de la cellule contenu dans la fille 
typedef struct celluleLDC {
  int i , j ;// coordonées de la 
 struct celluleLDC * prec ; /* pointeur sur l’element precedent de la liste */
 struct celluleLDC * suiv ; /* pointeur sur l’element suivant de la liste */
}CelluleLDC;


//declaration de la strcutre de fille LDC
typedef struct {
 CelluleLDC * premier ; /* Pointeur sur element en tete */
 CelluleLDC * dernier ; /* Pointeur sur element en fin */
}LDC;

/*
fonction prend en parametre deux entiers et alloue la memoire pour une cellule et initialise c'est coordonées a i j et la renvoie 
*/
CelluleLDC * creerCellule (int i , int j ) ; // qui alloue et retourne une cellule

/*
fionction qui prend une file LDC et initialise ses champs 
*/
void LDCInitialise ( LDC * ldc ) ; // qui initialise une liste

/*
fonction qui renvoie 1 si la file est vide 0 sinon 
*/
int  LDCVide ( LDC * ldc ) ; // qui teste si la liste est vide


/*
fonction qui prend en parametre une LDC et deux coordonées et ajouter a la fin de la file une cellule avec les coordonées passé en paramétre
*/
void LDCInsererEnFin (LDC *ldc , int i , int j ) ; //qui insere une nouvelle cellule en fin


/*
fonction qui prend en paramétre une file et une cellule et l'a suprimme de la file  
*/
void LDCenleverCellule ( LDC * ldc , CelluleLDC * cel ); // qui supprime une cellule a partir d un pointeur sur la cellule


/*
fonction qui prend en parametre une file LDC et affiche son contenue 
*/
void LDCafficher ( LDC * ldc ); // un affichage en cas de besoin pour debugage

/*
fonction qui prend en paramétre une file LDC et la supprime en desallouant toute la memoire dedié 
*/
void LDCdesalloue ( LDC *ldc ) ;// qui desalloue toute la liste (si elle n est pas vide a la fin)


/*
algorithme qui prend en parametre une file LDC et une grille , els coordonnées du robot et deux variable passé en parametre et renvoie la case non noir la plus proche du robot ou les coordonnées sont des les variable k l 
*/
void recherchePiece_NN (LDC *t,Grille *G,int i, int j,int *k,int *l);

/*
fonction qui prend en pramatre une grille et crée un tableau de file qui a comme taille le nombre de couleur et associe chaue a la fille correspondant à sa couleur de fond  et renoie un pointeur vers le tableau*/
LDC *TC(Grille *G);

/*
algorithme qui prend en parametre une liste et les  coordonées du robot et renvoie la cellule la plus proche qui a le meme couleur de fond que la couleur du robot 
*/
CelluleLDC* LDCrechercherPlusProcheCase(LDC* ldc, int i, int j);

/*
algorithme qui permet de resoudre le jeu en fesant appel aux differents fonctions de recherches .
*/
void algorithme_LDC(Grille *G, Solution *S);

#endif
