//IMPORTATION DES BIBLIOTHEQUES
#include "structures.h"
#include "deplacement.h"


//FONCTION DEMANDE DE DEPLACEMENT DU BUSHI (POSITION + TYPE)

void change_bushis(deplacement move[MAX_SAUTS], case_pla plateau[HAU_PLA][LAR_PLA], comp_der compteur)
{
 //####  comment ####
 //cette fonction déplace le bushis, elle déplace les informations de la case de départ a la case d'arrivé si les déplacements sont bon,
 //

 //printf("debug : change_bushis"); //debug 

 //variable tmp qui permet l'échange :
 case_pla tmp;
 
 //échange :
 tmp=plateau[move[compteur.nb_sauts].y_arr][move[compteur.nb_sauts].x_arr];
 plateau[move[compteur.nb_sauts].y_arr][move[compteur.nb_sauts].x_arr]=plateau[move[compteur.nb_sauts].y_dep][move[compteur.nb_sauts].x_dep];
 plateau[move[compteur.nb_sauts].y_dep][move[compteur.nb_sauts].x_dep]=tmp;

 

}

//##########################################################################################################################################

void retirer_bushis(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move[MAX_SAUTS], comp_der compteur)
{
 //####  Comment  ####
 //cette fontion enlève les pions mangés :
 //

 //variable :
 int moy_y, moy_x, j;
 
 //détermination du bushis a enlever :
 j=compteur.bushis_enemi_saute[compteur.nb_bushis_enemi_saute];

 //détermination des coordonées :
 moy_y=(move[j].y_dep+move[j].y_arr)/2;
 moy_x=(move[j].x_dep+move[j].x_arr)/2;

 plateau[moy_y][moy_x].bushis='o';
 plateau[moy_y][moy_x].non_case=0;
 plateau[moy_y][moy_x].vide=1;
 plateau[moy_y][moy_x].couleur=0;
}





