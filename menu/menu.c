#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"Solution.h"
#include"Grille.h"
#include"avl.h"
#include"Cerculaire.h"
#include"LDC.h"
#include"naif.h"

int main(int argc, char ** argv){
  //verification des paramettres
  if (argc!=5 || atoi(argv[3]) > (atoi(argv[1])*atoi(argv[2]) )  )
    {

      fprintf(stderr, "%s\n","ERREUR");
      return EXIT_FAILURE;

    }
  
  //Varibables qui vont service au calcule du temps d'exécution 
  double  temps;
  clock_t t1, t2;
	    
  //Creation de la liste de Solution
  Solution *S= (Solution *)malloc(sizeof(Solution));
  Solution_init(S);
  

  //Creation de la grille
  Grille *G = (Grille *)malloc(sizeof(Grille));


  //initialisation de la grille
  G->m=atoi(argv[1]);
  G->n=atoi(argv[2]);
  G->nbcoul=atoi(argv[3]);
  Grille_allocation(G);
  Gene_Grille(G,atoi(argv[4]));




  //Affichage d'un Message enregitré dans un fichier 
  FILE *f=NULL;
  if((f=fopen("Debut.txt","r"))==NULL)
    {

      printf("fichier introuvable ");
      return -1;

    }



  //lecture du fichier contenant le dessin du premier affichage 
  char ligne[256];
  while (fgets(ligne,256,f)!=NULL )
    {
      puts(ligne);
    }
  

  //laissez l'utilisateur interagir
  printf("apouyez sur une touche ");
  getchar();
  system("clear");
  fclose(f);
  

  int choix = 0;

 menu:
  //Affichage du menu Pour chosiir Le Type de Strucure utiliser pour Le Jeu du Robot Trieur
  printf("\n============================MENU=================================\n");	
  printf("Choisir La structure de Données pour Trouvé la solution du Robot trieur !\n");
  printf("\t 1- Struture de Matrice !                                              \n");
  printf("\t 2- structure de Liste doubelement chainnées                           \n");
  printf("\t 3- Strucutre de Graphe !                                              \n");
  printf("\t 4- Quitter                                                            \n"); 
  printf("\n\nquelle est votre choix?  ");

  
  //Récupéré le chois de l"utilisateur  a l'aide d'un entier designant son choix 
  scanf("%d",&choix);
  system("clear");
  

  //verification que le choix est valide 
  if(choix != 1 &&  choix!=2 &&  choix!=3 &&  choix!=4)
    {
      
      printf(" choissir réponse Valide {1,2,3,4} C'est un Jeu D'enfant !  ");
      goto menu;
      
    }
  


  //Parser le chois de l'tulisateur et utilisation de L'algorithme adequoit pour lui 
  switch (choix)
    {

      //Cas de L'utilisation D'une Matrice 
    case 1:
      
                 printf("\n\n Vous avez chosir la structure de matrice faire attention à ne pas sortir des bordure !!!!\n");
      
                 //choisir entre Algorithme naif et circulaire 
                 int choix2=10;

                 menu1:
		 //Menu qui permet à l'utilisateur de choisir le type d'algorithme a utilisé! ");
		 printf("\n\nVous avez Choisie La Structure Matricielle  :\n\t\t choissez L'algorithme à utilisé !?\n");
		 printf("\t\t\t 1- Algorithme naif\n");
		 printf("\t\t\t 2- Algorithme Circulaire\n");
		 printf("\t\t\t 0- Revenir en Arriere                                                                                   ");	
		 
		 
		 //recupération du choix de l'utilisateur 
		 printf("\n\n Quelle est votre choix ? ");
		 scanf("%d",&choix2);
		 

		 //verfication que le choix de l'utilisateur est valide 
		 if(choix2 !=0 && choix2 != 1 && choix2 != 2)
		   {

		     system("clear");
		     printf(" \n\n Choisir une valeur valide  {0,1,2} Vous y ete presque !! ");
		     goto menu1;

		   }
		 
		 //effacer la console 
		 system("clear");


		 //parser le deuxieme chooix de l'utilisateur entre l'algorithme naif ou circulaire ou le retour a l'arriere 
		 switch (choix2)
		   {
		     
		   case 1:
		     {

		       //execution du choix de L'utilisateur ALGORITHME NAIF !
		       printf("\n\nVous avez choisie l'algorithme naif !!!!! \n\t bonne idée mais comme a dit Anne Barratin :\n <<La ruse aime à se cacher sous la naïveté, comme une reprise sous un ruban>> \n");

		       //Capturer le temps d'entre à la fonction de L'algorithme NAIF
		       t1 = clock();

		       //Execution de L'algorithme Naif sur  la grille 
		       algorithme_naif(G,S);

		       //Capture le temps de sortie de l'algorithme 
		       t2 = clock();
		       

		       //finir le jeu
		       goto fin;
		       break;
		       
		     }
		     
		     
		   case 2:
		     {

		       //Execution de L'ALGORITHME CIRCULAIRE 
		       printf("\n\nVous avez choisie L'agorithme Circulaire \n\t Attention à ne pas tourné en rond !!\n");


		       //capturer le temps d'entré vers L'algorthme Circulaire 
		       t1 = clock();

		       //Execution  de L'algorithme Circulaire 
		       algorithme_circulaire(G,S);

		       //Capturer le temps de sortie de l'ALGORITHME Circulaire  
		       t2 = clock();
			
		       //finir le jeu
		       goto fin;

		       //sortie du switch gerant le choix entre lalgorithme Naif Ou Circulaire !!!!!
		       break;
		       
		     }

		   case 0:
		     {

		       //retour au premier menu 
		       printf("\n\n !! a bracadabra remontant le temps\n ");
		       goto menu;
		       break;

		     }
		   }
		 
	  break;
	  //fin du cas du choix 1 avec la Matrice 
       


       


    //cas de strucutre de Liste 
    case 2:
      {

	                    //Execution de l'algorithme utilsant Les Listes Doublement chainées !!
	                    printf(" Vous  Avez Choisie L'algorithme Utilisatant LEs Liste Doublement Chainées \n\t\t bon choix coté rapidité mais Vous Vous  etes Posez La Question de La Memoire !!!!? \n\n "); 

			    
			    //caputer le temps de debut
			    t1 = clock();
			    
			    //Appel à l'ALGORITHME Utilisant les Listes Doublement Chainées 
			    algorithme_LDC(G,S);

			    // capturer le temps de fin 
			    t2 = clock();
			    
			    goto fin;
			   
			    
	
	break;

      }



// Le Choix de L'algorithe entre Graphe et AVL 
    case 3:
      {
	          int choix3=10;
                  menu3: 
		  //menu pour Choisir entre L'usage du graphe ou l'usage des Arbres 
		  printf("\n\n\nVous avez choisie La Structure de Graphe:                      \n");
		  printf("\t 1- Structure d'Arbre AVL qui est un Graphe Maximum acylique \n");
		  printf("\t 2- Structure de graphe avec Algorithme De Daniel            \n");
		  printf("\t 3- Structure de graphe generale                             \n");
		  printf("\t 0- Retour en arriére                                        \n");
		  
		  
		  //recupération du chois de l'utilisateur
		  printf("\n\nQuelle est votre Choix? ");
		  scanf("%d",&choix3);
		  system("clear");

		  //verification que l'utilisateur a choisie une reponse valable 
		  if(choix3 != 0 && choix3 !=1 && choix3 && choix3 !=2 && choix3 !=3)
		    {

		      //si non afficahge d'un message L'avertissant 
		      printf(" choisir une reponse valide 0 1 et 2 \n\n");
		      
		      //retour au petit menu des choix d'algorithme 
		      goto menu3;

		    }

		  //si le choix est valide Parser le choix de L'utilisateur 
		  switch (choix3)
		    {
		    case 0:
		      {

			//retour au menu des Structure !
			printf(" ABRACADABRA Retour en Arriere !!!\n\n");

			//appel au label d'ou commence le  Menu des strucutre 
			goto menu;

			//sortie du switch qui parse le choix de lalgorithme entre AVL et Graphe
			break;
		      }
		      
		      //cas ou l'utilisateur  a choisie L'algorithme Utilisant les ARBRE type AVL  
		    case 1:
		      {
			printf(" Vous avez choisie la structure d'ARBRE AVL \n \tattention de ne pas se perdre dans la foret !\n\n");

		        //capturer le temps d'entré 
			t1 = clock();

			//appel a l'algorithme Utilisatant L'avl 
			algorithme_AVL(G,S);

			//Capturer le temps de sortie de la fonction 
			t2 = clock();

			//sortir Du Programme et affichage des reusltant !
			goto fin;

			//sortie du switch 
			break;
		      }

		      //Cas Ou L'utilisateur a Choisie L'algorithme utilisant les Graphes 
		    case 2:
		      {

			system("make all -C ../SortingProject-daniel_graf/ >/dev/null");
			char commande [120];
			sprintf(commande,"../SortingProject-daniel_graf/game %s %s %s %s",argv[1],argv[2],argv[3],argv[4]);
			printf(commande);
			printf(" vous avez chosie la structure  de Graphe \n \tJ'essepere que vous savez Lire une Carte\n\n");

	        	//Capture le temps de sortie de l'algorithme 
			t1 = clock();

			system(commande);

			//Capture le temps de sortie de l'algorithme 
			t2 = clock();

			int rep=-1;
			printf(" Voulez vous Réessayer encore avec Un autre ?? \n je sais c'est  marrant !!!\n");
			do
			  {
			    printf(" \t\tVotre reponse ? 1 -OUI 0- NON (Coté Binaire!! ) ");
			    scanf("%d",&rep);
			  }
			while (rep !=0 && rep !=1);
			if(rep)
			  {
			    
			    system("clear");
			    goto menu;
			    
			  }
			
			//sortie de L'algorithme et Afficahge des Resultat 
			goto fin2;
			
			//sortie du switch qui gere les algorithme a utiliser avvec les AVL Ou graphe
			break;
			
		      }
		    case 3:
		      {
			system("make all -C ../graphe_general/ >/dev/null");
			char commande [120];
			sprintf(commande,"../graphe_general/game %s %s %s %s",argv[1],argv[2],argv[3],argv[4]);
			printf(commande);
			printf(" vous avez chosie la structure  de Graphe \n \tJ'essepere que vous savez Lire une Carte\n\n");

	        	//Capture le temps de sortie de l'algorithme 
			t1 = clock();

			system(commande);

			//Capture le temps de sortie de l'algorithme 
			t2 = clock();
			
			printf(" Voulez vous Réessayer encore avec Un autre ?? \n je sais c'est  marrant !!!\n");
			int rep=-1;
			do
			  {
			    printf(" \t\tVotre reponse ? 1 -OUI 0- NON (Coté Binaire!! ) ");
			    scanf("%d",&rep);
			  }
			while (rep !=0 && rep !=1);
			
			if(rep)
			  {
			    
			    system("clear");
			    goto menu;
			    
			  }
			
			//sortie de L'algorithme et Afficahge des Resultat 
			goto fin2;

			//sortie du switch qui gere les algorithme a utiliser avvec les AVL Ou graphe
			break;

		      
		      }
		    }
		  break;
      }
      

      //cas ou l'utilisateur veut Sortir du programme !!!!
 case 4:
      {
	
	//sortir du menu
	system("clear");

	//allez vert la sortie du programme 
	goto fin2;

	//sortie du switch  qui parse les choix des structure 
	break;

      }
      
    }
  
 fin:
  //Calculer le Temps D'execution 
  temps = (float)(t2-t1)/CLOCKS_PER_SEC;
  
  //affichage du temps exploité par l'algoithme pour trouvé la solution 
  printf("\n Temps d'excution de l'algorithme de :  %f s \n ",temps); 

  printf("\n\t nombre de Pas : %d\n",S->cptr_pas);
  printf(" \n \tAppuyez sur une touche !!\n");
  getchar();
  getchar();
  system("clear");
  
  //Ecrite de la solution dans le dis que 
  Ecriture_Disque(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]),S);
  int rep=-1;

  //dmander a l'utilisateur s'il veut continuer ou pas LE programme avec une autre structure !

  printf(" Voulez vous Réessayer encore avec Un autre ?? \n je sais c'est  marrant !!!\n");
  do
    {
      printf(" \t\tVotre reponse ? 1 -OUI 0- NON (Coté Binaire!! ) ");
      scanf("%d",&rep);
    }
  while (rep !=0 && rep !=1);
  if(rep)
    {
      
      system("clear");
      goto menu;

    }

  goto fin2;
  
 fin2:
  //message de fin du Programme 


  printf("\n\n Merci D'avoir jouer Au ROBOT TRIEURE Au Revoir \n\n ");

  
  //Liberer la memoir de la grille    
  freeGrille(G);
  
  //liberer la memoir de la liste de solution
  freeSolution(S);
  
  
  return 0;
}
