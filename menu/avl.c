#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Solution.h"
#include"Grille.h"
#include"avl.h"
#include"math.h"

// retourne le maximum entre deux entier 
int max(int a, int b)
{
  return (a > b) ? a : b;
}


// mise a jour des heuteurs 
void updateHeight(AVL *root)
{
  if (!root)
    {
      return;
    }
  
  root->height = max(height(root->left), height(root->right)) + 1;
}

//retourne la balance qui est la difference entre la hauteur du fils gauche et fils droit
int getBalance(AVL *N)
{
  if (!N)
    return 0;
  return height(N->left) - height(N->right);
}

//retourn la hauteur d'un noeud 
int height(AVL *N)
{
  if (!N)
    return -1;
  return N->height;
}

//Rotation a droit
AVL *rightRotate(AVL *root)
{
  
  //pointeur vers le fils gauche de la racine
  AVL *newRoot = root->left;
  
  //pointeur vers le fils droit du fils gauche de la racine 
  AVL *right = newRoot->right;
  
  
  
  root->left = right;
  newRoot->right = root;
  
  // mise  à jour des hauteurs 
  updateHeight(root);
  updateHeight(newRoot);
  
  // Retourne la nouvelle racine de l'avl apres rotation droite 
  return newRoot;
}

//Rotation a gauche
AVL *leftRotate(AVL *root)
{
  //pointeur vers le fils droit de la racine 
  AVL *newRoot = root->right;
  
  //pointeur vers fils gauche du fils droit de la racine 
  AVL *left = newRoot->left;
  
  // rotation droite 
  root->right = left;
  newRoot->left = root;
  
  // mise a jour des hauteur 
  updateHeight(root);
  updateHeight(newRoot);
  
  // Retourner la nouvekke racine de l'avl apres la rotation droite
  return newRoot;
}

//Verfie a ce que il est equilibre
int isAVL(AVL *root)
{
  if (!root)
    {
      return 1;
    }
  return abs(getBalance(root)) < 2 && isAVL(root->right) && isAVL(root->left);
}

//creation et initialisation d'un noeud 
AVL* newNode(int j)
{
  
  // allocation dynamique du noeud 
  AVL* Node = (AVL*) malloc(sizeof(AVL));
  
  //initialisaton  des attributs du noeud 
  Node->j = j;
  Node->height = 0;
  Node->left = NULL;
  Node->right = NULL;
  
  // retourner le noeud 
  return (Node);
}

//Insert in the AVL and equilibre
AVL* insert(AVL* root, int j)
{
  
  //verification si l'arbre est vide et retourner un noeud 
  if (root == NULL)
    return (newNode(j));
  
  //insertion a droite
  if (j < root->j)
    root->left = insert(root->left, j);
  else
    
    //ajouter a gaucher de l'arbre 
    if (j > root->j)
      root->right = insert(root->right, j);
    else
      return root;

  //metre a jour la hauteur de l'arbre
  updateHeight(root);

  //recupérer la balance de la racine
  int balance = getBalance(root);

  if(balance == 2)
    {
      // si la balance du fils gauche est negative
      if(getBalance(root->left)<0)
	{

	  //rotation gauche
	  root->left=leftRotate(root->left);
	}
      //dans tout autre cas rotation droite
      root=rightRotate(root);
    }else
    {
      //si la balance = -2
      if(balance == -2)
	{

	  //si la balance du fils droit et positive
	  if(getBalance(root->right)>0)
	    {

	      //rotation droite du fils droit de la racine
	      root->right=rightRotate(root->right);

	    }

	  //rotation gauche de la racine
	  root=leftRotate(root);
	}
    }

  //retourne la nouvelle racine
  return root;
}


//parcour prefixé du l'arbre
void preOrder(AVL *root)
{
  if (!root)
    return;
  
  printf("%d ", root->j);
  preOrder(root->left);
  preOrder(root->right);
  
}


// parcour infix de l'arbre 
void Infix(AVL *root)
{
  if (!root)
    return;
  
  
  Infix(root->left);
  printf("%d ", root->j);
  Infix(root->right);
}


//supprimé l'arbre en liberant la memoire
void freeTree(AVL *root)
{
  
  if (root)
    {
      freeTree(root->right);
      freeTree(root->left);
      free(root);
    }
}


//fonction qui retourne le minimum d'un arbre 
AVL *getMin(AVL * root)
{
  
  if (root==NULL)
    {
      return NULL;
    }
  
  
  AVL *tmp = root;
  
  //parcourir l'abre a gauche jusqu'a la premiére feuille 
  while (tmp->left)
    {
      tmp = tmp->left;
    }
  
  //retourner le minimum 
  return tmp;
}


