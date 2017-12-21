//IMPORTATION DES BIBLIOTHEQUES
#include "header.h"


//FONCTION DEMANDE DE DEPLACEMENT DU BUSHI (POSITION + TYPE)
void demande(deplacement *test)
{
	//demande du type de bushi à déplacer
	do
	{
	printf("Type de bushi : (S ; L ; D)");
	scanf("%c", &test->bushi);
	printf("%c", test->bushi);
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
	printf("Ligne (départ) :\n");
	scanf("%d", &test->y_arr);
	printf("Colonne (départ) :\n");
	scanf("%d", &test->x_arr);
}
