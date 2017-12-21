//IMPORTATION DES BIBLIOTHEQUES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_NOM 30


//DEFINITION DES STRUCTURES
typedef struct
{
	char nom[MAX_NOM];
	char equipe[MAX_NOM];
	int numero;
}perso;


//DEFINITIONS DES PROTOTYPES DE FONCTIONS
int main();
int demande();


//FONCTION MAIN - LANCEMENT DES FONCTIONS
int main()
{
	demande();

	return 0;
}



int demande()
{
	//déclaration des variables
	int choix;
	perso J1, J2;

	//choix des joueurs J1 et J2
	printf("Joueur 1 : Entrez votre pseudo : "); scanf("%s", &J1.nom);
	printf("Joueur 2 : Entrez votre pseudo : "); scanf("%s", &J2.nom);
	printf("%s", J1.nom);
	printf("%s", J2.nom);
}
