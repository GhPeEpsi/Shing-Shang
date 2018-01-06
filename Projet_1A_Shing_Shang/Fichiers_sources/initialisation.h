#include "structures.h"



//PROTOTYPES :
void remp_pla(case_pla plateau[HAU_PLA][LAR_PLA]);
void deroulement(case_pla plateau[HAU_PLA][LAR_PLA], deplacement move[MAX_SAUTS], bushi singe, bushi lion, bushi dragon, perso *pseudo1, perso *pseudo2);
void qui_joue(int tour, perso *pseudo1, perso *pseudo2);
void qui_peut_jouer(deplacement move[MAX_SAUTS], perso *pseudo1, perso *pseudo2, int j);
int pile_face(perso *joueur1, perso *joueur2);
int numero_pile_face(perso *joueur1, perso *joueur2, int hasard);
int decide(perso *joueur1, perso *joueur2, int res_choix);
void rempli_dragon(bushi *tmp);
void rempli_singe(bushi *tmp);
void rempli_lion(bushi *tmp);
int initia_compteur(comp_der *compteur);
int couleur_differente(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], int j);
void storer(int couleur, comp_der *compteur);
void initia_move(deplacement move[MAX_SAUTS], int j);
void initia_autre_tour(autre_tour *tour);
void remp_tour_supp(deplacement move[MAX_SAUTS], autre_tour *tour, int j);

