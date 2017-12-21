//dans ce fichier on essayer de faire une verif de déplacement :
#include "header.h"



//##############################################################################################################################################

int choix_singe(deplacement demande)
{
 int res;
 res=verif_singe(demande);
 if(res==1)
 {
  printf("Ok\n");
 }
 else
 {
  printf("Nop\n");
 }

 return 0;
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
 verif=(((verif_hor==2)||(verif_hor==-2))&&((verif_ver==2)||(verif_ver==-2)))||(((verif_hor==1)||(verif_hor==-1))&&((verif_ver==1)||(verif_ver==-1))); //le singe si toutes les cases sont vides peut ce déplacer horizontalement verticalement ou horizontalement d'une ou deux cases

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
