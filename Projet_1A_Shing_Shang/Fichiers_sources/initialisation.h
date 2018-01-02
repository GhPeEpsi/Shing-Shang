
#include "structures.h"



//PROTOTYPES :
void remp_pla(case_pla plateau[HAU_PLA][LAR_PLA]);
void deroulement(case_pla plateau[HAU_PLA][LAR_PLA], deplacement *move, bushi singe, bushi lion, bushi dragon, perso *pseudo1, perso *pseudo2);
void qui_joue(int tour, perso *pseudo1, perso *pseudo2);
void qui_peut_jouer(deplacement *move, perso *pseudo1, perso *pseudo2);
int pile_face(perso *joueur1, perso *joueur2);
int numero_pile_face(perso *joueur1, perso *joueur2, int hasard);
int decide(perso *joueur1, perso *joueur2, int res_choix);
void rempli_dragon(bushi *tmp);
void rempli_singe(bushi *tmp);
void rempli_lion(bushi *tmp);
