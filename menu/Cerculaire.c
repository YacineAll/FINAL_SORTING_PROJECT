#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<math.h>
#include"Solution.h"
#include"Grille.h"
#include"Cerculaire.h"


//Une Recherche auteur de la case (i,j) et arrete des que elle trouve la case avec une couleur c
void RechercheCaseCirculaire_c(Grille *G, int c, int i, int j, int *K, int *L)
{
  //initialise la distance a quelle on cherche en 1
  int l = 1;
  //tant que le l < a la distance la plus grande qui pourrait etre
  while (l < G->m + G->n)
    {
      //k est l'abscisse de i - la distance a quelle cherche d' en bas vers haut
      int k = i - l;
      //k= k<0 ? i:k;
      //ordonnée pour chercher a gauche
      int lg = j;
      //ordonnée pour chercher a droite
      int ld = j;
      //tant que l'abscisse est inferieur a i
      while (k <= i)
	{
	  //si k n'a pas dépasser les bornes
	  if (k >= 0 && k < G->m)
	    {
		  //si lg l'indice a gauche n'a pas depasse les bornes et la la couleur de la case(k,lg) = C et ell n'est pas noire
	      if (lg >= 0 && lg < G->n && G->T[k][lg].fond == c && !est_noir(G->T[k][lg]))
		{
		  //On retourne la case (k,lg) par K et L et on continue pas chercher dans les autres cotes
		      *K = k;
		      *L = lg;
		      return;
		}
		  //si ld l'indice a gauche n'a pas depasse les bornes et la la couleur de la case(k,lg) = C et ell n'est pas noire
	      if (ld >= 0 && ld < G->n && G->T[k][ld].fond == c && !est_noir(G->T[k][ld]))
		{
		  //On retourne la case (k,lg) par K et L et on continue pas chercher dans les autres cotes
		      *K = k;
		      *L = ld;
		      return;
		}
	    }
	  //increment les abscisse
	  k++;
	  //decremente vers la gauche
	  lg--;
	  //incremente vers la droite
	  ld++;
	}
      //On refais la recherche de i+l donc d'en haut en bas
      k = i + 1;
      //On mis lg a j-la distance l + 1 pour increment pour monter jusqu'au j
      k= k>G->m ? G->m:k;
      lg = j - l + 1;
      //On mis lg a j-la distance l + 1 pour increment pour descendre jusqu'au j
      ld = j + l - 1;
      //tant que k < a i plus la distance
      while (k <= i + l)
	{
	  //si k ne depasse pas les bornes
	  if (k >= 0 && k < G->m)
	    {
	      // si lg ne depasse pas les bornes et la case est de la meme couleur que c et elle n'est pas noir
	      if (lg >= 0 && lg < G->n && !est_noir(G->T[k][lg]) && G->T[k][lg].fond == c)
		{
		  //On retourne la case(k,lg)
		  *K = k;
		  *L = lg;
		  return;
		}
	      // si lg ne depasse pas les bornes et la case est de la meme couleur que c et elle n'est pas noir
	      if (ld >= 0 && ld < G->n && !est_noir(G->T[k][ld]) && G->T[k][ld].fond == c)
		{
		  //On retourne la case(k,ld)
		  *K = k;
		  *L = ld;
		  return;
		}
	    }
	  //incrementer le k jusqua a i+la distance
	  k++;
	  //incrementer le lg vers j
	  lg++;
	  //decrementer le ld vers j
	  ld--;
	}
      //incrementer le l jusqu'a trouver la case
      l++;
    }
}
//chercher une case auteur de rebot qui contienne une case avec une piece non noir et c'est le meme algo comme ce lui d'avant c juste ici on verfie que les case contienne une piece et si le cas on retourne
void RechercheCaseCirculaire_nn(Grille *G, int i, int j, int *K, int *L)
{
  //initialise la distance de 1
  int l = 1;
  while (l < G->m + G->n)
    {
      int k = i - l;
      int lg = j;
      int ld = j;
      while (k <= i)
	{
	  if (k >= 0 && k < G->m)
	    {
	      if (lg >= 0 && lg < G->n && G->T[k][lg].piece != -1 && !est_noir(G->T[k][lg]))
		{
		  *K = k;
		  *L = lg;
		  return;
		}
	      if (ld > 0 && ld < G->n && G->T[k][ld].piece != -1
		  && !est_noir(G->T[k][ld]))
		{
		  *K = k;
		  *L = ld;
		  return;
		}
	    }
	  k++;
	  lg++;
	  ld--;
	}
      
      k = i + 1;
      lg = j - l + 1;
      ld = j + l - 1;
      
      while (k <= i + l)
	{
	  if (k >= 0 && k < G->m)
	    {
	      if (lg >= 0 && lg < G->n && G->T[k][lg].piece != -1 && !est_noir(G->T[k][lg]))
		{
		  *K = k;
		  *L = lg;
		  return;
	      }
	      if (ld >= 0 && ld < G->n && G->T[k][lg].piece != -1
		  && !est_noir(G->T[k][ld]))
		{
		  *K = k;
		  *L = ld;
		  return;
		}
	    }
	  k++;
	  lg++;
	  ld--;
	}
      l++;
    }
}

//Utilise l'algorithme cerculaire pour la solution du jeu 
void algorithme_circulaire(Grille *G, Solution *S)
{
  int k = 0, l = 0;
  // reproduire le boucle jusqu'a ce que le nombre de case noirs sois equivalent au nombre de cases de la grilles 
  while (G->cptr_noire < G->n * G->m)
    {
     
      swap_case(G);

      //ajouter l'action du swap dans la liste chainnées de la solution
      Ajout_action(S, 'S');

      //si le robot a une péice 
      if (robot_with_piece(G->T[G->ir][G->jr]))
	{
	  
	  //on fait appel a la fonction rechercheCaseCirculaire_c qui cherche la case la plus proche avec la meme couleur de fond que le robot
	  RechercheCaseCirculaire_c(G, coleur_of_robot(G->T[G->ir][G->jr]),G->ir, G->jr, &k, &l);
	}

      // si le robot n'a pas de piéce alors 
      else
	{
	  // on fait appel a la fonction RechercheCaseCirculaire_nn qui cherche la case la plus proche  non noir de la position actuel du robot
	  RechercheCaseCirculaire_nn(G, G->ir, G->jr, &k, &l);
	}
      
      //ajouter l'action dans la solution qui permet de bouger le robot vers la case trouvé 
      PlusCourtChemin(S, G->ir, G->jr, k, l);

      //bouger le robot 
      changement_case(G, k, l);
    }
}
