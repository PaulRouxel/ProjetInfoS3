#include "header.h"

///AFFICHAGE DE TOUTES LES BITMAPS DE LA ROUTE ET DES BATIMENTS
void AffichageRoute(t_joueur* perso, BITMAP* back,t_bitmap* images) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++)
        {
            if (perso->route[i][j] == 1 || perso->route[i][j] == 18 || perso->route[i][j] == 19 || perso->route[i][j] == 10)  ///ROUTE
                draw_sprite(back, images->route, xCoortoPixel(j), yCoortoPixel(i));

            if (perso->route[i][j] == 2 || perso->route[i][j] == 28 || perso->route[i][j] == 29 || perso->route[i][j] == 20) ///TERRAIN
                draw_sprite(back, images->terrain, xCoortoPixel(j - 1), yCoortoPixel(i - 1));

            if (perso->route[i][j] == 8 || perso->route[i][j] == 80)  ///CENTRALE
                draw_sprite(back, images->centrale, xCoortoPixel(j - 1), yCoortoPixel(i-2)); //-2 -3

            if (perso->route[i][j] == 9 || perso->route[i][j] == 90)  ///CHATEAU D'EAU
                draw_sprite(back, images->chateaudeau, xCoortoPixel(j-1), yCoortoPixel(i-2));

            if (perso->route[i][j] == 3) ///CABANE
                draw_sprite(back, images->cabane, xCoortoPixel(j - 1), yCoortoPixel(i - 1));

            if (perso->route[i][j] == 4) ///MAISON
                draw_sprite(back, images->maison, xCoortoPixel(j - 1), yCoortoPixel(i - 1));

            if (perso->route[i][j] == 5) ///IMMEUBLE
                draw_sprite(back, images->immeuble, xCoortoPixel(j - 1), yCoortoPixel(i - 1));

            if (perso->route[i][j] == 6) ///GRATTE-CIEL
                draw_sprite(back, images->gratteciel, xCoortoPixel(j - 1), yCoortoPixel(i - 1));

        }
    }
}

///AFFICHAGE DES SPRITES DE CANALISATIONS ET CHATEAU D'EAU AU NIVEAU -1
void AffichageCanalisations(t_joueur* perso, BITMAP* back,t_bitmap* images)
{
    for(int i=0;i<LIGNES;i++)
    {
        for(int j=0;j<COLONNES;j++)
        {
            if(perso->route[i][j]==1 || perso->route[i][j]==18 || perso->route[i][j]==19 || perso->route[i][j]==10)
                draw_sprite(back,images->eau,xCoortoPixel(j),yCoortoPixel(i));
            
            if (perso->route[i][j] == 9 || perso->route[i][j] == 90)  ///CHATEAU D'EAU
                draw_sprite(back, images->chateaudeau, xCoortoPixel(j-1), yCoortoPixel(i-2));
        }
    }

    for(int i=0;i<perso->batiments->nbchateaux;i++)
    {
        rectfill(back, xCoortoPixel(perso->batiments->chateaux[i].x-2), yCoortoPixel(perso->batiments->chateaux[i].y-3), xCoortoPixel(perso->batiments->chateaux[i].x+2), yCoortoPixel(perso->batiments->chateaux[i].y-3)+10, makecol(0,0,0));
        textprintf_ex(back,font, xCoortoPixel(perso->batiments->chateaux[i].x-1)-10, yCoortoPixel(perso->batiments->chateaux[i].y-3),makecol(255,255,255),-1,"%d/5000",perso->batiments->chateaux[i].capacitemax);
    }
}

///AFFICHAGE DES SPRITES DU RESEAU ELECTRIQUE ET CENTRALE AU NIVEAU -2
void AffichageEDF(t_joueur* perso, BITMAP* back,t_bitmap* images)
{
    for(int i=0;i<LIGNES;i++)
    {
        for(int j=0;j<COLONNES;j++)
        {
            if(perso->route[i][j]==1 || perso->route[i][j]==18 || perso->route[i][j]==19 || perso->route[i][j]==10)
                draw_sprite(back,images->electricite,xCoortoPixel(j),yCoortoPixel(i)); 
            
            if (perso->route[i][j] == 8 || perso->route[i][j] == 80)  ///CENTRALE
                draw_sprite(back, images->centrale, xCoortoPixel(j-1), yCoortoPixel(i-2));
        }
    }
    for(int i=0;i<perso->batiments->nbcentrales;i++)
    {
        rectfill(back, xCoortoPixel(perso->batiments->centrales[i].x-2), yCoortoPixel(perso->batiments->centrales[i].y-3), xCoortoPixel(perso->batiments->centrales[i].x+2), yCoortoPixel(perso->batiments->centrales[i].y-3)+10, makecol(0,0,0));
        textprintf_ex(back,font, xCoortoPixel(perso->batiments->centrales[i].x-1)-10, yCoortoPixel(perso->batiments->centrales[i].y-3),makecol(255,255,255),-1,"%d/5000",perso->batiments->centrales[i].capacitemax);
    }
}

