//dans ce fichier on peut trouver les fonctions relatives aux personnages :
#include "header.h"

void entre_joueur(int nb, perso *p)
{
 //###### coment #####
 //cette fonction sert a demander le nom des joueurs :
 //

 //remplissage des tableaux
 //Demande pseudo1
 printf("\nVeuillez entrer le nom du joueur %d :\n",nb);
 scanf("%s",p->nom);
 while(getchar() !='\n');

}

//##############################################################################################################################################

void ecrire_pseudo(perso pseudo)
{
 //###### coment #####
 //cette fonction sert a écrire le pseudo 1 :
 // !!!! ATTENTION PAS DE RETOUR A LA LIGNE !!!!
 //


 //ecriture
 printf("%s",pseudo.nom);

}
