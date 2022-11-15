
#include "header.h"

void initialisationAllegro(){
    allegro_init();
    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0))!=0){
        allegro_message("Pb de mode graphique") ;
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_keyboard();
    install_mouse();
}


int AffichageTemps(BITMAP* back, int sec, int min,clock_t t1)
{

    clock_t t2=clock()+1000;
    sec=(int)(t2-t1)/1000;

    if(sec==60)
        sec=0;

    ///du mal avec le compteur des minutes vu qu'on peut pas le retourner (je regarde par strucutres ou sinon avec time.h)


    rectfill(back, 706, 11, 810, 30, makecol(255,242,0));

    if(sec<10)
        textprintf_ex(back, font, 775, 22, makecol(0,0,0), -1, "0%d",sec);
    else
        textprintf_ex(back, font, 775, 22, makecol(0,0,0), -1, "%d",sec);

    if(min<10)
        textprintf_ex(back, font, 745, 22, makecol(0,0,0), -1, "0%d:",min);
    else
        textprintf_ex(back, font, 745, 22, makecol(0,0,0), -1, "%d:",min);

    return sec;
}

void RecupererImpots(t_joueur* perso, int time)
{
    if(time%15==0 && perso->antispam==true)                         ///faire un antispam dessus
    {
        perso->flouz+=10*perso->nb_habitants;
        perso->antispam=false;
    }
    if((time+2)%15==0)
        perso->antispam=true;
}

void AffichageReseaudEau(t_joueur* perso);  ///on declare ici pour pouvoir l'appeler partout dans le programme, même si elle aprait après dans le code

void AffichageReseauElec(t_joueur* perso)
{

    BITMAP* ecranelec;
    ecranelec = load_bitmap("ecranreseaudelec.bmp",NULL);                           ///CHANGEMENT CHEMIN

    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    BITMAP* grille;
    grille = load_bitmap("cases.bmp",NULL);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;
    int choix=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(ecranelec, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        blit(grille,ecranelec, 0,0,GRILLE_W,GRILLE_H, SCREEN_W,SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        draw_sprite(ecranelec,grille,62,34);

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=976)&&(mouse_x<=1018)&&(mouse_y>=118)&&(mouse_y<=160)) ///niveau -1
        {
            choix=1;
            next=1;
        }

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=976)&&(mouse_x<=1018)&&(mouse_y>=55)&&(mouse_y<=100)) ///reseau 0
            next=1;

    }

    if(choix==1) /// niveau -1
    {
        rest(200);
        AffichageReseaudEau(perso);
    }
    else             ///niveau 0 (on skip la fonction)
        rest(200);

}


void AffichageReseaudEau(t_joueur* perso)
{
    BITMAP* ecranwater;
    ecranwater = load_bitmap("ecranreseaudeau.bmp",NULL);                           ///CHANGEMENT CHEMIN

    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    BITMAP* grille;
    grille = load_bitmap("cases.bmp",NULL);


    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;
    int choix=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(ecranwater, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        blit(grille,ecranwater, 0,0,GRILLE_W,GRILLE_H, SCREEN_W,SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        draw_sprite(ecranwater,grille,62,34);

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=983)&&(mouse_x<=1020)&&(mouse_y>=114)&&(mouse_y<=153)) ///niveau -2
        {
            choix=1;
            next=1;
        }

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=983)&&(mouse_x<=1020)&&(mouse_y>=63)&&(mouse_y<=105)) ///reseau 0
            next=1;
    }

    if(choix==1) /// niveau -2
    {
        rest(200);
        AffichageReseauElec(perso);
    }
    else          ///niveau 0
        rest(200);

}


