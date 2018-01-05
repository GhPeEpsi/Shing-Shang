#include "structures.h"




//PROTOTYPES :
char choix_demande_dep(deplacement test[MAX_SAUTS], int j);
char demande_dep_dep(deplacement test[MAX_SAUTS], int j);
int demande_dep_arr(deplacement test[MAX_SAUTS], int j);
int recupe_cordo(deplacement move[MAX_SAUTS], int j);
void entre_joueur(int nb, perso *p);
int ordre_jeu(perso joueur1, perso joueur2);
int qui_commence(perso *joueur1, perso *joueur2);
int vouloir_autre_saut(deplacement move[MAX_SAUTS], int j);
