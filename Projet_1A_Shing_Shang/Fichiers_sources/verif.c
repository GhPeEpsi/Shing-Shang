//dans ce fichier on essayer de faire une verif de déplacement :
#include "structures.h"
#include "verif.h"
#include "demande.h"
#include "deplacement.h"

//###########################################################################################################################################
//##################################################   LANCEMENT DE TOUTES LES VERIFS  ######################################################
//###########################################################################################################################################


void choix_verif(deplacement *move, case_pla plateau[HAU_PLA][LAR_PLA])
{
 //#### comment ####
 //cette fonction commence par demander les coordonnées de déplacement puis lances les bonnes verifications et lance la fonction qui deplace
 //le bushis
 //
 
 //variables
 int res_deplacement;

 //lancement de la demande :
 //lancement la fonction qui verrifie que les déplacements et on recommence tant que c'est pas bon !
 do
 {
  boucle_entre_correcte(move, plateau);
  res_deplacement=choix_singe(*move, plateau);
 }while (res_deplacement==0);

 //si les deux sont ok alors on peut lancer le déplacement du bushis :
 change_bushis(*move,plateau);


}

//##########################################################################################################################################

void boucle_entre_correcte(deplacement *move, case_pla plateau[HAU_PLA][LAR_PLA])
{
 // ### comment ###
 //Cette fonction demande les déplacements voulue par le joueur jusqu'a ce qu'ils soient correcte
 // 

 //variables :
 int res_bushi, res_vide;

 //lancement de la fonction qui demande les déplacement dans une boucle while :
 do
 {
   demande_dep(move);
   res_bushi=verif_bushis(*move, plateau);
   res_vide=verif_arrive(*move, plateau);

   if(res_bushi==0)
   {
    printf("\nLa case de départ que vous avez saisie n'est pas en correlation avec le bushi que vous avez saisie\n\n");
   }

   if(res_vide==0)
   {
    printf("\nLa case d'arrivé est déjà rempli\n\n");
   }

 } while ((res_bushi==0)||(res_vide==0));

}

//###########################################################################################################################################

int verif_bushis(deplacement test, case_pla plateau[LAR_PLA][HAU_PLA])
{
 //variables :
 int res, i, j;
 char caract_bushi;

 //transformations des variables de positions :
 i=test.y_dep;
 j=test.x_dep;
 caract_bushi=plateau[i][j].bushis;

 //verification du Bushis :
 if(test.bushi==caract_bushi)
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
//########################################################   VERIFS SINGES   ################################################################
//###########################################################################################################################################

int choix_singe(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA])
{
 //variables :
 int res, diff_x, diff_y;

 //calcul des différences
 diff_x=fabs(move.x_dep-move.x_arr);
 diff_y=fabs(move.y_dep-move.y_arr);
 
 //choix du type de verif (saut ou simple)
 if((diff_x==1)||(diff_y==1))
 {
  printf("choix_singe : 1\n");
  res=verif_singe(move);
 }
 else 
 {
  printf("choix_singe : 2\n");
  if(trouver_bushi_saute(move, plateau)=='o')
  {
   printf("choix_singe : 3\n");
   res=verif_singe(move);
  }
  else
  {
   printf("choix_singe : 4\n");
   res=verif_sauter(plateau, move);
  }
 }

 //le return si res==0 alors pas bon / si res==1 ok
 return res;
}

//###########################################################################################################################################

int verif_singe(deplacement singe)
{
 //declaration des variables :
 int diff_x, diff_y, res;
 
 //calcul des differances avant le if pour simplifier l'écriture
 diff_x=fabs(singe.x_dep-singe.x_arr);
 diff_y=fabs(singe.y_dep-singe.y_arr);
 

 if((diff_x!=0)&&(diff_y!=0))      //si les absisses et les ordonnée changent alors le deplacement est 
 {                                 //en diagonal ou faux donc debut de la fonction diagonal
   res=singe_diagonal(singe);
 }
 else
 {
   if(diff_y==0)     //sinon si les ordonnées sont les même au depart et a l'arrivé alors le deplacement est horizontale
   {
    res=singe_horizontal(singe);
   }
   else
   {
    res=singe_vertical(singe);   //et puis si il n'y a rien d'enclenché au dessus c'est un déplacement vertical ou c'est mauvé ...
   }
 }
 
 //retourner le resultat a la fonction principal pr indiquer si c'est correct :
 return res;
}

//###########################################################################################################################################

int singe_horizontal(deplacement singe) //dans le cas où l'on ne mange pas de bushis
{
 //declaration des variables :
 int verif, res;

 //calcul de la verif : 
 verif=singe.x_dep-singe.x_arr;

 //verifications
 if((verif==2)||(verif==-2)||(verif==-1)||(verif==1))
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

int singe_vertical(deplacement singe)
{
 //declaration des variables :
 int verif, res;

 //calcul de la verif : 
 verif=singe.y_dep-singe.y_arr;

 //verifications
 if((verif==2)||(verif==-2)||(verif==-1)||(verif==1))
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

int singe_diagonal(deplacement singe)
{
 //declaration des variables :
 int verif_hor, verif_ver, res, verif;

 //calcul de la verif : 
 verif_hor=singe.x_dep-singe.x_arr;
 verif_ver=singe.y_dep-singe.y_arr;

 //calcul du bouleen verif
 verif=(((verif_hor==2)||(verif_hor==-2))&&((verif_ver==2)||(verif_ver==-2)))||(((verif_hor==1)||(verif_hor==-1))&&((verif_ver==1)||(verif_ver==-1))); 
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

int verif_arrive(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA])
{
 //#### comment ####
 //cette fonction permet de verifier que la case d'arrivé est bien vide
 //
 
 //variables :
 int res;

 //verif :
 if(plateau[move.y_arr][move.x_arr].vide==1)
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

int verif_sauter(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move)
{
 //#### comment ####
 //cette fonction verifie que l'on peut sauter un bushis 
 //
 
 //printf("pion sauté : verif_sauter\n ");  //debug 

 //variables :
 int res,res_arrive, res_bushi_inf;
 
 //verifications de la case d'arrivé :
 res_arrive=verif_arrive(move, plateau);

 //verifications que le bushi sauté est inférieure :
 res_bushi_inf=verif_bushi_inf(move, plateau);
 
 if((res_arrive==1)&&(res_bushi_inf==1))
 {
  res=1;
 }
 else
 {
  res=0;
 }

 return res;
}

//##########################################################################################################################################

int verif_bushi_inf(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA])
{
 //#### comment ####
 //cette fonction verifie que le pion sauté est bien inférieure ou égal au pion sauteur :

 //variables :
 int res; 
 char sauteur, saute;

 //printf("pion sauté : verif_bushi_inf\n");  //debug 

 //definition des variables char
 sauteur=plateau[move.y_dep][move.x_dep].bushis;
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

char trouver_bushi_saute(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA])
{
 //#### comment ####
 //Cette fonction retourne le bushis sauté
 
 //variable :
 char res;
 int moy_y,moy_x;

 //printf("pion sauté : trouver_bushi_saute\n");  //debug 

 //calcul des cordonées :
 moy_y=(move.y_dep+move.y_arr)/2;
 moy_x=(move.x_dep+move.x_arr)/2; //moyenne des déplacements qui doit donner les cordonées du bushis du milieu

 //attribution :
 res=plateau[moy_y][moy_x].bushis;

 //return :
 return res;

}












