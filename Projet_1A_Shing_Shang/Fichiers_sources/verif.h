
#include "structures.h"



//PROTOTYPES :
//verif :
int choix_bushi(deplacement *move, case_pla plateau[LAR_PLA][HAU_PLA], char bushi_deplace, bushi singe, bushi lion, bushi dragon);
void choix_verif(deplacement *move, case_pla plateau[HAU_PLA][LAR_PLA], bushi singe, bushi lion, bushi dragon, perso *pseudo1, perso *pseudo2);
int verif_bushis(deplacement test, case_pla plateau[LAR_PLA][HAU_PLA]);
char boucle_entre_correcte(deplacement *move, case_pla plateau[HAU_PLA][LAR_PLA], perso *pseudo1, perso *pseudo2);


//deplacement singe :
int verif_singe(deplacement singe, bushi bushi_dep);
int singe_horizontal(deplacement singe, bushi bushi_deplace);
int singe_vertical(deplacement singe, bushi bushi_deplace);
int singe_diagonal(deplacement singe, bushi bushi_deplace);
int choix_singe(deplacement demande, case_pla[LAR_PLA][HAU_PLA], bushi bushi_dep);
int verif_arrive(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA]);
int verif_sauter(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move, bushi bushi_dep);
int verif_bushi_inf(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA]);
char trouver_bushi_saute(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA]);
void manger(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move);
int verif_bonne_equipe(deplacement move, case_pla plateau[LAR_PLA][HAU_PLA]);



