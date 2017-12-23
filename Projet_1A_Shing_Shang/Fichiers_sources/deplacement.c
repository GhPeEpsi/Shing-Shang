//IMPORTATION DES BIBLIOTHEQUES
#include "structures.h"
#include "deplacement.h"


//FONCTION DEMANDE DE DEPLACEMENT DU BUSHI (POSITION + TYPE)

void change_bushis(deplacement move, case_pla plateau[HAU_PLA][LAR_PLA])
{
 //####  comment ####
 //cette fonction déplace le bushis, elle déplace les informations de la case de départ a la case d'arrivé si les déplacements sont bon,
 //

 //variable tmp qui permet l'échange :
 case_pla tmp;
 
 //échange :
 tmp=plateau[move.y_arr][move.x_arr];
 plateau[move.y_arr][move.x_arr]=plateau[move.y_dep][move.x_dep];
 plateau[move.y_dep][move.x_dep]=tmp;

}
