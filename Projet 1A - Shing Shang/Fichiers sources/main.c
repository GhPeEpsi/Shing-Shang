#include "header.h"

void main()
{

 //###### coment #######
 //Cette fonction est le début ce sera celle qui sera lancé
 //

 //creation des variables, pseudo, plateau, ... :
 perso pseudo1, pseudo2;
 int tmp;
 case_pla plateau[HAU_PLA][LAR_PLA];
 deplacement move;

 //on commence par afficher l'entéte :
 //entete();

 remp_pla(plateau);
 aff_pla(plateau);

 //lancement des demandes de jeu :
 demande(&move);

 //lancement des verifs
 res=choix_verif(move, plateau);
 printf("resultat : %d",res);
 //choix_singe(move, plateau);
}
