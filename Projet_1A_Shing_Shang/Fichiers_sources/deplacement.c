//IMPORTATION DES BIBLIOTHEQUES
#include "structures.h"
#include "deplacement.h"


//FONCTION DEMANDE DE DEPLACEMENT DU BUSHI (POSITION + TYPE)

void change_bushis(deplacement move[MAX_SAUTS], case_pla plateau[HAU_PLA][LAR_PLA])
{
 //####  comment ####
 //cette fonction déplace le bushis, elle déplace les informations de la case de départ a la case d'arrivé si les déplacements sont bon,
 //

 //variable tmp qui permet l'échange :
 case_pla tmp;
 
 //échange :
 tmp=plateau[move[0].y_arr][move[0].x_arr];
 plateau[move[0].y_arr][move[0].x_arr]=plateau[move[0].y_dep][move[0].x_dep];
 plateau[move[0].y_dep][move[0].x_dep]=tmp;

}

//##########################################################################################################################################

void retirer_bushis(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move[MAX_SAUTS])
{
 //####  Comment  ####
 //cette fontion enlève les pions mangés :
 //

 //variable :
 int moy_y, moy_x;
 
 //détermination des coordonées :
 moy_y=(move[0].y_dep+move[0].y_arr)/2;
 moy_x=(move[0].x_dep+move[0].x_arr)/2;

 plateau[moy_y][moy_x].bushis='o';
 plateau[moy_y][moy_x].non_case=0;
 plateau[moy_y][moy_x].vide=1;
 plateau[moy_y][moy_x].couleur=0;
}





