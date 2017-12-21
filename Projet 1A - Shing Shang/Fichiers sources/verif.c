//dans ce fichier on essayer de faire une verif de déplacement :
#include "header.h"



//##############################################################################################################################################

int choix_verif(deplacement demande, case_pla plateau)
{
 //variables
 int res;

 //lancement de la premiére fonction qui verrifie que le Bushis indiqué par le jour est bien le bushis qui est dans la case :
 res=verif_bushis(demande, plateau);

 return res;
}

//##############################################################################################################################################

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
  #ifdef DEBUG
   printf("%d",res);
  #endif
 }
 else
 {
  res=0;
 }

 //le return si res==0 alors pas bon / si res==1 ok
}
