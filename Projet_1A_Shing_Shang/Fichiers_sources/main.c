#include "structures.h"
#include "affichage.h"
#include "verif.h"
#include "initialisation.h"
#include "demande.h"


void main()
{

 //###### coment #######
 //Cette fonction est le début ce sera celle qui sera lancé
 //

 //creation des variables, pseudo, plateau, ... :
 perso pseudo1, pseudo2;
 int tmp, res	;
 case_pla plateau[HAU_PLA][LAR_PLA];
 deplacement move;


 //on commence par afficher l'entéte :
 entete();

 //ensuite on remplit le plateau :
 remp_pla(plateau);

 //on demande les noms des joueurs :
 entre_joueur(1, &pseudo1);
 entre_joueur(2, &pseudo2); 
 
 //Demande de qui commence :
 res=qui_commence(&pseudo1, &pseudo2);
 
 //on demande si les joueurs veulent voire les régles :
 vouloir_regles();

 //puis on lance la partie :
 deroulement(plateau, &move);
 
}
