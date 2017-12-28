//ce fichier regroupe tout les fonctions relatives au plateau:
#include "structures.h"
#include "initialisation.h"
#include "affichage.h"
#include "verif.h"

void remp_pla(case_pla plateau[HAU_PLA][LAR_PLA])
{
 //#### Coment ####
 // Cette fonction remplit le plateau de 0 matérialisant les cases 
 // et de ' ' servant a délimiter les lignes
 // 

 //Variables
 int i, j;


 //debut du remplissage :
 for(i=0 ; i<HAU_PLA ; i++)
 {
  for(j=0 ; j<LAR_PLA ; j++)
  {
   if(((i<4)||(i>5))&&((j==0)||(j==9)))   //permet de selectionner les cases dans les coins pour ne pas afficher de o
   {
    plateau[i][j].non_case=1;   //ce ne sont pas des cases
    plateau[i][j].vide=1;       //elles sont donc vides
    plateau[i][j].bushis=0;     //il n'i a donc pas de bushis dans les cases
    plateau[i][j].couleur=0;    //pas d'équipe
   }
   else
   {
    plateau[i][j].vide=1;       //les cases sont vides
    plateau[i][j].bushis='o';   //le bushis contenu dans ces cases sont 'o' soit case vide
    plateau[i][j].non_case=0;   //c'est bien une case
    plateau[i][j].couleur=0;    //pas d'équipe
   }   
  }
 }



 //remplissage des bushis :
 //remplissage des portail :
 plateau[1][4].bushis='P';  //je declare que le bushis est de type P =>portail soit un bushis que l'on ne peut ni déplacer
 plateau[1][5].bushis='P';  //ni manger mais le p servira à l'affichage
 plateau[8][4].bushis='P';
 plateau[8][5].bushis='P';
 //de l'equipe dont ils font partie
 plateau[1][4].couleur=32;
 plateau[1][5].couleur=32;   //je définit que les portails font partie de leur propre équipe 
 plateau[8][4].couleur=32;
 plateau[8][5].couleur=32;
 //portail non vide :
 plateau[1][4].non_case=plateau[1][4].vide=0;
 plateau[1][5].non_case=plateau[1][5].vide=0;   //les portails sont des cases qui ne sont pas vide
 plateau[8][4].non_case=plateau[8][4].vide=0;
 plateau[8][5].non_case=plateau[8][5].vide=0;



 //remplissage des bushis :
 //######  Dragons  ######
 plateau[0][1].bushis='D';  
 plateau[0][8].bushis='D';  //je declare que les dragons sont matérialisé par des D
 plateau[9][1].bushis='D';  
 plateau[9][8].bushis='D'; 
 //de l'equipe dont ils font partie
 plateau[0][1].couleur=34;  //il y a 2 dragons par équipe :
 plateau[0][8].couleur=34;  //2 noirs
 plateau[9][1].couleur=31;  //2rouges
 plateau[9][8].couleur=31; 
 //non vide case
 plateau[0][1].non_case=plateau[0][1].vide=0;
 plateau[0][8].non_case=plateau[0][8].vide=0;  //les Dragons sont des cases non vide
 plateau[9][1].non_case=plateau[9][1].vide=0;
 plateau[9][8].non_case=plateau[9][8].vide=0;



 //######  Lions  ######
 plateau[0][2].bushis='L';   
 plateau[1][1].bushis='L';   
 plateau[0][7].bushis='L'; //je declare que les lions sont matérialisé par des L
 plateau[1][8].bushis='L'; 
 plateau[8][1].bushis='L';   
 plateau[9][2].bushis='L';    
 plateau[8][8].bushis='L'; 
 plateau[9][7].bushis='L'; 
 //de l'equipe dont ils font partie
 plateau[0][2].couleur=34;   
 plateau[1][1].couleur=34; //declaration des equipes 4 noir 4rouge
 plateau[0][7].couleur=34; //noir
 plateau[1][8].couleur=34;
 plateau[8][1].couleur=31;   
 plateau[9][2].couleur=31; //rouge   
 plateau[8][8].couleur=31; 
 plateau[9][7].couleur=31;
 //non vide case
 plateau[0][2].non_case=plateau[0][2].vide=0;
 plateau[1][1].non_case=plateau[1][1].vide=0;
 plateau[0][7].non_case=plateau[0][7].vide=0; //les lions sont des cases non vide
 plateau[1][8].non_case=plateau[1][8].vide=0;
 plateau[8][1].non_case=plateau[8][1].vide=0;
 plateau[9][2].non_case=plateau[9][2].vide=0;
 plateau[8][8].non_case=plateau[8][8].vide=0;
 plateau[9][7].non_case=plateau[9][7].vide=0;


 //TESTS!!!!   debug
 //plateau[2][2].bushis='L'; 
 //plateau[2][2].couleur=34;
 //plateau[2][2].non_case=plateau[2][2].vide=0;



 //######  Singes  ######
 plateau[0][3].bushis='S';   
 plateau[1][2].bushis='S';   
 plateau[2][1].bushis='S';  
 plateau[0][6].bushis='S'; 
 plateau[1][7].bushis='S';  
 plateau[2][8].bushis='S';  //je declare que les singes sont matérialisé par des S
 plateau[7][1].bushis='S'; 
 plateau[8][2].bushis='S'; 
 plateau[9][3].bushis='S'; 
 plateau[7][8].bushis='S';
 plateau[8][7].bushis='S';  
 plateau[9][6].bushis='S'; 
 //de l'equipe dont ils font partie
 plateau[0][3].couleur=34;  
 plateau[1][2].couleur=34;  
 plateau[2][1].couleur=34;   //declaration des equipes 4 noir 4rouge
 plateau[0][6].couleur=34;
 plateau[1][7].couleur=34;   //6 noirs
 plateau[2][8].couleur=34;  
 plateau[7][1].couleur=31; 
 plateau[8][2].couleur=31;   //6 rouges
 plateau[9][3].couleur=31; 
 plateau[7][8].couleur=31;
 plateau[8][7].couleur=31;  
 plateau[9][6].couleur=31;
 //non vide case
 plateau[0][3].non_case=plateau[0][3].vide=0;
 plateau[1][2].non_case=plateau[1][2].vide=0;
 plateau[2][1].non_case=plateau[2][1].vide=0;
 plateau[0][6].non_case=plateau[0][6].vide=0;
 plateau[1][7].non_case=plateau[1][7].vide=0;   //les singes sont des cases non vide
 plateau[2][8].non_case=plateau[2][8].vide=0;
 plateau[7][1].non_case=plateau[7][1].vide=0;
 plateau[8][2].non_case=plateau[8][2].vide=0;
 plateau[9][3].non_case=plateau[9][3].vide=0;
 plateau[7][8].non_case=plateau[7][8].vide=0;
 plateau[8][7].non_case=plateau[8][7].vide=0;
 plateau[9][6].non_case=plateau[9][6].vide=0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deroulement(case_pla plateau[HAU_PLA][LAR_PLA], deplacement *move)
{
 //#### Comment ####
 //cette fonction gere le nombre de tour de la partie
 //

 //variables :
 int i=0, res;

 //boucle qui permet la continuité de la partie
 do 
 {
  qui_joue(i);
  aff_pla(plateau);
  choix_verif(move, plateau);
  //res=gagner();
  i++;
 }while(res!=1);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void qui_joue(int i)
{
 //#### comment ####
 //Cette fonction gére l'affichage de qui joue
 //
 
 if(i%2==0)
 {
  printf("\n\nTour %d c'est au joueur 1 de jouer !\n",i+1);
 }
 else
 {
  printf("\n\nTour %d c'est au joueur 2 de jouer !\n",i+1);
 }
 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pile_face(perso *joueur1, perso *joueur2)
{
	int max=1, min=0, hasard;
	srand(time(NULL));

	hasard = rand()%(max+1-min)+min;
        //printf("Hasard : %d\n",hasard);  //debugage

	//ON MET LE NUMERO DES joueurS SELON LE RESULTAT DU PILE OU FACE
	numero_pile_face(joueur1, joueur2, hasard);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void numero_pile_face(perso *joueur1, perso *joueur2, int hasard)
{
	if(hasard==1)
	{
	joueur1->numero=1;
        joueur2->numero=2;
	}
	else
	{
        joueur2->numero=1;
        joueur1->numero=2;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void decide(perso *joueur1, perso *joueur2, int res_choix)
{
	int val;

	if(res_choix==1)
	{
	joueur1->numero=1;
        joueur2->numero=2;
	}
	else
	{
        joueur2->numero=1;
        joueur1->numero=2;
	}
}
