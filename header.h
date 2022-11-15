
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


#endif
