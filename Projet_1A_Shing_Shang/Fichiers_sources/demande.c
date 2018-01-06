//dans ce fichier on peut trouver les fonctions relatives aux personnages :
#include "structures.h"
#include "demande.h"
#include "initialisation.h"
#include "affichage.h"


void entre_joueur(int nb, perso *p)
{
 //###### coment #####
 //cette fonction sert a demander le nom des joueurs :
 //

 //remplissage des tableaux
 //Demande pseudo1
 printf("\nVeuillez entrer le nom du joueur %d :\n",nb);
 scanf("%s",p->nom);
 while(getchar() !='\n');

}

//##############################################################################################################################################

char choix_demande_dep(deplacement test[MAX_SAUTS], int j)
{
 if(j==0)
 {
  //printf("Choix_demande_dep : j==0 "); //debug
  demande_dep_dep(test, j);
  demande_dep_arr(test, j);
 }
 else
 {
  if(test[j-1].saute==1)
  {
   //printf("Choix_demande_dep : j!=0 et il y a deja eu un saut"); //debug
   recupe_cordo(test, j);   
   demande_dep_arr(test, j);
  }
  else
  {
   //printf("Choix_demande_dep : j!=0 et il n'y a pas deja eu de saut"); //debug
   demande_dep_dep(test, j);
   demande_dep_arr(test, j);
  }
 }
 
}

//##############################################################################################################################################

int recupe_cordo(deplacement move[MAX_SAUTS], int j)
{
 
 //printf("pion sauté : recup_cordo\n ");  //debug 

 move[j].bushi=move[j-1].bushi; //printf("%c",move[j].bushi); //debug
 move[j].x_dep=move[j-1].x_arr; //printf("%d",move[j].x_dep); //debug
 move[j].y_dep=move[j-1].y_arr; //printf("%d",move[j].y_dep); //debug
}

//##############################################################################################################################################

char demande_dep_dep(deplacement test[MAX_SAUTS], int j)
{ 
 //demande du type de bushi à déplacer
 do
 {
  printf("Type de bushi : (S ; L ; D)");
  scanf("%c", &test[j].bushi);
  while(getchar()!='\n');
 }
 while((test[j].bushi != 'D') && (test[j].bushi != 'S') && (test[j].bushi != 'L'));

 //demande de la position de départ du bushi à déplacer
 printf("\nQuelle est la position du Bushi que vous voulez déplacer ?\n");

 do
 {
  printf("Ligne (départ) :\n");
  scanf("%d", &test[j].y_dep);
  while(getchar()!='\n');
 }
 while((test[j].y_dep>=10) || (test[j].y_dep<0));

 do
 {
  printf("Colonne (départ) :\n");
  scanf("%d", &test[j].x_dep);
  while(getchar()!='\n');
 }
 while((test[j].x_dep>=10) || (test[j].x_dep<0));
 
}

//##############################################################################################################################################

int demande_dep_arr(deplacement test[MAX_SAUTS], int j)
{

 //demande de la position d'arrivée du bushi à déplacer
 printf("\nOù voulez-vous déplacer votre Bushi ?\n");
 do
 {
  printf("Ligne (arrivée) :\n");
  scanf("%d", &test[j].y_arr);
  while(getchar()!='\n');
 }
 while((test[j].y_arr>=10) || (test[j].y_arr<0));
 
 do
 {
  printf("Colonne (arrivée) :\n");
  scanf("%d", &test[j].x_arr); 
  while(getchar()!='\n');
 }
 while((test[j].x_arr>=10) || (test[j].x_arr<0));

 //while(getchar()!='\n');  //permet d'eviter d'entrer 2 fois le type de bushis au tour suivant

}

//#############################################################################################################################################

int qui_commence(perso *joueur1, perso *joueur2)
{
	//VARIABLES
	int res_choix, res;

	//CHOIX DE L'ORDRE DE JEU PAR LES joueurS
	res_choix=ordre_jeu(*joueur1, *joueur2);

	//SELON LE CHOIX DES joueurS, ON LANCE LE PILE OU FACE OU ON INITIALISE COMME ILS L'ONT CHOISI
	if (res_choix==3)
	{
		res=pile_face(joueur1, joueur2);
	}
	else
	{
		res=decide(joueur1, joueur2, res_choix);
	}
  
        printf("numero joueur %s : %d\n",joueur1->nom,joueur1->numero);
        printf("numero joueur %s : %d\n",joueur2->nom,joueur2->numero);

  //retour de qui commence :
  return res;
}

//#############################################################################################################################################

int ordre_jeu(perso joueur1, perso joueur2)
{
	int choix;

	do
	{
		printf("\n");
		printf("'1' --> %s joue en premier\n", joueur1.nom);
		printf("'2' --> %s joue en premier\n", joueur2.nom);
		printf("'3' --> On tire a pile ou face !\n");
		scanf("%d", &choix);
	}
	while((choix!=1) && (choix!=2) && (choix!=3));

	//ON RETOURNE CE CHOIX A LA FONCTION MAIN
	return choix;
}

//###########################################################################################################################################

int vouloir_autre_saut(deplacement move[MAX_SAUTS], int j)
{
 //comment :
 //cette fonction sert a demander si le joueur beux refair un saut avec le même bushis :
 //
 
 int i, res=0; 

 if(move[j].saute==1)
 {
  do
  {
   aff_vouloir_rejouer();
   scanf("%d",&i);
   while(getchar() !='\n');
  }
  while((i!=0)&&(i!=1));

  if(i==1) 
  {
   res=1;
  }
  else
  {
   res=0;
  }
 }
 else
 {
  res=0;
 }

return res;
}


