
#include "structures.h"



//PROTOTYPES :
//verif :
int choix_bushi(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], bushi singe, bushi lion, bushi dragon, comp_der *compteur);
void choix_verif(deplacement move[MAX_SAUTS], case_pla plateau[HAU_PLA][LAR_PLA], bushi singe, bushi lion, bushi dragon, perso *pseudo1, perso *pseudo2, comp_der *compteur);
int verif_bushis(deplacement test[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], comp_der *compteur);
char boucle_entre_correcte(deplacement move[MAX_SAUTS], case_pla plateau[HAU_PLA][LAR_PLA], perso *pseudo1, perso *pseudo2, comp_der *compteur);


//deplacement singe :
int verif_singe(deplacement singe[MAX_SAUTS], bushi bushi_dep);
int singe_horizontal(deplacement singe[MAX_SAUTS], bushi bushi_deplace);
int singe_vertical(deplacement singe[MAX_SAUTS], bushi bushi_deplace);
int singe_diagonal(deplacement singe[MAX_SAUTS], bushi bushi_deplace);
int choix_singe(deplacement move[MAX_SAUTS], case_pla[LAR_PLA][HAU_PLA], bushi bushi_dep, comp_der *compteur);
int verif_arrive(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], int j);
int verif_sauter(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move[MAX_SAUTS], bushi bushi_dep, comp_der *compteur);
int verif_bushi_inf(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], int j);
char trouver_bushi_saute(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], int j);
void manger(case_pla plateau[LAR_PLA][HAU_PLA], deplacement move[MAX_SAUTS], int j);
int verif_bonne_equipe(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], int j);