///AFFICHAGE DU TEMPS SUR L'ECRAN DE JEU
void AffichageTemps(BITMAP* back, int* temps, clock_t t1, t_joueur* perso)
{
    clock_t t2=clock()+1000;            ///on décale d'une seconde pour commencer la partie à 00:01
    temps[0]=(int)(t2-t1)/1000;         ///on calcule la différence de tick depuis le lancement de l'écran de jeu

    if(temps[0]%60==0 && perso->antisp.antispam[0]==true && temps[0]!=1)
    {
        temps[1]=temps[1]+1;
        perso->antisp.antispam[0]=false;
        temps[0]=0;
    }
    else if(temps[0]%60==10 && perso->antisp.antispam[0]==false)
    {
        perso->antisp.antispam[0]=true;
    }

    rectfill(back, 680, 11, 740, 30, makecol(0,173,233));

    if(temps[0]%60<10)
        textprintf_ex(back, font, 715, 22, makecol(0,0,0), -1, "0%d",temps[0]%60);
    else
        textprintf_ex(back, font, 715, 22, makecol(0,0,0), -1, "%d",temps[0]%60);

    if(temps[1]<10)
        textprintf_ex(back, font, 685, 22, makecol(0,0,0), -1, "0%d:",temps[1]);
    else
        textprintf_ex(back, font, 685, 22, makecol(0,0,0), -1, "%d:",temps[1]);

}

///AFFICHAGE DU NIVEAU +1
void AffichageDieu(t_bitmap* images){

    BITMAP *buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    int next=0;

    while(next!=1) {

        blit(images->dieu, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        if((mouse_b&1)&&(mouse_x>=714)&&(mouse_x<=936)&&(mouse_y>=620)&&(mouse_y<=740)){
            next=1;
        }
    }
}

///AFFICHAGE DU NIVEAU -2
void AffichageReseauElec(t_joueur* perso,t_bitmap* images)
{
    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;
    int choix=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(images->fond2, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        blit(images->map2,images->fond2, 0,0,GRILLE_W,GRILLE_H, SCREEN_W,SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        AffichageEDF(perso,images->fond2,images);

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=967)&&(mouse_x<=1011)&&(mouse_y>=598)&&(mouse_y<=650)) ///niveau -1
        {
            choix=1;
            next=1;
        }

        //correspond aux cases de l'ecranb
        if((mouse_b&1)&&(mouse_x>=967)&&(mouse_x<=1011)&&(mouse_y>=521)&&(mouse_y<=570)) ///reseau 0
            next=1;

    }

    if(choix==1) /// niveau -1
    {
        rest(200);
        AffichageReseaudEau(perso,images);
    }
    else             ///niveau 0 (on skip la fonction)
        rest(200);
}

///AFFICHAGE DU NIVEAU -1
void AffichageReseaudEau(t_joueur* perso,t_bitmap* images)
{
    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;
    int choix=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(images->fond1, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        blit(images->map1,images->fond1, 0,0,GRILLE_W,GRILLE_H, SCREEN_W,SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        AffichageCanalisations(perso, images->fond1,images);

        if((mouse_b&1)&&(mouse_x>=967)&&(mouse_x<=1015)&&(mouse_y>=590)&&(mouse_y<=632)) ///niveau -2
        {
            choix=1;
            next=1;
        }

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=967)&&(mouse_x<=1015)&&(mouse_y>=530)&&(mouse_y<=575)) ///reseau 0
            next=1;
    }

    if(choix==1) /// niveau -2
    {
        rest(200);
        AffichageReseauElec(perso,images);
    }
    else          ///niveau 0
        rest(200);
}

///AFFICHAGE GAMEOVER
void GameOver(t_bitmap* images)
{
    BITMAP* buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next=0;

    //boucle d'affichage
    while(next!=1){

        //routine d'affichage
        blit(images->gameover, buffer, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0,SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);

        //correspond aux cases de l'ecran
        if((mouse_b&1)&&(mouse_x>=700)&&(mouse_x<=900)&&(mouse_y>=300)&&(mouse_y<=700)) ///quitter
            next=1;
    }
}

