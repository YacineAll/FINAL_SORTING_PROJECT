#include <stdio.h>
#include <stdlib.h>
#include "Grille.h"
#include "LDC.h"

// qui alloue et retourne une cellule
CelluleLDC * creerCellule(int i, int j)
{

  //allocation dynamique de la memoire dedié a la cellule
  CelluleLDC * cellule = (CelluleLDC *) malloc(sizeof(CelluleLDC));

  if (cellule == NULL)
    {

      //afficahge d'un message d'erreur en cas de non fonctionnement de l'allocation
      fprintf(stderr, "%s\n", " Erreure d'allocation sur la methodes creerCellule(int i,int j )");

      return NULL;
    }

  //initialisation des attribut de la cellule
  cellule->i = i;
  cellule->j = j;
  cellule->prec = NULL;
  cellule->suiv = NULL;

  //renvoyer la cellule 
  return cellule;
}

// qui initialise une liste
void LDCInitialise(LDC *ldc)
{

  if (!ldc)
    {
      fprintf(stderr, "%s\n"," Erreur lors de la creation de la cellule fonction LDCInitialise()");
      return;
    }

  //initialisation des attribut de la file 
  ldc->premier = NULL;
  ldc->dernier = NULL;
}

// qui teste si la liste est vide
int LDCVide(LDC *ldc)
{
  if (!ldc)
    return -1;


  //revoie 1 si la liste est vide
  if (ldc->premier == NULL && ldc->dernier == NULL)
    {
      return 1;
    }

  //renvoie 0 si la liste n'ai pas vide 
  return 0;
}


//qui insere une nouvelle cellule en fin
void LDCInsererEnFin(LDC *ldc, int i, int j)
{

  //verification si la file est vide 
  if (ldc == NULL) {
    fprintf(stderr, "%s\n", "Erreur dans la fonction LDCInsererEnFin");
    return;
  }
  
  //creation de la cellule a ajouter dans file 
  CelluleLDC *ajout = creerCellule(i, j);
  
  //verification si la file est vide  
  if (!(ldc->premier))
    {
      //pointer le premier pointeur de la fille vers la cellule 
      ldc->premier = ajout;
    }
  
  //si la fille contient deja au moin un element 
  if (ldc->dernier)
    {
      //faire pointer le suivant de la cellule avece le dernier de la fille 
      ajout->prec = ldc->dernier;
      
      //mettre a jour le pointeur du dernier de la fill vers la  nouvelle fin  
      ldc->dernier->suiv = ajout;
    }
  
  ldc->dernier = ajout;
}

// qui supprime une cellule a partir d un pointeur sur la cellule
void LDCenleverCellule(LDC * ldc, CelluleLDC * cel)
{
  if (ldc == NULL || cel == NULL)
    {
      fprintf(stderr, "%s\n", "Erreure liste vide LDCenleverCellule( )");
      return;
    }
  
  //si la cellule a supprimer est la premiere cellule de la file
  if (ldc->premier == cel && ldc->premier == cel)
    {
      
      //pointer vers le suivat de la cellule
      ldc->premier = cel->suiv;
      
    }
  
  
  //si la cellule a supprimer est la dernier de la file
  if (ldc->dernier == cel && ldc->dernier == cel)
    {
      
      //mettre a jour le pointeur
      ldc->dernier = cel->suiv;
      
    }
  
  
  // cas de suppression au millieu de la files
  //verification que le precedent existe
  if (cel->prec)
    cel->prec->suiv = cel->suiv;
  
  
  //verification que le suivant existe
  if (cel->suiv)
    cel->suiv->prec = cel->prec;
  
  
  //liberation d ela memoire allouer pour la cellule
  if (cel)
    {
      free(cel);
    }
}

// un affichage en cas de besoin pour debugage
void LDCafficher(LDC * ldc)
{

  //verification que la strucutre existe
  if (ldc == NULL)
    {
      fprintf(stderr, "%s\n", " Erreure lors de l'affichage files vide LDCafficher(LDC * ldc) ");
      return;
    }

  //creation d'un copie de la file
  CelluleLDC *celulle_temporaire = ldc->premier;


  //parcour de la fille et affichge
  while (celulle_temporaire)
    {

      //afficher le contenu de chaque cellule 
      printf("(%d , %d)\n", celulle_temporaire->i, celulle_temporaire->j);

      // bouger dans la liste 
      celulle_temporaire = celulle_temporaire->suiv;

    }
}


// qui desalloue toute la liste (si elle n est pas vide a la fin)
void LDCdesalloue(LDC *ldc)
{
  if (!ldc) {
    fprintf(stderr, "%s\n",
	    " Erreur dans la fonction LDCdesalloue() ldc vide ");
    return;
  }
  if (ldc)
    {

      //cereation d'un copie temporaire pour le debut de la cellule
      //CelluleLDC *celulle_temporaire=ldc->premier;
      //suppression de la files doublement chainer
      while (ldc->premier)
	{
	  
	  //enregistrer le suivant dans une variable emporaire 
	  CelluleLDC *tmp = ldc->premier->suiv;

	  //liberation de la memoire allouer
	  free(ldc->premier);

	  //mettre a jour le pointeur
	  ldc->premier = tmp;
	}
      
      ldc = NULL;
    }
}



