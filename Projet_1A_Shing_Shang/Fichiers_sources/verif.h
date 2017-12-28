
#include "structures.h"



//PROTOTYPES :
//verif :
void choix_verif(deplacement *demande, case_pla plateau[HAU_PLA][LAR_PLA]);
int verif_bushis(deplacement test, case_pla plateau[LAR_PLA][HAU_PLA]);
void boucle_entre_correcte(deplacement *move, case_pla plateau[HAU_PLA][LAR_PLA]);


//deplacement singe :
int verif_singe(deplacement singe);
int singe_horizontal(deplacement singe);
int singe_vertical(deplacement singe);
int singe_diagonal(deplacement singe);
int choix_singe(deplacement demande, case_pla[LAR_PLA][HAU_PLA]);
int verif_arrive(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA]);
int verif_sauter(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move);
int verif_bushi_inf(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA]);
char trouver_bushi_saute(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA]);




