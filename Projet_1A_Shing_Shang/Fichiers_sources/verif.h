
#include "structures.h"



//PROTOTYPES :
//verif :
void choix_verif(deplacement *demande, case_pla plateau[HAU_PLA][LAR_PLA]);
int verif_bushis(deplacement test, case_pla plateau[LAR_PLA][HAU_PLA]);
int boucle_entre_correcte(deplacement *move, case_pla plateau[HAU_PLA][LAR_PLA]);


//deplacement singe :
int verif_singe(deplacement singe);
int singe_horizontal(deplacement singe);
int singe_vertical(deplacement singe);
int singe_diagonal(deplacement singe);
int choix_singe(deplacement demande);




