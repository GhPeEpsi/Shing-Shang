
#include "structures.h"



//PROTOTYPES :
void remp_pla(case_pla plateau[HAU_PLA][LAR_PLA]);
void deroulement(case_pla plateau[HAU_PLA][LAR_PLA], deplacement *move);
void qui_joue(int i);
void pile_face(perso *joueur1, perso *joueur2);
void numero_pile_face(perso *joueur1, perso *joueur2, int hasard);
void decide(perso *joueur1, perso *joueur2, int res_choix);