//suprimer le noeud de l'arbre étiqueté par J
AVL *deleteNode(AVL * root, int j)
{
  //verfication si la racine n'est pas à NULL
  if (root == NULL)
    return root;
  
  //si j inferieur à l'etiquette de la racine on cherche à gauche
  if (j < root->j)
    root->left = deleteNode(root->left, j);
  
  //si non  si  superieur  à l'etiquette de la racine on cherche à droite
  else
    
    if (j > root->j)
      root->right = deleteNode(root->right, j);
  
  //Si non on la trouvé
    else
      {
	//Si le neoud a un seul sous arbre
	if ((root->left == NULL) || (root->right == NULL))
	  {
	    //on stock l'adresse de l'un de ses deux sous arbre droit 
	    AVL *temp = root->left ? root->left : root->right;
	    
	    //Si temp est null c'est à dire que les deux sous arbre droit sont à NULL ==> c'est une feuille
	    if (temp == NULL)
	      {
		//on stock le Neoud dans temp
		temp= root;
		//on mis le noeud a NULL
		root = NULL;
	      }
	    
	    //Si non le Noeud a juste un seul sous arbre
	    else
	      //on mis dans le noeud le contenu de son sous arbre qui n'est pas à NULL
	      *root = *temp;
	    
	    //On libere la mimoire de Noeud 
	    free(temp);
	  }
	
	//Si non le noeud a deux sous arbre
	else
	  {
	    //on cherche le min de sous arbre droit 
	    AVL* min = getMin(root->right);
	    
	    //On remplace l'etiquette de in trouve avec l'etiquette de noued que On veut supprimer
	    root->j=min->j;
	    
	    //on supprime le min trouvée
	    root->right = deleteNode(root->right, min->j);
	  }
      }
  
  //Si root est NULL c'est à dire c'est était une feuille on renvoie  directement le Noeud 
  if (root == NULL)
    return root;
  
  //on mis a jour la hauteur du Noeud
  updateHeight(root);
  
  //la deffirence entre la heuteur de sous arbre gauche et celle de sous arbre droit
  int balance = getBalance(root);
  
  //Si la balance == 2  c'est a dire l'arbre est degenre à gauche
  if(balance == 2)
    {
      //Si la balance de sous arbre gauche inferieur à 0
      if(getBalance(root->left)<0)
	
	{
	  //on fait une Rotation gauche pour le sous arbre gauche de la racine 
	  root->left=leftRotate(root->left);
	}
      
      //On fais une rotation droite
      root=rightRotate(root);
    }
  
  //Si non
  else
    {
      //Si la balance == -2 c'est a dire l'arbre est degenre a droite
      if(balance == -2)
	{
	  //Si la balance de sous arbre droit >0
	  if(getBalance(root->right)>0)
	    {
	      //Rotation a droite pour le sous arbre droit 
	      root->right=rightRotate(root->right);
	    }
	  //rotation gauche pour la racine
	  root=leftRotate(root);
	}
    }
  
  //on return la nouvelle racine
  return root;
}


//initialisation d'un tableau d'avl en utilisant la grille 
Tableau *initTab(Grille *G)
{
  
  //declaration du tableau et allocation dynamique 
  Tableau *tab = (Tableau *) malloc(sizeof(Tableau));
  
  //allocation dynamique de du tableau d'avl
  tab->M = (AVL ***) malloc(sizeof(AVL **) * G->nbcoul);
  
  
  //allocation dynamique de chaque avl 
  for (int i = 0; i < G->nbcoul; i++) {
    tab->M[i] = (AVL **) malloc(sizeof(AVL *) * G->m);
  }
  
  //initialisation des avl  
  for (int i = 0; i < G->nbcoul; i++)
    {
      for (int j = 0; j < G->m; j++)
	{
	  tab->M[i][j] = NULL;
	}
    }
  
  
  //insertion des ordonées de chaque case non noir  dans la couleur coréspondante 
  for (int i = 0; i < G->m; i++)
    {
      for (int j = 0; j < G->n; j++)
	{
	  if (!est_noir(G->T[i][j]))
	    {
	      tab->M[G->T[i][j].fond][i] = insert(tab->M[G->T[i][j].fond][i],j);
	    }
	}
    }
  return tab;
}


// algorithme qui trouve la solution au jeu qui utilise les differents fonctions declarer 
void algorithme_AVL(Grille *G, Solution *S)
{
  Tableau *tab=initTab(G);
  int k=0,l=0;
  while (G->cptr_noire < G->m*G->n)
    {
      
      //swape la piéce du robot et la case contenant le contenant 
      swap_case(G);
      
      //ajout à la solution l'action du swap
      Ajout_action(S, 'S');
      
      
      //verification si le robot contient un case 
      if (robot_with_piece(G->T[G->ir][G->jr]))
	{
	  //si oui on recherche la case la plus proche a la coordonées du robot
	  CaseLaPlusProche(tab,G,G->T[G->ir][G->jr].robot, &k,G->jr, &l);
	  
	  // suppression de la case trouvé de l'avl 
	  tab->M[G->T[G->ir][G->jr].robot][k]=deleteNode(tab->M[G->T[G->ir][G->jr].robot][k],l);
	}
      else
	{
	  //si le robot ne contient pas de case
	  
	  //On cherche une case avec une piece non noir avec la recherche cerculaire car avec cella on doit parcourir toute les listes de tableau
	  PieceLaPlusProche(tab, G,&k,G->jr, &l);
	  //RechercheCaseCirculaire_nn(G,G->ir, G->jr,&k,&l);
	}
      //on ecris le chemin le plus cour dans la Solution
      PlusCourtChemin(S, G->ir, G->jr, k, l);
      //On change la case de robot
      changement_case(G, k, l);
    }
  freeTab(tab, G->nbcoul, G->n);
}


