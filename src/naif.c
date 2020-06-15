#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<math.h>
#include"Solution.h"
#include"Grille.h"
#include"naif.h"
// algorithme naif 
void algorithme_naif(Grille *G, Solution *S)
{
  int k=0,l=0;
  while (G->cptr_noire<G->n*G->m)
    {
      // swape la couleur du robot et la piéce de la case  
      swap_case(G);
      // ajouter l'action S de Swap a la liste chainées de la  solution 
      Ajout_action(S,'S');

      //vérification si le robot a une piéce 
      if (robot_with_piece(G->T[G->ir][G->jr]))
	{
	  // recherche de la case la plus poche au robot qui a le meme fond que celle du robot 
	  RechercheCaseNaif(G,coleur_of_robot(G->T[G->ir][G->jr]),G->ir,G->jr,&k,&l);
	}
      else
	{

	 
	  // si le robot n'a pas de piéce on fait une recherche d'une piéce plus proche. 
	  RecherchePieceNaif(G,G->ir,G->jr,&k,&l);
	}

      //Ecrire dans la solution le chemain vers la case trouvé 
      PlusCourtChemin(S,G->ir,G->jr,k,l);

      // déplacer le robot la la case trouvé 
      changement_case(G,k,l);
    }
}

// algorithme de recherche de la piéce la plus proche  si le robot n'a pas de piéce 
void RecherchePieceNaif(Grille *G,int i,int j,int *k,int *l)
{
  //intitialisation de distance 
  int distance=G->m + G->n;

  //parcourir les lignes de la grille
  for (int ligne = 0; ligne < G->m; ligne++)
    {

      //parcourir les colonne de la grille 
      for (int colonne = 0; colonne < G->n; colonne++)
	{
	  
	  // si la case n'ai pas noir et qui a une piéce non noir
	  if (G->T[ligne][colonne].piece!=-1 && !est_noir(G->T[ligne][colonne]))
	    {
	      
	      // calculer la distance entre la case du robot et la case trouvé 
	      int dis = distanceEtreDeuxPoint(ligne,colonne,i,j);

	      //si la distance est inférieur aux distances précédentes 
	      if (dis<distance)
		{

		  // on sauvegarde les coordonées de la piéce et on met a jour la nouvelle distance 
		  distance = dis;
		  *k=ligne;
		  *l=colonne;
		  
		}
	    }
	}
    }
}


// algorithme de recherche une case non noir 
void RechercheCaseNaif (Grille *G, int c, int i, int j, int*k, int *l)
{
  // initialistion de la variable distance à la distance la plus grande de la grille 
  int distance=G->m+G->n;

  //parcourir le ligne de la grille 
  for (int ligne = 0; ligne < G->m; ligne++)
    {

      //parcourir les colonne de la grille 
      for (int colonne = 0; colonne < G->n; colonne++)
	{

	  // si le fond est egale a la couleur du robot et que la case n'ai pas noir 
	  if (G->T[ligne][colonne].fond==c && !est_noir(G->T[ligne][colonne]))
	    {

	      //calculer la diastance entre la case du robot et la case trouvé 
	      int dis = distanceEtreDeuxPoint(i,j,ligne,colonne);

	      //si la disatnce est inférieur aux distances précédentes 
	      if (dis<distance)
		{

		  //sauvegarder les coordonnées de la case et mise a jour de la distance 
		  distance = dis;
		  *k=ligne;
		  *l=colonne;
		}
	    }
	}
    }
}


