#include "header.h"

///AFFICHAGE DE L'ECRAN DE TRANSITION DU MODE CAPITALISTE
void AffichageCapitaliste(t_bitmap* images)
{
    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(images->ecrancapitaliste, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);
        rest(1000);   //temps d'affichage
        next=1;
    }
}

///AFFICHAGE DE L'ECRAN DE TRANSITION DU MODE COMMUNISTE
void AffichageCommuniste(t_bitmap* images)
{
    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(images->ecrancommuniste, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);
        rest(1000);   //temps d'affichage
        next=1;
    }
}

///ECRAN DE CHOIX DU MODE DE JEU
void ChoixDuMode(t_joueur* perso,t_bitmap* images)
{
    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;
    int choix=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(images->ecranmode, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=144)&&(mouse_x<=440)&&(mouse_y>=354)&&(mouse_y<=528))
        {
            choix=1;
            next=1;
        }

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=534)&&(mouse_x<=845)&&(mouse_y>=354)&&(mouse_y<=528))
        {
            choix=2;
            next=1;
        }
    }

    if(choix==1) // capitaliste
    {
        perso->capitaliste=true;
        perso->communiste=false;
        AffichageCapitaliste(images);
    }

    if(choix==2) //communiste
    {
        perso->capitaliste=false;
        perso->communiste=true;
        AffichageCommuniste(images);
    }
}

///LANCE UNE NOUVELLE PARTIE AVEC DES STRUCTURES REMISES A ZERO ET CHOIX DU MODE
void NouvellePartie(t_joueur* perso, t_bitmap* images)
{
    StructureJoueurInit(perso);
    StructureBitmapInit(images);
    ChoixDuMode(perso,images);
    EcranDeJeu(perso,images);
}

///PERMET D'AFFICHER L'ECRAN D'AFFICHAGE DES REGLES
void AfficherRegles()
{
    BITMAP *buffer;
    BITMAP *regles;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    regles = load_bitmap("Bitmaps/regles.bmp",NULL);

    int next=0;
    while(next!=1) {

        blit(regles, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        if((mouse_b&1)&&(mouse_x>=714)&&(mouse_x<=936)&&(mouse_y>=620)&&(mouse_y<=740)){
            next=1;
        }
    }
}

///PERMET DE QUITTER LE JEU EN LIBERANT L'ESPACE MEMOIRE ALLOUE PAR LES STRUCTURES
void Quitter(t_joueur* perso, t_bitmap* images)
{
    free(perso);
    free(images);
    allegro_exit();
}

///AFFICHAGE DU MENU DE DEMARRAGE
void MenuDemarrage(t_joueur* perso, t_bitmap* images)
{
    //BITMAP
    BITMAP* accueil;
    accueil = load_bitmap("Bitmaps/ecrandemarrageS3.bmp",NULL);                 ///CHANGEMENT CHEMIN

    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;
    int choix=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(accueil, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=340)&&(mouse_x<=630)&&(mouse_y>=220)&&(mouse_y<=300))
        {
            choix=1;
            next=1;
        }

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=340)&&(mouse_x<=630)&&(mouse_y>=320)&&(mouse_y<=387))
        {
            choix=2;
            next=1;
        }

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=340)&&(mouse_x<=630)&&(mouse_y>=420)&&(mouse_y<=493))
        {
            choix=3;
            next=1;
        }

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=340)&&(mouse_x<=630)&&(mouse_y>=512)&&(mouse_y<=586))
        {
            choix=4;
            next=1;
        }
    }

    if(choix==1)
        NouvellePartie(perso,images);
    if(choix==2)
        ChargerUnePartie(perso,images);
    if(choix==3)
        AfficherRegles();
    if(choix==4)
        Quitter(perso,images);
}