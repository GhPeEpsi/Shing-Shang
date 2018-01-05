//ce fichier contient toutes les fonctions relatives à l'affichage :
#include "structures.h"
#include "affichage.h"


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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void aff_pla(case_pla plateau[HAU_PLA][LAR_PLA])
{
 //#### coment ####
 //cette fonction permet l'affichage d'un plateau 

 //variables :
 int i, j;

 printf("\n");   //sert a espacer les plateaux

 //affichage d'une ligne de chiffres qui permet de localiser les cases :
 printf("  "); //permet d'espacer la ligne pour laisser de la place a la ligne vertical.
 for(i=0 ; i<LAR_PLA ; i++)
 {
  printf(" %d",i);
 }

 printf("\n"); printf("\n");   //sert a espacer les plateaux et la ligne
 
 //affichage:
 for(i=0 ; i<HAU_PLA ; i++)
 {
  printf("%d ",i);   //permet d'afficher une ligne de chiffre vertical qui permet de reperrer les bushis.
  for(j=0 ; j<LAR_PLA ; j++)
  {
   if((plateau[i][j].non_case==1)) //premiére partie permets de selectionner les 16 cases des coins la deuxieme pour mettre de
   {                                             //l'espace dans le tableau   
    printf("  ");                                 //permet d'espacer le tableau pour qu'il paraisse plus carré (même si c'en est pas un ...)
   }
   else
   {
    aff_couleur_bushis(plateau[i][j].couleur, plateau[i][j].bushis);   //affiche les P, D, L, S
   }    
  }
  printf("\n");   //sert a passer à la ligne
 }


 printf("\n");   //sert à espacer les plateaux
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void aff_couleur_bushis(int couleur, char bush)  //appellé par aff_couleur_bushis(couleur.plateau[i][j], char bush)
{
 //#### coment ####
 //cette fonction permet l'affichage d'une case ainsi que sa couleur 
 

 if(couleur==0)
 {
  printf(" %c",bush);
 }

 if(couleur==31)
 {
  couleur("31");
  printf(" %c",bush);
  couleur("0");
 }

 if(couleur==34)
 {
  couleur("34");
  printf(" %c",bush);
  couleur("0");
 }

 if(couleur==32)
 {
  couleur("32");
  printf(" %c",bush);
  couleur("0");
 }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ecrire_pseudo(perso pseudo)
{
 //###### coment #####
 //cette fonction sert a écrire le pseudo 1 :
 // !!!! ATTENTION PAS DE RETOUR A LA LIGNE !!!!
 //


 //ecriture
 printf("%s",pseudo.nom);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void aff_qui_joue(perso joueur, int nb)
{
 if(joueur.numero==1)
 {
  printf("\n\nTour %d c'est a %s de jouer avec les Bleus! \n",nb+1, joueur.nom);
 }
 else
 {
  printf("\n\nTour %d c'est a %s de jouer avec les Rouges !\n",nb+1, joueur.nom);
 }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void aff_rejouer(deplacement move[MAX_SAUTS], int j)
{
 if(move[j].saute==1)
 {
  printf("\nVous pouvez refaire un saut avec le même bushis !\n");
 }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void aff_vouloir_rejouer()
{
 printf("\nVoulez vous refaire un saut avec le même bushis ? 1 si oui ; 2 si non => \n");
}






