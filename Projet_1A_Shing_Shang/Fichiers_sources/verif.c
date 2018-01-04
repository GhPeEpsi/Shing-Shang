//dans ce fichier on fait les verifs de déplacement :
#include "structures.h"
#include "verif.h"
#include "demande.h"
#include "initialisation.h"
#include "deplacement.h"

//###########################################################################################################################################
//##################################################   LANCEMENT DE TOUTES LES VERIFS  ######################################################
//###########################################################################################################################################


void choix_verif(deplacement move[MAX_SAUTS], case_pla plateau[HAU_PLA][LAR_PLA], bushi singe, bushi lion, bushi dragon, perso *pseudo1, perso *pseudo2, int j)
{
 //#### comment ####
 //cette fonction commence par demander les coordonnées de déplacement puis lances les bonnes verifications et lance la fonction qui deplace
 //le bushis
 //
 
 //variables
 int res_deplacement, res_bonne_equipe;
 char bushi_deplace;

 //lancement de la demande :
 //lancement la fonction qui verrifie que les déplacements et on recommence tant que c'est pas bon !
 do
 {
  bushi_deplace=boucle_entre_correcte(move, plateau, pseudo1, pseudo2, j);
  res_deplacement=choix_bushi(move, plateau, bushi_deplace, singe, lion, dragon);
  res_bonne_equipe=verif_bonne_equipe(move, plateau);

  if(res_deplacement==0)
  {
    printf("\nVous ne pouvez pas effectuer ce mouvement !!\n\n");   
  }

  if(res_bonne_equipe==0)
  {
    printf("\nHum vous vous êtes trompé d'équipe !!\n\n");   
  }

 }while((res_deplacement==0)||(res_bonne_equipe==0));

 //printf("\n\nLe Bushi déplacé est le suivant : %c\n\n",bushi_deplace); debug

 //si les deux sont ok alors on peut lancer le déplacement du bushis :
 change_bushis(move,plateau);


}

//##########################################################################################################################################

char boucle_entre_correcte(deplacement move[MAX_SAUTS], case_pla plateau[HAU_PLA][LAR_PLA], perso *pseudo1, perso *pseudo2, int j)
{
 // ### comment ###
 //Cette fonction demande les déplacements voulue par le joueur jusqu'a ce qu'ils soient correcte
 // 

 //variables :
 int res_bushi, res_vide;
 char res;

 //lancement de la fonction qui demande les déplacement dans une boucle while :
 do
 {
   res=choix_demande_dep(move, j);
   
            //debug
     printf("\nDebug tour %d :\n", j);
     printf("%c\n",move[j].bushi);
     printf("x: %d\n",move[j].x_dep);
     printf("y: %d\n",move[j].y_dep);

   qui_peut_jouer(move, pseudo1, pseudo2);
   res_bushi=verif_bushis(move, plateau);
   res_vide=verif_arrive(move, plateau);

   //attribution de qui peut jouer :


   if(res_bushi==0)
   {
    printf("\nLa case de départ que vous avez saisie n'est pas en correlation avec le bushi que vous avez saisie\n\n");
   }

   if(res_vide==0)
   {
    printf("\nLa case d'arrivé est déjà rempli\n\n");
   }

 } while ((res_bushi==0)||(res_vide==0));

 //retour du bushis qui doit se déplacer :
 return res;
}

//###########################################################################################################################################

int verif_bushis(deplacement test[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA])
{
 //variables :
 int res, i, j;
 char caract_bushi;

 //transformations des variables de positions :
 i=test[0].y_dep;
 j=test[0].x_dep;
 caract_bushi=plateau[i][j].bushis;

 //verification du Bushis :
 if(test[0].bushi==caract_bushi)
 {
  res=1;
 }
 else
 {
  res=0;
 }

 //le return si res==0 alors pas bon / si res==1 ok
 return res;
}

//###########################################################################################################################################
//########################################################   VERIFS DEPLACEMENT   ###########################################################
//###########################################################################################################################################

int choix_bushi(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], char bushi_deplace, bushi singe, bushi lion, bushi dragon)
{
 //#### comment ####
 //cette fonction permet de choisir pour quel bushi on veut voir les verifs
 //
 
 int res_deplacement;

 if(bushi_deplace=='S')
 {
  res_deplacement=choix_singe(move, plateau, singe);
 }
 
 if(bushi_deplace=='L')
 {
  res_deplacement=choix_singe(move, plateau, lion);
 }

 if(bushi_deplace=='D')
 {
  res_deplacement=choix_singe(move, plateau, dragon);
 }

 return res_deplacement;
}

