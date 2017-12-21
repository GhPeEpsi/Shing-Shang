//ce fichier contient toutes les fonctions relatives à l'affichage :
#include "header.h"


void vouloir_regles()
{
 //##### Coment ####
 //cette fonction permet de demander au joueur si il veut consulter les régles

 //variables :
 int rep=0;

 //demande au joueur il ne doit pouvoir rentrer que 1 ou 0 sinon il ne peut pas continuer
 do
 {
  printf("\nVoulez vous consulter les régles ? entrez 1 si oui ; 0 si non =>");
  scanf("%d",&rep);
  while(getchar() !='\n');  //le jeux ne doit pas plenter si il entre des lettres donc vidage de buffer
 }
 while ((rep!=1) && (rep!=0));

 //affichage desregles si besoin
 if(rep==1)
 {
  aff_reg();
 }

}


//##############################################################################################################################################

void aff_reg()
{
 //#### coment ####
 // Cette Fonction permet d'afficher les règles :

 printf("Pour Jouer au jeu du Shing Shang Vous devez êtres 2\nLe but est de placer les dragons materialisés par un D sur les portails adverse (cases en vert).\nPour cela vous avez une armée de 12 Bushis.\nCette armée est composée de 3 groupes de Bushis : 2 Dragons, 4 Lions et 6 Singes.\nChaque joueur place son armée dans les coins du damier.\nAlors la partie peut commencer\n\nChaque Bushi à un déplacement particulier, ils peuvent tous se déplacer horizontalement, verticalement et en diagonal :\nLe singe peut se déplacer de 2 cases à chaque tour sans changer de direction\nLe lion peut se déplacer de 1 case à chaque tour sans changer de direction\nLe dragon peut se déplacer qu'en sautant par dessus d'autres bushis sans changer de direction\n\n");

 printf("Déroulement du jeu : Les joueurs jouent à tour de rôle. Lors de son tour de jeu, un joueur doit déplacer l’un de ses Bushis de deux façons :\n— Glisser vers une case suivante vide horizontalement, verticalement ou en diagonal, aussi bien en avant qu’en arrière.\n— Sauter par dessus un Bushi si celui-ci est de la même grandeur ou plus petit que le sauteur. \nPour pouvoir sauter, le Bushi doit se trouver sur une case contiguë à une case occupée par un Bushi rouge ou noire, il peut sauter la pièce, verticalement, horizontalement ou en diagonale, à condition que la case suivante soit vide. On peut enchaîner plusieurs sauts au cours d’un même tour. Cet enchaînement de sauts s’appel un Shing Shang.\n\n");
}

//##############################################################################################################################################

void entete()
{
 //###### Coment #####
 //cette fonction sert à afficher l'entéte du jeu

 //affichage
 printf("\n			###############################################################################################\n			###############################################################################################\n			####                                                                                       ####\n			####                                  Jeu du Shing shang                                   ####\n			####                                  Nécessite 2 Joueurs                                  ####\n			####                                     Bon jeu !!!                                       ####\n			####                                                                                       ####\n			###############################################################################################\n			###############################################################################################\n");
 
}


//1/ générer exec gcc _______.c -o _______ -lm
//2/ lancer :     ./_______
