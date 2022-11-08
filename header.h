
#ifndef POINTH_H_INCLUDED
#define POINTH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <allegro.h>

/**********************/
/*     STRUCTURES     */
/**********************/

// chaque acteur qui se d�place
typedef struct acteur
{

    // coordonn�e (du coin sup. gauche)
    int x, y;

    // vecteur deplacement
    int dx, dy;

    // tailles (rayons des disques)
    int rayon;

    // couleur des disques
    int couleur;

    // vivant :
    //   0 mort (doit disparaitre de la liste)
    //   1 vivant
    int vivant;

} t_acteur;

// Une collection de acteurs
typedef struct listeActeurs
{
    // nombre maxi d'�l�ments
    // =taille du tableau de pointeurs
    int max;

    // nombre effectif de pointeurs utilis�s
    // (les autres sont � NULL)
    int n;

    // le tableau de pointeurs (allou� dynamiquement)
    t_acteur **tab;

} t_listeActeurs;



/*********************/
/*     PROTOTYPES    */
/*********************/

// Allouer et initialiser un acteur
//   ( � adapter selon besoins )
t_acteur * creerActeur();

// Allouer et initialiser une liste (vide) de acteurs
t_listeActeurs * creerListeActeurs(int maxacteurs);

// Retourne un bool�en vrai si il reste de la place
// dans la liste, faux sinon
int libreListeActeurs(t_listeActeurs *la);

// Allouer et ajouter un acteur � la liste
// et retourner l'adresse de ce nouveau acteur
// retourne NULL en cas de probl�me
t_acteur * ajouterActeur(t_listeActeurs *la);

// Enlever et lib�rer un acteur qui �tait dans la liste en indice i
void enleverActeur(t_listeActeurs *la,int i);


// Actualiser un acteur (bouger ...)
void actualiserActeur(t_acteur *acteur);

// G�rer l'�volution de l'ensemble des acteurs
void actualiserListeActeurs(t_listeActeurs *la);


// Dessiner un acteur sur la bitmap bmp
void dessinerActeur(BITMAP *bmp,t_acteur *acteur);

// Dessiner sur une bitmap l'ensemble des acteurs
void dessinerListeActeurs(BITMAP *bmp,t_listeActeurs *la);


// Dessiner sur une bitmap les cases utilis�es par des acteurs
// ( pour visualiser: pas utile dans un programme finalis� )
void dessinerCasesListeActeurs(BITMAP *bmp,t_listeActeurs *la);

#endif
