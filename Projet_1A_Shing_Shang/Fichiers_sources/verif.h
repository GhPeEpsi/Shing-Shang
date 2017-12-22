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
//verif :
void choix_verif(deplacement demande, case_pla plateau[HAU_PLA][LAR_PLA]);
int verif_bushis(deplacement test, case_pla plateau[LAR_PLA][HAU_PLA]);
void boucle_entre_correcte(deplacement *demande, case_pla plateau[HAU_PLA][LAR_PLA]);


//deplacement singe :
int verif_singe(deplacement singe);
int singe_horizontal(deplacement singe);
int singe_vertical(deplacement singe);
int singe_diagonal(deplacement singe);
int choix_singe(deplacement demande);





