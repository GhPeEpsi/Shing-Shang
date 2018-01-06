#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>


//Constantes :
//persos :
#define MAX_NOM 30

//plateau :
#define LAR_PLA 10
#define HAU_PLA 10

//couleur :
#define couleur(param) printf("\033[%sm",param)

//nb de sauts maxi :
#define MAX_SAUTS 100 


//DEFINITIONS DES STRUCTURES :
typedef struct //définit ce qu'il faut retenir pour faire un autre tour avec un autre bushis après shing-shang
{ 
 int droit;    //booléen qui indique si c'est un deuxiéme tour
 char bushi;   //type de bushi
 int pos_x;    //position du bushi en abscisse
 int pos_y;    //position du bushi en ordonnée
}autre_tour;

typedef struct
{
 int nb_sauts;     //définit combien de saut a effectué le bushis pendant le tour
 int shing_shang;
 int bushis_enemi_saute[MAX_SAUTS]; //permet de stocker les bushis enemies sautées
 int nb_bushis_enemi_saute;   //permet de retrouver le dernier bushis ennemis sauté dans le tableau
}comp_der; 

typedef struct  //définit les informations nécessaires aux déplacements
{
 char bushi;      //definit le type de bushis pour les verifs
 int x_dep;       //definit la position en absice du départ
 int y_dep;       //définit la position en ordonnée du depart
 int x_arr;       //definit la position en absice de l'arrivée
 int y_arr;       //définit la position en ordonnée de l'&rrivée
 int joueur;      //définit le joueur qui doit jouer
 int tour;        //définit le n° du tour
 int saute;       //définit si le bushis a sauté pendant ce tour
 int shing_shang; //définit si il y a shing shang (booléen)
}deplacement;

typedef struct  //définit tout ce que l'ont doit savoir a propos des joueurs
{
 char nom[MAX_NOM];
 char equipe[MAX_NOM];
 int numero;
 int couleur;
}perso;

typedef struct  //cette structure définit une case et toutes les informations dont on a besoin pour creer un plateau
{
 int non_case;  //booléen qui permet de savoir si la case fait parti du plateau ou non (pour les 16 cases qui forment les coins)
 int vide;      //booléen qui permet de tester si la case est vide
 char bushis;   //variable qui permet de savoir si ce qui est dans la case est un dragon D lion L ou singe S
 int couleur;   //permet de savoir si c'est un bushis de l'équipe rouge ou noir
}case_pla;                           //pas d'équipe=0 ; noir=1 ; rouge=2 ; vert(portail)=3

typedef struct
{
 int nb_saut_max;  //permet de connaitre le nombre de saut faisable au max par le bushi
 int nb_saut_min;  //permet de connaitre le nombre de saut faisable au min par le bushi
 char bushi;       //permet de connaitre le type de bushi
}bushi;

#endif
