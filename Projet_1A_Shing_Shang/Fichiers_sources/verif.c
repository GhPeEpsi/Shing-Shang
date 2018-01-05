//dans ce fichier on fait les verifs de déplacement :
#include "structures.h"
#include "verif.h"
#include "demande.h"
#include "initialisation.h"
#include "deplacement.h"

//###########################################################################################################################################
//##################################################   LANCEMENT DE TOUTES LES VERIFS  ######################################################
//###########################################################################################################################################


void choix_verif(deplacement move[MAX_SAUTS], case_pla plateau[HAU_PLA][LAR_PLA], bushi singe, bushi lion, bushi dragon, perso *pseudo1, perso *pseudo2, comp_der *compteur)
{
 //#### comment ####
 //cette fonction commence par demander les coordonnées de déplacement puis lances les bonnes verifications et lance la fonction qui deplace
 //le bushis
 //
 
 //variables
 int res_deplacement, res_bonne_equipe;

 //lancement de la demande :
 //lancement la fonction qui verrifie que les déplacements et on recommence tant que c'est pas bon !
 do
 {
  //printf("J dans la fonction choix_verif (ante boucle_entre-correct): %d\n",j); //debug
  boucle_entre_correcte(move, plateau, pseudo1, pseudo2, compteur);
  //printf("J dans la fonction choix_verif (post boucle_entre-correct): %d\n",j); //debug
  res_deplacement=choix_bushi(move, plateau, singe, lion, dragon, compteur);
  res_bonne_equipe=verif_bonne_equipe(move, plateau, compteur->nb_sauts);
  //printf("debug : choix_verif : res_bonne_equipe=%d\n",res_bonne_equipe); //debug 

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
 change_bushis(move, plateau, compteur);
}

//##########################################################################################################################################

char boucle_entre_correcte(deplacement move[MAX_SAUTS], case_pla plateau[HAU_PLA][LAR_PLA], perso *pseudo1, perso *pseudo2, der_comp *compteur)
{
 // ### comment ###
 //Cette fonction demande les déplacements voulue par le joueur jusqu'a ce qu'ils soient correcte
 // 

 //variables :
 int res_bushi, res_vide;

 //lancement de la fonction qui demande les déplacement dans une boucle while :
 do
 {
   //printf("J dans la fonction boucle_entre_correcte :%d\n",j); //debug
   choix_demande_dep(move, compteur->nb_sauts);
   
            
     //printf("\nDebug tour %d :\n", j); //debug
     //printf("%c\n",move[j].bushi); //debug
     //printf("x: %d\n",move[j].x_dep); //debug
     //printf("y: %d\n",move[j].y_dep); //debug

   qui_peut_jouer(move, pseudo1, pseudo2, compteur->nb_sauts);
   res_bushi=verif_bushis(move, plateau, compteur);
   res_vide=verif_arrive(move, plateau, compteur->nb_sauts);

   //attribution de qui peut jouer :


   if(res_bushi==0)
   {
    
    printf("\nLa case de départ que vous avez saisie n'est pas en correlation avec le bushi que vous avez saisie\n\n");
    //printf("%c\n",move[j].bushi);//debug
    //printf("x: %d\n",move[j].x_dep);//debug
    //printf("y: %d\n",move[j].y_dep);//debug
   }

   if(res_vide==0)
   {
    printf("\nLa case d'arrivé est déjà rempli\n\n");
   }

 } while ((res_bushi==0)||(res_vide==0));

}

//###########################################################################################################################################

int verif_bushis(deplacement test[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], comp_der *compteur)
{
 //variables :
 int res, i, j;
 char caract_bushi;

 //transformations des variables de positions :
 i=test[k].y_dep;
 j=test[k].x_dep;
 caract_bushi=plateau[i][j].bushis;

 //verification du Bushis :
 if(test[compteur->nb_sauts].bushi==caract_bushi)
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

int choix_bushi(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], bushi singe, bushi lion, bushi dragon, comp_der *compteur)
{
 //#### comment ####
 //cette fonction permet de choisir pour quel bushi on veut voir les verifs
 //

 //printf("debug : choix_bushi : bushi déplacé : %c\n\n",move[j].bushi);
 
 //variable :
 int res_deplacement;

 if(move[compteur->nb_sauts].bushi=='S')
 {
  //printf("debug : choix_bushi : S");
  res_deplacement=choix_singe(move, plateau, singe, compteur);
 }
 
 if(move[compteur->nb_sauts].bushi=='L')
 {
  res_deplacement=choix_singe(move, plateau, lion, compteur);
 }

 if(move[compteur->nb_sauts].bushi=='D')
 {
  res_deplacement=choix_singe(move, plateau, dragon, compteur);
 }

 //printf("debug : choix_bushi : res_d...=%d\n",res_deplacement); //debug
 return res_deplacement;
}

//###########################################################################################################################################

int choix_singe(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], bushi bushi_dep, comp_der *compteur)
{
 //variables :
 int res, diff_x, diff_y;

 //printf("\n\n Je suis dans choix_singe le bushis que je deplace est : %c\n\n",bushi_dep.bushi); //debug

 //calcul des différences
 diff_x=fabs(move[compteur->nb_sauts].x_dep-move[compteur->nb_sauts].x_arr);
 diff_y=fabs(move[compteur->nb_sauts].y_dep-move[compteur->nb_sauts].y_arr);
 
 //choix du type de verif (saut ou simple)
 if(move[compteur->nb_sauts-1].saute==1)
 {
  printf("debug : choix_singe move j-1==1");
  res=verif_sauter(plateau, move, bushi_dep, compteur);
 }
 else 
 {
      if((diff_x==1)||(diff_y==1))
      {
       res=verif_singe(move, bushi_dep);
       printf("debug : choix_singe dep normal 1 : res_...=%d\n",res); //debug
      }
      else 
      { 
           if(trouver_bushi_saute(move, plateau, compteur->nb_sauts)=='o')
           {
            res=verif_singe(move, bushi_dep);
            printf("debug : choix_singe dep_normal 2 : res_...=%d\n",res); //debug
           }
           else
           {
            res=verif_sauter(plateau, move, bushi_dep, compteur);
            printf("debug : choix_singe sauter : res_...=%d\n",res); //debug
           }
      }
  }

 //le return si res==0 alors pas bon / si res==1 ok
 //printf("debug : choix_singe total : res_...=%d\n",res); //debug
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

int verif_arrive(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], int j)
{
 //#### comment ####
 //cette fonction permet de verifier que la case d'arrivé est bien vide
 //
 
 //variables :
 int res;

 //verif :
 //printf("Verif_arrive j=%d\n",j); //debug
 //printf("Verif_arrive vide?=%d\n",plateau[move[j].y_arr][move[j].x_arr].vide); //debug
 if(plateau[move[j].y_arr][move[j].x_arr].vide==1)
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

int verif_sauter(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move[MAX_SAUTS], bushi bushi_deplace, comp_der *compteur)
{
 //#### comment ####
 //cette fonction verifie que l'on peut sauter un bushis 
 //
 
 //printf("debug : verif_sauter\n ");  //debug 

 //variables :
 int res,res_arrive, res_bushi_inf, ver, hor, verif;
 hor=fabs(move[compteur->nb_sauts].x_dep-move[compteur->nb_sauts].x_arr);
 ver=fabs(move[compteur->nb_sauts].y_dep-move[compteur->nb_sauts].y_arr);

 printf("debug : verif_sauter : hor=%d\n",hor);  //debug 
 printf("debug : verif_sauter : ver=%d\n",ver);  //debug 


 //verifications que le bushi sauté est inférieure :
 res_bushi_inf=verif_bushi_inf(move, plateau, compteur->nb_sauts);
 printf("debug : verif_sauter : bushi inf res_...=%d\n",res_bushi_inf); //debug

 //calcul du bit de verification :
 verif=((res_bushi_inf==1)&&(((hor==2)||(hor==0))&&((ver==2)||(ver==0))));
 printf("debug : verif_sauter : verif=%d\n",verif);  //debug 
 
 if(verif)
 {
  //printf("debug : verif_sauter : 1\n ");  //debug 
  res=1;
  move[compteur->nb_sauts].saute=1;
  //move[j].nb_sauts++;
 }
 else
 {
  res=0;
  move[compteur->nb_sauts].saute=0;
 }

 //lancement de la fonction qui verifie si le pion sauté est allié ou ennemi :
 manger(plateau, move, compteur->nb_sauts);
 
 
 //printf("debug : verif_sauter : res_...=%d\n",res); //debug
 return res;
}

//##########################################################################################################################################

void manger(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move[MAX_SAUTS], int j)
{
 //####  Comment  ####
 //cette fonction regarde si le pion sauté est enemie, si il est enemi alors on l'enléve :
 
 //variables :
 char saute;

 //printf("Debug : manger\n");  //debug

 //détermination du bushi sauté
 //printf("debug : manger : trouver_bushi_saute\n"); //debug
 saute=trouver_bushi_saute(move, plateau, j);

 //traitement :
 //printf("debug : manger\n"); //debug
 if(plateau[move[j].y_dep][move[j].x_dep].couleur!=plateau[(move[j].y_dep+move[j].y_arr)/2][(move[j].x_dep+move[j].x_arr)/2].couleur)
 {
  //printf("debug : manger\n"); //debug
  retirer_bushis(plateau, move, j);
 }

}

//##########################################################################################################################################

int verif_bushi_inf(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], int j)
{
 //#### comment ####
 //cette fonction verifie que le pion sauté est bien inférieure ou égal au pion sauteur :

 //variables :
 int res; 
 char sauteur, saute;

 //printf("pion sauté : verif_bushi_inf\n");  //debug 

 //definition des variables char
 sauteur=plateau[move[j].y_dep][move[j].x_dep].bushis;
 saute=trouver_bushi_saute(move, plateau, j);

 //
 if((sauteur<=saute)&&(saute!='o'))  //les caractéres sont rangés par ordre alphabétique (a plus petit ; z plus grand, 
 {                   //D L S sont rangées dans l'ordre inverse d'où le inférieur ou égal ....
  res=1;
  //printf("youpi");  //debug
 }
 else
 {
  res=0;
  //printf("non");  //debug
 }

 //printf("debug : verif_bushi_inf : res_...=%d\n",res); //debug
 return res;
}

//##########################################################################################################################################

char trouver_bushi_saute(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], int j)
{
 //#### comment ####
 //Cette fonction retourne le bushis sauté
 
 //variable :
 char res;
 int moy_y,moy_x;

 //printf("pion sauté : trouver_bushi_saute\n");  //debug 

 //calcul des cordonées :
 moy_y=(move[j].y_dep+move[j].y_arr)/2;
 moy_x=(move[j].x_dep+move[j].x_arr)/2; //moyenne des déplacements qui doit donner les cordonées du bushis du milieu

 //attribution :
 res=plateau[moy_y][moy_x].bushis;

 //return :
 return res;

}

//##########################################################################################################################################

int verif_bonne_equipe(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA],int j)
{
 int res;
 
 //printf("Debug verif_bonne_equipe : couleur joueur : %d couleur plateau %d\n",move[j].joueur, plateau[move[j].y_dep][move[j].x_dep].couleur);  //debug
 if(move[j].joueur==plateau[move[j].y_dep][move[j].x_dep].couleur)
 {
  res=1;
 }
 else
 {
  res=0;
 }


 return res;
}


