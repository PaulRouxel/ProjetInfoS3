
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
    bool editmaison;
    bool editcentrale;
    bool editchateaudeau;
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

//centre (x=1;y=2) centrale -> 8
//centre (x=1;y=2) connecté -> 80
//autour centrale -> 81

//centre (x=1;y=2) chateau d'eau -> 9
//centre (x=1;y=2) connecté -> 90
//autour chateau d'eau -> 91


#endif
