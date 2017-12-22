//IMPORTATION DES BIBLIOTECH :
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



//Constantes :
//persos :
#define MAX_NOM 30

//plateau :
#define LAR_PLA 10
#define HAU_PLA 10

//couleur :
#define couleur(param) printf("\033[%sm",param)



//PROTOTYPES :
//affichage
void vouloir_regles();
void aff_reg();
void entete();
void aff_pla(case_pla plateau[HAU_PLA][LAR_PLA]);
void ecrire_pseudo(perso pseudo);
void aff_couleur_bushis(int couleur, char bush);