void EcranDeJeu(t_joueur* perso)
{
    BITMAP* background;
    background = load_bitmap("ecrandejeu.bmp",NULL);   ///CHANGEMENT CHEMIN

    BITMAP* grille;
    grille = load_bitmap("cases.bmp",NULL);  ///CHANGEMENT CHEMIN

    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //FONT* myfont = load_font("simpsonfont.pcx",NULL,NULL);

    clock_t t1 = clock();
    int minutes=0;
    int secondes=0;

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(background, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        blit(grille,background, 0,0,GRILLE_W,GRILLE_H, SCREEN_W,SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        rectfill(background, 52, 11, 120, 30, makecol(255,242,0)); ///argent
        textprintf_ex(background, font, 60, 20, makecol(0,0,0), -1, "%d",perso->flouz);

        rectfill(background, 196, 11, 260, 30, makecol(255,242,0)); ///capacite eau
        textprintf_ex(background, font, 200, 20, makecol(0,0,0), -1, "%d",perso->eau);

        rectfill(background, 315, 11, 409, 30, makecol(255,242,0)); ///capacite elec
        textprintf_ex(background, font, 320, 20, makecol(0,0,0), -1, "%d",perso->electricite);

        rectfill(background, 873, 11, 991, 30, makecol(255,242,0)); ///nb_hab
        textprintf_ex(background, font, 882, 21, makecol(0,0,0), -1, "%d",perso->nb_habitants);

        secondes=AffichageTemps(background,secondes,minutes,t1);
        RecupererImpots(perso,secondes);


        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=969)&&(mouse_x<=1015)&&(mouse_y>=317)&&(mouse_y<=360))  ///quitter
            next=1;

        //corrrespond aux niveaux du jeu
        if((mouse_b&1)&&(mouse_x>=969)&&(mouse_x<=1015)&&(mouse_y>=123)&&(mouse_y<=171)) ///niveau -1
        {
            rest(200);
            AffichageReseaudEau(perso);
        }

        if((mouse_b&1)&&(mouse_x>=969)&&(mouse_x<=1015)&&(mouse_y>=55)&&(mouse_y<=103)) ///niveau -2
        {
            rest(200);
            AffichageReseauElec(perso);
        }

    }
    allegro_exit();
}


void AffichageCapitaliste()
{
    BITMAP* ecrancapitaliste;
    ecrancapitaliste = load_bitmap("Capitaliste.bmp",NULL);                ///CHANGEMENT CHEMIN

    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(ecrancapitaliste, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);
        rest(1000);   //temps d'affichage
        next=1;
    }
}

void AffichageCommuniste()
{
    BITMAP* ecrancommuniste;
    ecrancommuniste = load_bitmap("communiste.bmp",NULL);                     ///CHANGEMENT CHEMIN

    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(ecrancommuniste, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);
        rest(1000);   //temps d'affichage
        next=1;
    }
}


void ChoixDuMode(t_joueur* perso)
{
    BITMAP* ecranmodedejeu;
    ecranmodedejeu = load_bitmap("ecranmodedejeu.bmp",NULL);                           ///CHANGEMENT CHEMIN

    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;
    int choix=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(ecranmodedejeu, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=180)&&(mouse_x<=480)&&(mouse_y>=440)&&(mouse_y<=520))
        {
            choix=1;
            next=1;
        }

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=571)&&(mouse_x<=837)&&(mouse_y>=440)&&(mouse_y<=520))
        {
            choix=2;
            next=1;
        }
    }

    if(choix==1) // capitaliste
    {
        perso->capitaliste=true;
        perso->communiste=false;
        AffichageCapitaliste();
    }

    if(choix==2) //communiste
    {
        perso->capitaliste=false;
        perso->communiste=true;
        AffichageCommuniste();
    }
}

/*
void Song() //theme
{
    SAMPLE*son;
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    son=load_sample("zikmu.wav"); //on lance le fichier audio          ///CHANGEMENT CHEMIN
    play_sample(son,255,0,1000,0);
}
*/

void StructureInit(t_joueur* perso)
{
    perso->eau=0;
    perso->electricite=0;
    perso->flouz=500000;
    perso->nb_habitants=500;
    perso->antispam=true;
    perso->route=(int**)malloc(35*sizeof(int*));   ///allocation dynamique matrice entiers
    for(int i=0;i<35;i++)
        perso->route[i]=(int*)malloc(45*sizeof(int));
}

void NouvellePartie(t_joueur* perso)
{
    StructureInit(perso);
    ChoixDuMode(perso);
    EcranDeJeu(perso);
}

void ChargerUnePartie(t_joueur* perso)
{
    printf("charger une partie");
}

void AfficherRegles(t_joueur* perso)
{
    printf("afficher regles");
}

void Quitter(t_joueur* perso)
{
    free(perso);
    for(int i = 0; i < 35; ++i)
        free(perso->route[i]);
    free(perso->route);
    allegro_exit();
}

void MenuDemarrage(t_joueur* perso)
{
    //BITMAP
    BITMAP* accueil;
    accueil = load_bitmap("ecrandemarrageS3.bmp",NULL);                 ///CHANGEMENT CHEMIN

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
        NouvellePartie(perso);
    if(choix==2)
        ChargerUnePartie(perso);
    if(choix==3)
        AfficherRegles(perso);
    if(choix==4)
        Quitter(perso);
}


int main()
{
    initialisationAllegro();
    srand(time(NULL));
    t_joueur* homer=(t_joueur*)malloc(sizeof(t_joueur));

    MenuDemarrage(homer);
    free(homer);
    return 0;

}
END_OF_MAIN();