//algorithme qui recherche la case la plus proche qui correspantà la couleur du robot 
void CaseLaPlusProche(Tableau *t, Grille *G, int c, int *i, int j, int *k)
{
  
  if (!t)
    {
      return;
    }
  int colonne,ligne;
  int d = G->m + G->n;
  int  min=G->m+G->n;
  int initl=*i;
  int distance = G->m+G->n;
  
  //parcourir les lignes du tableau 
  for (ligne=0;ligne<G->m;ligne++)
    {
      //recherche une case 
      if (CaseLaPlusProcheInLigne(t->M[c][ligne], &d, j,&colonne)) 
	{
	  
	  //calculer la distance entre la case trouvé et la case du robot 
	  distance=distanceEtreDeuxPoint(initl,j,ligne,colonne);
	  
	  // si deux case on la meme distance on enregistre la plus haut a gauche 
	  if(distance == min && colonne < j)
	    {
	      *i=ligne;
	      *k=colonne;
	    }
	  
	  // si la distance est inférieur aux précédente on enregistre c coordonnées et on met a jour la distance 
	  if(distance<min)
	    {
	      *i=ligne;
	      *k=colonne;
	      min=distance;
	    }
	}
      d = G->m + G->n;
    }
}


//algorithme qui recherche la case la plus proche non noir des coordonnées actuel
void PieceLaPlusProche(Tableau *t, Grille *G, int *i, int j, int *k)
{
  //Si le tableau des AVL n'est pas a null
  if (!t)
    {
      return;
    }
  
  //initialisatio des variable
  int min=G->m+G->n;
  int initi=*i;
  int newl=*i,newj=0;
  
  //on cherche pour chaque couleur la Case qui n'est pas noire et a une piece Non noire
  for(int couleur=0 ; couleur < G->nbcoul;couleur++)
    {
      //On utulise la recheche des case
      CaseLaPlusProche(t,G,couleur,&newl,j,&newj);
      
      //Si la case trouver n'est pas noire et aa une piece 
      if(G->T[newl][newj].piece !=-1 && !est_noir(G->T[newl][newj]))
        {
	  //On calcule a distance entre la case trouve et le robot
	  int distance=distanceEtreDeuxPoint(initi,j,newl,newj);
	  
	  //si la distance == aux precedentes on stock celle a gauche
	  if(distance == min && newj < j)
	    {
	      
	      *i=newl;
	      *k=newj;
	    }
	  
	  //si elle est plus proche on la stock et on mis a jour le min
	  if (distance < min)
	    {
	      *i=newl;
	      *k=newj;
	      min=distance;
	    }
	}
    }
}


//algorithme qui recherche une casse dans une ligne du tableau d'avl 
int CaseLaPlusProcheInLigne(AVL *avl, int *dis, int j, int *k) {
  
  //Si le tableau des avl n'est pas Null
  if (!avl)
    {
      //On return La valeur NULL > non trouve
      return 0;
    }
  
  
  //en stock la diffrence entre le j et le j du noeud
  int  distance = abs(avl->j-j);
  
  //Si on arrive a une feuille et la diffrence entre les deux j < dis donné en paramtere on stock le j trouvé
  if(avl->left == NULL && avl->right == NULL && distance < *dis)
    {
      
      *k=avl->j;
      *dis=distance;
      //On return 1 > Trouve
      return 1;
    }
  
  //si j < a la racine on fais une recherche a gauche
  if (avl->j < j)
    {
      //si un noeud n'a pas un sous arbre droit on stock le J
      if(avl->right==NULL  && distance < *dis ) 
	{
	  *dis=distance;
	  *k=avl->j;
	  return 1;
	}
      return  CaseLaPlusProcheInLigne(avl->right, dis, j, k);
    }
  else
    if(avl->j > j)
      {
	
	if(avl->left==NULL  && distance < *dis )
	  {
	    *dis=distance;
	    *k=avl->j;
	    return 1;
	  }
	
	return CaseLaPlusProcheInLigne(avl->left, dis, j, k );
      }
    else
      {
	*dis=distance;
        *k = avl->j;
        return 1;
      } 
}


//lebration de la memoire dedier au tableau d'avl
void freeTab(Tableau *tab, int nbcoul, int n)
{
  
  //parcourir les cases du tableau d'avl et suppression de chaque avl 
  for (int i = 0; i < nbcoul; i++)
    {
      free(tab->M[i]);
    }
  
  //lebaration de la memoire dedié au tableau d'avl 
  free(tab->M);
  
  //leberer la memoire de la variable tab
  free(tab);
}
