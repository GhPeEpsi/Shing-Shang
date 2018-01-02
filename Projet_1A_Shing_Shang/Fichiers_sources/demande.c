//dans ce fichier on peut trouver les fonctions relatives aux personnages :
#include "structures.h"
#include "demande.h"
#include "initialisation.h"


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

char demande_dep(deplacement *test)
{
        char res;
 
	//demande du type de bushi à déplacer
	do
	{
	printf("Type de bushi : (S ; L ; D)");
	scanf("%c", &test->bushi);
	while(getchar()!='\n');
	}
	while((test->bushi != 'D') && (test->bushi != 'S') && (test->bushi != 'L'));

        //enregistrement du bushis qui se déplace :
        res=test->bushi;

	//demande de la position de départ du bushi à déplacer
	printf("\nQuelle est la position du Bushi que vous voulez déplacer ?\n");
	printf("Ligne (départ) :\n");
	scanf("%d", &test->y_dep);
	printf("Colonne (départ) :\n");
	scanf("%d", &test->x_dep);

        //demande de la position d'arrivée du bushi à déplacer
	printf("\nOù voulez-vous déplacer votre Bushi ?\n");
	printf("Ligne (arrivée) :\n");
	scanf("%d", &test->y_arr);
	printf("Colonne (arrivée) :\n");
	scanf("%d", &test->x_arr);
	while(getchar()!='\n');  //permet d'eviter d'entrer 2 fois le type de bushis au tour suivant

        //retour du bushi qui se déplace :
        return res;
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

//#############################################################################################################################################


