//dans ce fichier on peut trouver les fonctions relatives aux personnages :
#include "structures.h"
#include "demande.h"

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

void demande_dep(deplacement *test)
{
	//demande du type de bushi à déplacer
	do
	{
	printf("Type de bushi : (S ; L ; D)");
	scanf("%c", &test->bushi);
	while(getchar()!='\n');
	}
	while((test->bushi != 'D') && (test->bushi != 'S') && (test->bushi != 'L'));

	//demande de la position de départ du bushi à déplacer
	printf("Quelle est la position du Bushi que vous voulez déplacer ?\n");
	printf("Ligne (départ) :\n");
	scanf("%d", &test->y_dep);
	printf("Colonne (départ) :\n");
	scanf("%d", &test->x_dep);

    //demande de la position d'arrivée du bushi à déplacer
	printf("Où voulez-vous déplacer votre Bushi ?\n");
	printf("Ligne (arrivée) :\n");
	scanf("%d", &test->y_arr);
	printf("Colonne (arrivée) :\n");
	scanf("%d", &test->x_arr);
}
