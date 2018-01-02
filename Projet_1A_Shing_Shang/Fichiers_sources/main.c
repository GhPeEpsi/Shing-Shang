#include "structures.h"
#include "affichage.h"
#include "verif.h"
#include "initialisation.h"
#include "demande.h"


void main()
{

 //###### comments #######
 //Cette fonction est le début ce sera celle qui sera lancée
 //

 //création des variables, pseudo, plateau, ... :
 perso pseudo1, pseudo2;
 int tmp, res;
 case_pla plateau[HAU_PLA][LAR_PLA];
 deplacement move;
 bushi lion, dragon, singe;


 //on commence par afficher l'entête :
 entete();

 //ensuite on remplit le plateau et les bushis :
 remp_pla(plateau);
 rempli_singe(&singe);
 rempli_lion(&lion);
 rempli_dragon(&dragon); 

 //on demande les noms des joueurs :
 entre_joueur(1, &pseudo1);
 entre_joueur(2, &pseudo2); 
 
 //Demande de qui commence :
 res=qui_commence(&pseudo1, &pseudo2); //sert a rien pour le moment
 
 
 //on demande si les joueurs veulent voir les règles :
 vouloir_regles();

 //puis on lance la partie :
 deroulement(plateau, &move, singe, lion, dragon, &pseudo1, &pseudo2);
 
}
