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
 //cette fonction commence par demander les coordonnées de déplacement puis lances les bonnes verifications et lance la fonction qui deplace le bushis
 //
 
 //variables
 int res_deplacement;

 //lancement de la demande :
 boucle_entre_correcte(move, plateau);

 //lancement la fonction qui verrifie que les déplacements :
 res_deplacement=choix_singe(*move);

 //si les deux sont ok alors on peut lancer le déplacement du bushis :
 if (res_deplacement==1)
 {
  change_bushis(*move,plateau);
 }
 else
 {
  printf("C'est pas bon");
 }
}

//#############################################################################################################################################

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

//############################################################################################################################################

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

//##############################################################################################################################################
//########################################################   VERIFS SINGES   ###################################################################
//##############################################################################################################################################

int choix_singe(deplacement move)
{
 int res;
 res=verif_singe(move);

 //le return si res==0 alors pas bon / si res==1 ok
 return res;
}

//##############################################################################################################################################

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

//##############################################################################################################################################

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

//##############################################################################################################################################

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

//##############################################################################################################################################

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

//##############################################################################################################################################

int verif_arrive(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA])
{
 //#### comment ####
 //cette fonction permet de verifier que la case d'arrivé est bien vide
 //
 
 //variables :
 int res;

 //verif :
 if(plateau[move.x_arr][move.y_arr].vide==1)
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



