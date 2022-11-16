
#ifndef POINTH_H_INCLUDED
#define POINTH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <allegro.h>
#include <stdbool.h>

/**********************/
/*     STRUCTURES     */
/**********************/

#define GRILLE_W 62
#define GRILLE_H 34

#define COLONNES 45
#define LIGNES 35

#define nbantispam 30

///STUCTURE POUR LES VARIABLES DE TEMPS ///
typedef struct temps
{
    bool antispam[nbantispam];
}t_temps;

/// STRUCTURE DES JOUEURS ///
typedef struct joueur  //Cette structure gerera les donnees de joueurs tout au long de la partie
{
    bool communiste;
    bool capitaliste;
    int flouz;
    int eau;
    int electricite;
    int nb_habitants;
    t_temps antisp;
    bool antispam;
    bool editroute;
    bool editmaison;
    int** route;
} t_joueur;

typedef struct bitmap
{
    BITMAP* map0;
    BITMAP* map1;
    BITMAP* map2;
    BITMAP* fond0;
    BITMAP* fond1;
    BITMAP* fond2;
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
}t_bitmap;






///INFOS
//libre -> 0
//route -> 1
//centre terrain -> 2
//centre terrain connecté -> 20
//autour terrain -> 21




/*************************/
/*     PROTOTYPES        */
/*************************/


void initialisationAllegro(); //Initialise allegro

int xPixeltoCoor(int xPixel); //pour traduire les pixels en coordonnes en X

int yPixeltoCoor(int yPixel); //pour traduire les pixels en coordonnes en Y

int xCoortoPixel(int xCoor); //pour traduire les coordonnes en pixels en X

int yCoortoPixel(int yCoor); //pour traduire les coordonnes en pixels en Y

void AffichageRoute(t_joueur* perso, BITMAP* grille); //pour afficher les routes sur la bitmap de fond

void AffichageTemps(BITMAP* back, int* temps,clock_t t1, t_joueur* perso); //affiche le temps qui avance sur l'écran



#endif
