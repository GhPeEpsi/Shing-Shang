//IMPORTATION DES BIBLIOTHEQUES
#include "header.h"


//FONCTION DEMANDE DE DEPLACEMENT DU BUSHI (POSITION + TYPE)
void demande(deplacement *test)
{
	//demande du type de bushi � d�placer
	do
	{
	printf("Type de bushi : (S ; L ; D)");
	scanf("%c", &test->bushi);
	printf("%c", test->bushi);
	while(getchar()!='\n');
	}
	while((test->bushi != 'D') && (test->bushi != 'S') && (test->bushi != 'L'));

	//demande de la position de d�part du bushi � d�placer
	printf("Quelle est la position du Bushi que vous voulez d�placer ?\n");
	printf("Ligne (d�part) :\n");
	scanf("%d", &test->y_dep);
	printf("Colonne (d�part) :\n");
	scanf("%d", &test->x_dep);

    //demande de la position d'arriv�e du bushi � d�placer
	printf("O� voulez-vous d�placer votre Bushi ?\n");
	printf("Ligne (d�part) :\n");
	scanf("%d", &test->y_arr);
	printf("Colonne (d�part) :\n");
	scanf("%d", &test->x_arr);
}
