#ifndef POINTH_H_INCLUDED
#define POINTH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <allegro.h>
#include <stdbool.h>


#define GRILLE_W 62
#define GRILLE_H 34

#define COLONNES 45
#define LIGNES 35

#define nbantispam 30

#define NBMAISONSMAX 30
#define NBCENTRALESMAX 10
#define NBCHATEAUXMAX 10

#define NBCONNEXESMAX 5
#define NBCOLONNESMAXTABCONNEXE 4

#define NBCOLONNESMAXMATRICEALIMENTEES 3

/**********************/
/*     STRUCTURES     */
/**********************/

/// Structure d'une Maison ///
typedef struct maison
{
    int x;  ///coordonnées du centre du batiment
    int y;
    int stade; ///stade d'évolution
    int nbhabitants;
    clock_t temps;  ///temps depuis sa dernière évolution
}t_terter;

typedef struct centrale
{
    int x;  ///coordonnées du centre du batiment
    int y;
    int capacitemax;
    int** alimentees;   ///id puis quantité d'hab puis distance -> tableau trié par distance croissante
    int nbalim;        ///nombre de maisons alimentées par la centrale
}t_centrale;

typedef struct chateau
{
    int x;
    int y;
    int capacitemax;
}t_chateau;

typedef struct connexe
{
    int** tab; ///d'abord id puis nb habitants puis distance à la centrale la plus proche puis numéro de la centrale qui l'alimente
}t_connexe;


/// STRUCTURE pour les batiments ///
typedef struct batiments
{
    t_terter* maisons;
    t_centrale* centrales;
    t_chateau* chateaux;
    int nbmaisons;
    int nbcentrales;
    int nbchateaux;
}t_bat4;


///STUCTURE POUR LES VARIABLES DE TEMPS ///
typedef struct temps
{
    bool antispam[nbantispam];
}t_temps;

/****************************/
/*    THEORIE DES GRAPHES   */
/****************************/

typedef struct sommet{
    int num;
    int nb_succ;
    int blanc;
    int gris;
    int noir;
    struct sommet* tabsucc;
}sommet;

typedef struct arete{
    sommet a;
    sommet b;
    int poids;
}arete;

typedef struct maillon{
    sommet pred;
    sommet act;
    int PoidRelatif;
}maillon;

typedef struct graphe{
    int ordre;
    int taille;
    sommet *tab_sommet;
    arete *tab_arete;
}graphe;

/// STRUCTURE DES JOUEURS ///
typedef struct joueur  //Cette structure gerera les donnees de joueurs tout au long de la partie ( XD )
{
    bool communiste;
    bool capitaliste;
    int flouz;
    int eau;
    int electricite;
    int nb_habitants;
    bool antispam;
    bool editroute;
    bool editmaison;
    bool editcentrale;
    bool editchateaudeau;
    bool actualisationcapacites;
    graphe* g;
    int** route;
    t_temps antisp;
    t_bat4* batiments;
    t_connexe* composante;


} t_joueur;

typedef struct bitmap
{
    BITMAP* map0;
    BITMAP* map1;
    BITMAP* map2;
    BITMAP* fond0;
    BITMAP* fond1;
    BITMAP* fond2;
    BITMAP* dieu;
    BITMAP* ecranaccueil;
    BITMAP* ecranmode;
    BITMAP* ecrancommuniste;
    BITMAP* ecrancapitaliste;
    BITMAP* chateaudeau;
    BITMAP* centrale;
    BITMAP* terrain;
    BITMAP* ruine;
    BITMAP* cabane;
    BITMAP* maison;
    BITMAP* immeuble;
    BITMAP* gratteciel;
    BITMAP* route;
    BITMAP* eau;
    BITMAP* electricite;
    BITMAP* surbrillance1x1;
    BITMAP* surbrillance3x3;
    BITMAP* surbrillance4x6;
}t_bitmap;



///INFOS
//libre -> 0

//route -> 1
//route connecte à une centrale -> 18
//route connecte à un chateau d'eau ->19
//route connecte en eau ET elec ->10

//centre terrain -> 2
//centre terrain connecté en eau ET elec -> 20
//autour terrain -> 21


//centre (x=1;y=2) centrale -> 8
//centre (x=1;y=2) connecté -> 80
//autour centrale -> 81

//centre (x=1;y=2) chateau d'eau -> 9
//centre (x=1;y=2) connecté -> 90
//autour chateau d'eau -> 91

//crash lorsque on construit en bordures du terrain (barrière ou blindage en +)
//map de fond niveau -2







/*************************/
/*     PROTOTYPES        */
/*************************/


void initialisationAllegro(); //Initialise allegro

int xPixeltoCoor(int xPixel); //pour traduire les pixels en coordonnes en X

int yPixeltoCoor(int yPixel); //pour traduire les pixels en coordonnes en Y

int xCoortoPixel(int xCoor); //pour traduire les coordonnes en pixels en X

int yCoortoPixel(int yCoor); //pour traduire les coordonnes en pixels en Y

void AffichageRoute(t_joueur* perso, BITMAP* back,t_bitmap* images); //pour afficher les routes sur la bitmap de fond

void AffichageTemps(BITMAP* back, int* temps,clock_t t1, t_joueur* perso); //affiche le temps qui avance sur l'écran



#endif