//###########################################################################################################################################

int choix_singe(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], bushi bushi_dep)
{
 //variables :
 int res, diff_x, diff_y;

 //printf("\n\n Je suis dans choix_singe le bushis que je deplace est : %c\n\n",bushi_dep.bushi); debug

 //calcul des différences
 diff_x=fabs(move[0].x_dep-move[0].x_arr);
 diff_y=fabs(move[0].y_dep-move[0].y_arr);
 
 //choix du type de verif (saut ou simple)
 if((diff_x==1)||(diff_y==1))
 {
  //printf("choix_singe : 1\n"); debug
  res=verif_singe(move, bushi_dep);
 }
 else 
 {
  //printf("choix_singe : 2\n"); debug
  if(trouver_bushi_saute(move, plateau)=='o')
  {
   //printf("choix_singe : 3\n"); debug
   res=verif_singe(move, bushi_dep);
  }
  else
  {
   //printf("choix_singe : 4\n"); debug
   res=verif_sauter(plateau, move, bushi_dep);
  }
 }

 //le return si res==0 alors pas bon / si res==1 ok
 return res;
}

//###########################################################################################################################################

int verif_singe(deplacement move[MAX_SAUTS], bushi bushi_deplace)
{
 //declaration des variables :
 int diff_x, diff_y, res;
 
 //calcul des differences avant le if pour simplifier l'écriture
 diff_x=fabs(move[0].x_dep-move[0].x_arr);
 diff_y=fabs(move[0].y_dep-move[0].y_arr);
 

 if((diff_x!=0)&&(diff_y!=0))      //si les absisses et les ordonnée changent alors le deplacement est 
 {                                 //en diagonal ou faux donc debut de la fonction diagonal
   res=singe_diagonal(move, bushi_deplace);
 }
 else
 {
   if(diff_y==0)     //sinon si les ordonnées sont les même au depart et a l'arrivé alors le deplacement est horizontale
   {
    res=singe_horizontal(move, bushi_deplace);
   }
   else
   {
    res=singe_vertical(move, bushi_deplace);   //et puis si il n'y a rien d'enclenché au dessus c'est un déplacement vertical ou c'est mauvé ...
   }
 }
 
 //retourner le resultat a la fonction principal pr indiquer si c'est correct :
 return res;
}

//###########################################################################################################################################

int singe_horizontal(deplacement singe[MAX_SAUTS], bushi bushi_deplace) //dans le cas où l'on ne mange pas de bushis
{
 //declaration des variables :
 int verif, res, dep_min, dep_max;

 //calcul de la verif : 
 verif=singe[0].x_dep-singe[0].x_arr;
 
 //calcul longueur de déplacement :
 dep_min=bushi_deplace.nb_saut_min;
 dep_max=bushi_deplace.nb_saut_max;

 //verifications
 if((verif==dep_max)||(verif==-dep_max)||(verif==-dep_min)||(verif==dep_min))
 {
  res=1; //res booleen donc si res=1 le déplacement est correct
 }
 else
 {
  res=0; //sinon il est incorrect donc 0
 }

 //return qui renvoie si ca a fonctionné ou non
 return res;
 
}

//###########################################################################################################################################

int singe_vertical(deplacement singe[MAX_SAUTS], bushi bushi_deplace)
{
 //declaration des variables :
 int verif, res, dep_min, dep_max;

 //calcul de la verif : 
 verif=singe[0].y_dep-singe[0].y_arr;

 //calcul longueur de déplacement :
 dep_min=bushi_deplace.nb_saut_min;
 dep_max=bushi_deplace.nb_saut_max;

 //verifications
 if((verif==dep_max)||(verif==-dep_max)||(verif==-dep_min)||(verif==dep_min))
 {
  res=1; //res booleen donc si res=1 le déplacement est correct
 }
 else
 {
  res=0; //sinon il est incorrect donc 0
 }

 //return qui renvoie si ca a fonctionné ou non
 return res;
 
 
}

//###########################################################################################################################################