//Chercher dans la liste ldc la case la plus proche de la case (i,j)
CelluleLDC* LDCrechercherPlusProcheCase(LDC* ldc, int i, int j)
{
  
  //Si ldc est NULL on retourne
  if (!ldc)
    {
      
      fprintf(stderr, "%s\n", " probleme fntion LDCrechercherPlusProcheCase");
      
      return NULL;
      
    }
  
  //cel pour retourne la Cellule qui Contienne (k,l)
  CelluleLDC *cel = ldc->premier;
  
  //Si cell est null on sort pour eveter les SIGGEV
  if (cel == NULL)
    {
      //fprintf(stderr, "%s\n", " probleme cellule vide ");
      return cel;
    }


  //calculer la distance entre la case 1ere case de la liste et (i,j)
  int dis = distanceEtreDeuxPoint(i, j, cel->i, cel->j);


  //une Cellule tmporaire pour parcourir la liste qui pointe sur la 2eme cellule
  CelluleLDC *tmp = cel;


  while (tmp)
    {
      //calcule la distance entre (i,j) et (tmp->i,tmp->j)
      int distance = distanceEtreDeuxPoint(i, j, tmp->i, tmp->j);
      
      //si la distance de (tmp->i,tmp->j) vers (i,j)<=
      if (distance <= dis)
	{
	  //sila distance == a la nouvelle distance on verfie a ce que la case est plus haut a gauche et on la sauvegardex
	  
	  if (distance == dis && tmp->j < j) 
	    {
	      cel = tmp;
	    }
	  
	  
	  //et si distance inferieur strictement on point vers tmp avec cel et on sauvegarde la distance
	  if (distance < dis)
	    {
	      cel = tmp;
	      dis = distance;
	    }
	}

      //on point vers le suivant element
      tmp = tmp->suiv;
    }

  //on retourne le pointeur vers la cellule trouvé
  return cel;
}



//Initialise le tableau et on remplie un tableau de LDC de cellule et chaqe case contient la liste des case qui ont la meme couleur
LDC *TC(Grille *G)
{
  //instantiation du tableau
  LDC *tableau = (LDC *) malloc(sizeof(LDC) * G->nbcoul);

  //verification que le tableau  a bien était allouer
  if (tableau == NULL)
    {
      fprintf(stderr, "%s\n", " erreur lors de la creation du tableau ");
      return NULL;
    }

  //initialisation les files du tableaux
  for (int i = 0; i < G->nbcoul; i++)
    {
      LDCInitialise(&tableau[i]);
    }


  //insertion des cases de la grilles dans le tableau
  for (int i = 0; i < G->m; i++)
    {
      for (int j = 0; j < G->n; j++)
	{
	  if (!est_noir(G->T[i][j]))
	    {

	      //on insert la une cellule(i,j) dans la liste de T[couleur de case[i,j]]
	      LDCInsererEnFin(&tableau[G->T[i][j].fond], i, j);

	    }
	}
    }
  return tableau;
}



//algorithme permettant de chercher la case la plus proche du robot equivalent à al couleur de la piéce du robot
void recherchePiece_NN (LDC *t,Grille *G,int i, int j,int *k,int *l)
{
  // initialisation de la variable max a une distance grande 
  int min = G->m+G->n;

  //parcourir la file 
  for(int c=0;c<G->nbcoul;c++)
    {
      //faire appel à la fonction qui prend en parametre une liste et les coordonnées du robot  et renvoie la case la plus proche de ses coordonnées 
      CelluleLDC *cel = LDCrechercherPlusProcheCase(&t[c],i,j);
      if(cel && !est_noir(G->T[cel->i][cel->j]))
	{	   

	  //calculer la distance entre la case contenant le robot et la cellule trouvé 
	  int distance=distanceEtreDeuxPoint(i,j,cel->i,cel->j);
	  
	  //si la distance est egale à la distance on verifie si elle se situe plus à gauche  que celle deja trouvé on enregistre ses coordonnées 
	  if (distance == min && cel->j < j ) 
	    {
	      *k=cel->i;
	      *l=cel->j;
	    }
	      
	  //si la distance est inferieur au précédente on enregistre les coordonnées de la nouuvelles case et on met à jour la distance 
	  if(distance<min)
	    {
	      *k=cel->i;
	      *l=cel->j;
	      min=distance;
	    }
	}
    }
  
}





//le meme algo avec les precedent sauf ici on utilise les cellule
void algorithme_LDC(Grille *G, Solution *S)
{
  LDC *tableau=TC(G);
  //on initialise une cellue a NULL et qui va nous servir a faire des recherches
  CelluleLDC *cel = NULL;
  //Tant que il reste des cases non noirs
  int k = 0, l = 0;
  while (G->cptr_noire < G->m * G->n)
    {
      swap_case(G);
      Ajout_action(S, 'S');
      if (robot_with_piece(G->T[G->ir][G->jr]))
	{
	  //recherche la case la plus proche et retourne une cellule (k,j)
	  cel = LDCrechercherPlusProcheCase(&tableau[coleur_of_robot(G->T[G->ir][G->jr])],G->ir, G->jr);
	  k = cel->i;
	  l = cel->j;
	  //On enleve la cellule trouve
	  LDCenleverCellule(&tableau[coleur_of_robot(G->T[G->ir][G->jr])],cel);
	}
      else
	{
	  //On cherche une case avec une piece non noir avec la recherche cerculaire car avec cella on doit parcourir toute les listes de tableau
	  // RechercheCaseCirculaire_nn(G, G->ir, G->jr, &k, &l);
	  recherchePiece_NN (tableau,G,G->ir, G->jr,&k,&l);
	}
      //on ecris le chemin le plus cour dans la Solution
      PlusCourtChemin(S, G->ir, G->jr, k, l);
      //On change la case de robot
      changement_case(G, k, l);
    }
     free(tableau);

}
