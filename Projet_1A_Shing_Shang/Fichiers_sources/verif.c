//dans ce fichier on essayer de faire une verif de déplacement :
#include "header.h"



//##############################################################################################################################################

void boucle_entre_correcte(deplacement *move, case_pla plateau[HAU_PLA][LAR_PLA])
{
 // ### comment ###
 //Cette fonction demande les déplacements voulue par le joueur jusqu'a ce qu'ils soient correcte
 // 

 //variables :
 

 //lancement de la fonction qui demande les déplacement dans une boucle while :
 do
 {
  demande(move);
  res=verif_bushis(*demande, plateau);
 } while (res==0);

 //if(res==0)
 //{
  //printf("La case que vous avez saisie n'est pas en correlation avec le bushi que vous avez saisie\n");
 //}

}

//##############################################################################################################################################

void choix_verif(deplacement *demande, case_pla plateau[HAU_PLA][LAR_PLA])
{
 //#### comment ####
 //cette fonction commence par demander les coordonnées de déplacement puis lances les bonnes verifications
 //
 
 //variables
 int res;

 //lancement de la demande :
 boucle_entre_correcte(&demande, plateau);

 //lancement la fonction qui verrifie que le Bushis indiqué par le joueur est bien le bushis qui est dans la case :
 res=verif_bushis(demande, plateau);

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
 }
 else
 {
  res=0;
 }

 //le return si res==0 alors pas bon / si res==1 ok
 return res;
}
