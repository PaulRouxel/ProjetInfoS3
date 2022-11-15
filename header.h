
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

/// STRUCTURE DES JOUEURS ///
typedef struct joueur  //Cette structure gerera les donnees de joueurs tout au long de la partie
{
    bool communiste;
    bool capitaliste;
    int flouz;
    int eau;
    int electricite;
    int nb_habitants;
    bool antispam;
    bool editroute;
    int** route;

} t_joueur;

/*************************/
/*     PROTOTYPES        */
/*************************/


void initialisationAllegro(); //Initialise allegro

int xPixeltoCoor(int xPixel); //pour traduire les pixels en coordonnes en X

int yPixeltoCoor(int yPixel); //pour traduire les pixels en coordonnes en Y

int xCoortoPixel(int xCoor); //pour traduire les coordonnes en pixels en X

int yCoortoPixel(int yCoor); //pour traduire les coordonnes en pixels en Y

void AffichageRoute(t_joueur* perso, BITMAP* grille); //pour afficher les routes sur la bitmap de fond

void AffichageTemps(BITMAP* back, int* temps,clock_t t1, bool antispam); //affiche le temps qui avance


#endif
