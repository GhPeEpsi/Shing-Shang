//IMPORTATION DES BIBLIOTECH :
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



//Constantes :
//persos :
#define MAX_NOM 30

//plateau :
#define LAR_PLA 10
#define HAU_PLA 10

//couleur :
#define couleur(param) printf("\033[%sm",param)



//DEFINITIONS DES STRUCTURES :
typedef struct  //définit les informations nécessaires aux déplacements
{
 char bushi;      //definit le type de bushis pour les verifs
 int x_dep;       //definit la position en absice du départ
 int y_dep;       //définit la position en ordonnée du depart
 int x_arr;       //definit la position en absice de l'arrivée
 int y_arr;       //définit la position en ordonnée de l'&rrivée
 int bush_mange;  //définit le nombre de bushis enemis mangé
}deplacement;

typedef struct  //définit tout ce que l'ont doit savoir a propos des joueurs
{
 char nom[MAX_NOM];
 char equipe[MAX_NOM];
 int numero;

}perso;

typedef struct  //cette structure définit une case et toutes les informations dont on a besoin pour creer un plateau
{
 int non_case; //booléen qui permet de savoir si la case fait parti du plateau ou non principalement pour les 16 cases qui forment les coins
 int vide; //booléen qui permet de tester si la case est vide
 char bushis; //variable qui permet de savoir si ce qui est dans la case est un dragon D lion L ou singe S
 int couleur;  //permet de savoir si c'est un bushis de l'équipe rouge ou noir
}case_pla;                           //pas d'équipe=0 ; noir=1 ; rouge=2 ; vert(portail)=3





//PROTOTYPES :
//affichage
void vouloir_regles();
void aff_reg();
void entete();
int ordre_jeu();
int demande();
int pile_face();

//déplacements
void demande(deplacement *test);

//persos :
void entre_joueur(int nb, perso *p);
void ecrire_pseudo(perso pseudo);

//plateau :
void remp_pla(case_pla plateau[HAU_PLA][LAR_PLA]);
void aff_pla(case_pla plateau[HAU_PLA][LAR_PLA]);
void aff_couleur_bushis(int couleur, char bush);

//deplacement singe :
int verif_singe(deplacement singe);
int singe_horizontal(deplacement singe);
int singe_vertical(deplacement singe);
int singe_diagonal(deplacement singe);
int choix_singe(deplacement demande);





