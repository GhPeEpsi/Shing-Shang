//ce fichier regroupe tout les fonctions relatives au plateau:
#include "structures.h"
#include "initialisation.h"
#include "affichage.h"
#include "verif.h"
#include "demande.h"
#include "deplacement.h"

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
 plateau[2][2].bushis='S'; 
 plateau[2][2].couleur=31;
 plateau[2][2].non_case=plateau[2][2].vide=0;

 plateau[4][2].bushis='S'; 
 plateau[4][2].couleur=31;
 plateau[4][2].non_case=plateau[2][2].vide=0;



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

void deroulement(case_pla plateau[HAU_PLA][LAR_PLA], deplacement move[MAX_SAUTS], bushi singe, bushi lion, bushi dragon, perso *pseudo1, perso *pseudo2)
{
 //#### Comments ####
 //cette fonction gère le nombre de tours de la partie
 //

 //variables :
 int i=0, res=0, j=0, res_autre_saut;
 comp_der compteur;
 initia_compteur(&compteur);
 initia_move(move, j);

 //boucle qui permet la continuité de la partie
 do 
 { 
   //printf("debug 1 : Deroulement : i=%d ; j=%d\n",i,j); //debug
   compteur.nb_sauts=j;
   qui_joue(i, pseudo1, pseudo2);
   aff_rejouer(move, j);  //à modifier
   aff_pla(plateau);
   choix_verif(move, plateau, singe, lion, dragon, pseudo1, pseudo2, &compteur);

   res_autre_saut=vouloir_autre_saut(move, j);  //fonction qui demande si le joueur veut refaire un saut (si il a déjà fait un saut)
                                                // ou s'il veut jouer avec un autre bushi après le shing-shang
   //printf("debug 2 : Deroulement : i=%d ; j=%d\n",i,j); //debug
  
   if(move[j].saute==1)  //est ce qu'il y a eu un saut a ce tour et est ce que le joueur veut resauter ?
   {
      j++;
      //printf("\nCC\n");  //debug
      //printf("debug 2 : Deroulement : compteur.nb_bushis_enemi_saute=%d ; j=%d\n",compteur.nb_bushis_enemi_saute,j); //debug
      if((j>=2)&&(compteur.nb_bushis_enemi_saute!=0))  //est ce qu'il y a shing shang et est-ce qu'il y a eu saut d'un ennemi
      {
         //printf("debug : deroulement : shing shang\n");
         retirer_bushis(plateau, move, compteur);
         initia_move(move, j);
         initia_compteur(&compteur);
         j=0;
      }
      else
      {
       if(res_autre_saut==0)
         {
          //printf("debug n°3");
          i++;
          initia_move(move, j);
          move[0].tour=i;
          initia_compteur(&compteur);
          j=0;
         }
      }
   }
   else
   { 
      j=0;
      i++;
      move[j].tour=i;
      initia_compteur(&compteur);
      initia_move(move, j);
   }


   //res=gagner();

 }while(res!=1); //ancienne boucle (move[j-1].saute==1);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void qui_joue(int tour, perso *pseudo1, perso *pseudo2)
{
 //#### comments ####
 //Cette fonction gère l'affichage de qui joue
 //
 
 //printf("debug : qui_joue\n");//debug

 if(pseudo1->numero==1)
 {
    //printf("debug : qui_joue : 1\n");//debug
    if(tour%2==0)
    {
     aff_qui_joue(*pseudo1, tour);
     //pseudo1->couleur=34;
     //printf("debug : qui_joue : 1.1\n");//debug
    }
    else
    {
     aff_qui_joue(*pseudo2, tour);
     //pseudo1->couleur=31;
     //printf("debug : qui_joue : 1.2\n");//debug
    }   
 }
 else
 {
   //printf("debug : qui_joue : 2");//debug
    if(tour%2==0)
    {
     aff_qui_joue(*pseudo2, tour);
     //pseudo1->couleur=34;
    }
    else
    {
     aff_qui_joue(*pseudo1, tour);
     //pseudo1->couleur=31;
    }
 }
 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void qui_peut_jouer(deplacement move[MAX_SAUTS], perso *pseudo1, perso *pseudo2, int j)
{
 //cette fonction définit qui peut jouer donc quels bushis peuvent être bougés :
 //

 //printf("Je suis dans qui peut jouer move[0].tour=%d\n",move[0].tour); //debug
 
 if((move[0].tour)%2==0)
 {
  move[j].joueur=34;
 }
 else
 {
  move[j].joueur=31;
 }

 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pile_face(perso *joueur1, perso *joueur2)
{
	int max=1, min=0, hasard, res;
	srand(time(NULL));

	hasard = rand()%(max+1-min)+min;
        //printf("Hasard : %d\n",hasard);  //debug

	//ON MET LE NUMERO DES joueurS SELON LE RESULTAT DU PILE OU FACE
	res=numero_pile_face(joueur1, joueur2, hasard);

        return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int numero_pile_face(perso *joueur1, perso *joueur2, int hasard)
{
        int res;
   
	if(hasard==1)
	{
	joueur1->numero=1;
        joueur2->numero=2;
        res=1;
	}
	else
	{
        joueur2->numero=1;
        joueur1->numero=2;
        res=2;
	}

        return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int decide(perso *joueur1, perso *joueur2, int res_choix)
{
	int res;

	if(res_choix==1)
	{
	joueur1->numero=1;
        joueur2->numero=2;
        res=1;
	}
	else
	{
        joueur2->numero=1;
        joueur1->numero=2;
        res=2;
	}

        return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rempli_singe(bushi *tmp)
{
 tmp->nb_saut_max=2;
 tmp->nb_saut_min=1;
 tmp->bushi='S';
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rempli_lion(bushi *tmp)
{
 tmp->nb_saut_max=1;
 tmp->nb_saut_min=1;
 tmp->bushi='L';
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rempli_dragon(bushi *tmp)
{
 tmp->nb_saut_max=0;
 tmp->nb_saut_min=0;
 tmp->bushi='D';
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int initia_compteur(comp_der *compteur)
{
 compteur->nb_sauts=0;     //définit combien de saut a effectué le bushis pendant le tour
 compteur->shing_shang=0;
 
 for(int i=0 ; i<compteur->nb_bushis_enemi_saute ; i++)
 {
  compteur->bushis_enemi_saute[i]=0;
 }

 compteur->nb_bushis_enemi_saute=0;
 

 return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int couleur_differente(deplacement move[MAX_SAUTS], case_pla plateau[LAR_PLA][HAU_PLA], int j)
{
 //variables :
 int moy_x, moy_y, res;

 //calcul des moyennes :
 moy_x=(move[j].x_dep+move[j].x_arr)/2;
 moy_y=(move[j].y_dep+move[j].y_arr)/2;

 if(plateau[move[j].y_dep][move[j].x_dep].couleur!=plateau[moy_y][moy_x].couleur)
 {
  res=1;
 }
 else
 {
  res=0;
 }

 return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void storer(int couleur, comp_der *compteur)
{
 if(couleur=1)
 {
  //printf("debug : nb_bushis_enemi_saute=%d",compteur->nb_bushis_enemi_saute);
  compteur->nb_bushis_enemi_saute++;
  compteur->bushis_enemi_saute[compteur->nb_bushis_enemi_saute]=compteur->nb_sauts;
 }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initia_move(deplacement move[MAX_SAUTS], int j)
{
 for(int i=0 ; i<j ; i++)
 {
  move[i].bushi='\0';
  move[i].x_dep=0;
  move[i].y_dep=0;
  move[i].x_arr=0;
  move[i].y_arr=0;
  move[i].joueur=0;
  move[i].tour=0;
  move[i].saute=0;
  move[i].shing_shang=0;
 }
}