int singe_diagonal(deplacement singe[MAX_SAUTS], bushi bushi_deplace)
{
 //declaration des variables :
 int verif_hor, verif_ver, res, verif, dep_min, dep_max;

 //calcul de la verif : 
 verif_hor=singe[0].x_dep-singe[0].x_arr;
 verif_ver=singe[0].y_dep-singe[0].y_arr;

 //calcul longueur de déplacement :
 dep_min=bushi_deplace.nb_saut_min;
 dep_max=bushi_deplace.nb_saut_max;

 //calcul du bouleen verif
 verif=(((verif_hor==dep_min)||(verif_hor==-dep_min))&&((verif_ver==dep_min)||(verif_ver==-dep_min)))||(((verif_hor==dep_max)||(verif_hor==-dep_max))&&((verif_ver==dep_max)||(verif_ver==-dep_max)));
 //le singe si toutes les cases sont vides peut ce déplacer horizontalement verticalement ou horizontalement d'une ou deux cases

 //verifications
 if (verif)
 {                  
  res=1; //res booleen donc si res=1 le déplacement est correct
 }
 else
 {
  res=0; //sinon il est incorrect donc 0
 }

 //return qui renvoie si ca a fonctionné ou non
 return res;
}

//###########################################################################################################################################

int verif_arrive(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA])
{
 //#### comment ####
 //cette fonction permet de verifier que la case d'arrivé est bien vide
 //
 
 //variables :
 int res;

 //verif :
 if(plateau[move[0].y_arr][move[0].x_arr].vide==1)
 {
  res=1;
 }
 else
 {
 res=0;
 }
 
 //retour
 return res;
}

//###########################################################################################################################################

int verif_sauter(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move[MAX_SAUTS], bushi bushi_deplace)
{
 //#### comment ####
 //cette fonction verifie que l'on peut sauter un bushis 
 //
 
 printf("pion sauté : verif_sauter\n ");  //debug 

 //variables :
 int res,res_arrive, res_bushi_inf;
 
 //verifications de la case d'arrivé :
 res_arrive=verif_arrive(move, plateau);

 //verifications que le bushi sauté est inférieure :
 res_bushi_inf=verif_bushi_inf(move, plateau);
 
 if((res_arrive==1)&&(res_bushi_inf==1))
 {
  res=1;
  move[0].saute=1;
  move[0].nb_sauts++;
 }
 else
 {
  res=0;
  move[0].saute=0;
 }

 //lancement de la fonction qui verifie si le pion sauté est allié ou ennemi :
 manger(plateau, move);
 
 return res;
}

//##########################################################################################################################################

void manger(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move[MAX_SAUTS])
{
 //####  Comment  ####
 //cette fonction regarde si le pion sauté est enemie, si il est enemi alors on l'enléve :
 
 //variables :
 char saute;

 //printf("Debug je suis dans la fonction manger");  debug

 //détermination du bushi sauté
 saute=trouver_bushi_saute(move, plateau);

 //traitement :
 if(plateau[move[0].y_dep][move[0].x_dep].couleur!=plateau[(move[0].y_dep+move[0].y_arr)/2][(move[0].x_dep+move[0].x_arr)/2].couleur)
 {
  retirer_bushis(plateau, move);
 }

}

//##########################################################################################################################################

int verif_bushi_inf(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA])
{
 //#### comment ####
 //cette fonction verifie que le pion sauté est bien inférieure ou égal au pion sauteur :

 //variables :
 int res; 
 char sauteur, saute;

 //printf("pion sauté : verif_bushi_inf\n");  //debug 

 //definition des variables char
 sauteur=plateau[move[0].y_dep][move[0].x_dep].bushis;
 saute=trouver_bushi_saute(move, plateau);

 //
 if(sauteur<=saute)  //les caractéres sont rangés par ordre alphabétique (a plus petit ; z plus grand, D L S sont rangées dans l'ordre 
 {                   //inverse d'où le inférieur ou égal ....
  res=1;
  //printf("youpi");  //debug
 }
 else
 {
  res=0;
  //printf("non");  //debug
 }

 return res;
}

//##########################################################################################################################################

char trouver_bushi_saute(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA])
{
 //#### comment ####
 //Cette fonction retourne le bushis sauté
 
 //variable :
 char res;
 int moy_y,moy_x;

 //printf("pion sauté : trouver_bushi_saute\n");  //debug 

 //calcul des cordonées :
 moy_y=(move[0].y_dep+move[0].y_arr)/2;
 moy_x=(move[0].x_dep+move[0].x_arr)/2; //moyenne des déplacements qui doit donner les cordonées du bushis du milieu

 //attribution :
 res=plateau[moy_y][moy_x].bushis;

 //return :
 return res;

}

//##########################################################################################################################################

int verif_bonne_equipe(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA])
{
 int res;
 
 if(move[0].joueur==plateau[move[0].y_dep][move[0].x_dep].couleur)
 {
  res=1;
 }
 else
 {
  res=0;
 }


 return res;
}


