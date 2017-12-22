#include "header.h"
#include "structures.h"

void main()
{

 //###### coment #######
 //Cette fonction est le début ce sera celle qui sera lancé
 //

 //salut je fais un test (Bastien)

 //creation des variables, pseudo, plateau, ... :
 perso pseudo1, pseudo2;
 int tmp, res	;
 case_pla plateau[HAU_PLA][LAR_PLA];
 deplacement move;
 printf("salut");

 //on commence par afficher l'entéte :
 //entete();

 remp_pla(plateau);
 aff_pla(plateau);

 //lancement des demandes de jeu :

 //lancement des verifs
 choix_verif(&move, plateau);

 //choix_singe(move, plateau);
}
