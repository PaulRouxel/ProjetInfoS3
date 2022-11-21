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

int xPixeltoCoor(int xPixel) //pour traduire les pixels en coordonnes en X
{
    if((xPixel>=62)&&(xPixel<82)) //retourne la case en question
        return 0;
    else if((xPixel>=82)&&(xPixel<102))  //retourne la case en question
        return 1;
    else if((xPixel>=102)&&(xPixel<122))  //retourne la case en question
        return 2;
    else if((xPixel>=122)&&(xPixel<142))  //retourne la case en question
        return 3;
    else if((xPixel>=142)&&(xPixel<162))  //retourne la case en question
        return 4;
    else if((xPixel>=162)&&(xPixel<182))  //retourne la case en question
        return 5;
    else if((xPixel>=182)&&(xPixel<202))  //retourne la case en question
        return 6;
    else if((xPixel>=202)&&(xPixel<222))  //retourne la case en question
        return 7;
    else if((xPixel>=222)&&(xPixel<242)) //retourne la case en question
        return 8;
    else if((xPixel>=242)&&(xPixel<262))  //retourne la case en question
        return 9;
    else if((xPixel>=262)&&(xPixel<282))  //retourne la case en question
        return 10;
    else if((xPixel>=282)&&(xPixel<302))  //retourne la case en question
        return 11;
    else if((xPixel>=302)&&(xPixel<322))  //retourne la case en question
        return 12;
    else if((xPixel>=322)&&(xPixel<342))  //retourne la case en question
        return 13;
    else if((xPixel>=342)&&(xPixel<362))  //retourne la case en question
        return 14;
    else if((xPixel>=362)&&(xPixel<382))  //retourne la case en question
        return 15;
    else if((xPixel>=382)&&(xPixel<402))  //retourne la case en question
        return 16;
    else if((xPixel>=402)&&(xPixel<422))  //retourne la case en question
        return 17;
    else if((xPixel>=422)&&(xPixel<442))  //retourne la case en question
        return 18;
    else if((xPixel>=442)&&(xPixel<462))  //retourne la case en question
        return 19;
    else if((xPixel>=462)&&(xPixel<482))  //retourne la case en question
        return 20;
    else if((xPixel>=482)&&(xPixel<502))  //retourne la case en question
        return 21;
    else if((xPixel>=502)&&(xPixel<522))  //retourne la case en question
        return 22;
    else if((xPixel>=522)&&(xPixel<542)) //retourne la case en question
        return 23;
    else if((xPixel>=542)&&(xPixel<562))  //retourne la case en question
        return 24;
    else if((xPixel>=562)&&(xPixel<582))  //retourne la case en question
        return 25;
    else if((xPixel>=582)&&(xPixel<602))  //retourne la case en question
        return 26;
    else if((xPixel>=602)&&(xPixel<622))  //retourne la case en question
        return 27;
    else if((xPixel>=622)&&(xPixel<642))  //retourne la case en question
        return 28;
    else if((xPixel>=642)&&(xPixel<662))  //retourne la case en question
        return 29;
    else if((xPixel>=662)&&(xPixel<682))  //retourne la case en question
        return 30;
    else if((xPixel>=682)&&(xPixel<702))  //retourne la case en question
        return 31;
    else if((xPixel>=702)&&(xPixel<722))  //retourne la case en question
        return 32;
    else if((xPixel>=722)&&(xPixel<742))  //retourne la case en question
        return 33;
    else if((xPixel>=742)&&(xPixel<762))  //retourne la case en question
        return 34;
    else if((xPixel>=762)&&(xPixel<782))  //retourne la case en question
        return 35;
    else if((xPixel>=782)&&(xPixel<802))  //retourne la case en question
        return 36;
    else if((xPixel>=802)&&(xPixel<822))  //retourne la case en question
        return 37;
    else if((xPixel>=822)&&(xPixel<842)) //retourne la case en question
        return 38;
    else if((xPixel>=842)&&(xPixel<862))  //retourne la case en question
        return 39;
    else if((xPixel>=862)&&(xPixel<882))  //retourne la case en question
        return 40;
    else if((xPixel>=882)&&(xPixel<902))  //retourne la case en question
        return 41;
    else if((xPixel>=902)&&(xPixel<922))  //retourne la case en question
        return 42;
    else if((xPixel>=922)&&(xPixel<942))  //retourne la case en question
        return 43;
    else if((xPixel>=942)&&(xPixel<962))  //retourne la case en question
        return 44;

    else
    {
        return -1;
        allegro_message("error xPixeltoCoor");
    }

}

int yPixeltoCoor(int yPixel)  //pour traduire les pixels en coordonnes en Y
{
    if((yPixel>=34)&&(yPixel<54))
        return 0;
    else if((yPixel>=54)&&(yPixel<74))  //retourne la case en question
        return 1;
    else if((yPixel>=74)&&(yPixel<94))  //retourne la case en question
        return 2;
    else if((yPixel>=94)&&(yPixel<114))  //retourne la case en question
        return 3;
    else if((yPixel>=114)&&(yPixel<134))  //retourne la case en question
        return 4;
    else if((yPixel>=134)&&(yPixel<154))  //retourne la case en question
        return 5;
    else if((yPixel>=154)&&(yPixel<174))  //retourne la case en question
        return 6;
    else if((yPixel>=174)&&(yPixel<194))  //retourne la case en question
        return 7;
    else if((yPixel>=194)&&(yPixel<214))  //retourne la case en question
        return 8;
    else if((yPixel>=214)&&(yPixel<234))  //retourne la case en question
        return 9;
    else if((yPixel>=234)&&(yPixel<254))  //retourne la case en question
        return 10;
    else if((yPixel>=254)&&(yPixel<274))  //retourne la case en question
        return 11;
    else if((yPixel>=274)&&(yPixel<294))  //retourne la case en question
        return 12;
    else if((yPixel>=294)&&(yPixel<314))  //retourne la case en question
        return 13;
    else if((yPixel>=314)&&(yPixel<334))  //retourne la case en question
        return 14;
    else if((yPixel>=334)&&(yPixel<354))  //retourne la case en question
        return 15;
    else if((yPixel>=354)&&(yPixel<374))  //retourne la case en question
        return 16;
    else if((yPixel>=374)&&(yPixel<394))  //retourne la case en question
        return 17;
    else if((yPixel>=394)&&(yPixel<414))  //retourne la case en question
        return 18;
    else if((yPixel>=414)&&(yPixel<434))  //retourne la case en question
        return 19;
    else if((yPixel>=434)&&(yPixel<454))  //retourne la case en question
        return 20;
    else if((yPixel>=454)&&(yPixel<474))  //retourne la case en question
        return 21;
    else if((yPixel>=474)&&(yPixel<494))  //retourne la case en question
        return 22;
    else if((yPixel>=494)&&(yPixel<514))  //retourne la case en question
        return 23;
    else if((yPixel>=514)&&(yPixel<534))  //retourne la case en question
        return 24;
    else if((yPixel>=534)&&(yPixel<554))  //retourne la case en question
        return 25;
    else if((yPixel>=554)&&(yPixel<574))  //retourne la case en question
        return 26;
    else if((yPixel>=574)&&(yPixel<594))  //retourne la case en question
        return 27;
    else if((yPixel>=594)&&(yPixel<614))  //retourne la case en question
        return 28;
    else if((yPixel>=614)&&(yPixel<634))  //retourne la case en question
        return 29;
    else if((yPixel>=634)&&(yPixel<654))  //retourne la case en question
        return 30;
    else if((yPixel>=654)&&(yPixel<674))  //retourne la case en question
        return 31;
    else if((yPixel>=674)&&(yPixel<694))  //retourne la case en question
        return 32;
    else if((yPixel>=694)&&(yPixel<714))  //retourne la case en question
        return 33;
    else if((yPixel>=714)&&(yPixel<734))  //retourne la case en question
        return 34;

    else
    {
        return 0;
        allegro_message("Error yPixeltoCoor");
    }
}

int xCoortoPixel(int xCoor) //pour traduire les coordonnes en pixels en X
{
    if(xCoor==0)
        return 63;
    else if(xCoor==1)  //retourne la case en pixels
        return 83;
    else if(xCoor==2)  //retourne la case en pixels
        return 103;
    else if(xCoor==3)  //retourne la case en pixels
        return 123;
    else if(xCoor==4)  //retourne la case en pixels
        return 143;
    else if(xCoor==5)  //retourne la case en pixels
        return 163;
    else if(xCoor==6)  //retourne la case en pixels
        return 183;
    else if(xCoor==7)  //retourne la case en pixels
        return 203;
    else if(xCoor==8)
        return 223;
    else if(xCoor==9)  //retourne la case en pixels
        return 243;
    else if(xCoor==10)  //retourne la case en pixels
        return 263;
    else if(xCoor==11)  //retourne la case en pixels
        return 283;
    else if(xCoor==12)  //retourne la case en pixels
        return 303;
    else if(xCoor==13)  //retourne la case en pixels
        return 323;
    else if(xCoor==14)  //retourne la case en pixels
        return 343;
    else if(xCoor==15)  //retourne la case en pixels
        return 363;
    else if(xCoor==16)
        return 383;
    else if(xCoor==17)  //retourne la case en pixels
        return 403;
    else if(xCoor==18)  //retourne la case en pixels
        return 423;
    else if(xCoor==19)  //retourne la case en pixels
        return 443;
    else if(xCoor==20)  //retourne la case en pixels
        return 463;
    else if(xCoor==21)  //retourne la case en pixels
        return 483;
    else if(xCoor==22)  //retourne la case en pixels
        return 503;
    else if(xCoor==23)  //retourne la case en pixels
        return 523;
    else if(xCoor==24)
        return 543;
    else if(xCoor==25)  //retourne la case en pixels
        return 563;
    else if(xCoor==26)  //retourne la case en pixels
        return 583;
    else if(xCoor==27)  //retourne la case en pixels
        return 603;
    else if(xCoor==28)  //retourne la case en pixels
        return 623;
    else if(xCoor==29)  //retourne la case en pixels
        return 643;
    else if(xCoor==30)  //retourne la case en pixels
        return 663;
    else if(xCoor==31)  //retourne la case en pixels
        return 683;
    else if(xCoor==32)  //retourne la case en pixels
        return 703;
    else if(xCoor==33)  //retourne la case en pixels
        return 723;
    else if(xCoor==34)  //retourne la case en pixels
        return 743;
    else if(xCoor==35)  //retourne la case en pixels
        return 763;
    else if(xCoor==36)  //retourne la case en pixels
        return 783;
    else if(xCoor==37)  //retourne la case en pixels
        return 803;
    else if(xCoor==38)  //retourne la case en pixels
        return 823;
    else if(xCoor==39)  //retourne la case en pixels
        return 843;
    else if(xCoor==40)  //retourne la case en pixels
        return 863;
    else if(xCoor==41)  //retourne la case en pixels
        return 883;
    else if(xCoor==42)  //retourne la case en pixels
        return 903;
    else if(xCoor==43)  //retourne la case en pixels
        return 923;
    else if(xCoor==44)  //retourne la case en pixels
        return 943;

    else
    {
        return 0;
        allegro_message("Error xCoortoPixel");
    }
}

int yCoortoPixel(int yCoor)  //pour traduire les coordonnes en pixels en Y
{

    if(yCoor==0)
        return 35;
    else if(yCoor==1)  //retourne la case en pixels
        return 55;
    else if(yCoor==2)  //retourne la case en pixels
        return 75;
    else if(yCoor==3)  //retourne la case en pixels
        return 95;
    else if(yCoor==4)  //retourne la case en pixels
        return 115;
    else if(yCoor==5)  //retourne la case en pixels
        return 135;
    else if(yCoor==6)  //retourne la case en pixels
        return 155;
    else if(yCoor==7)  //retourne la case en pixels
        return 175;
    else if(yCoor==8)  //retourne la case en pixels
        return 195;
    else if(yCoor==9)  //retourne la case en pixels
        return 215;
    else if(yCoor==10)  //retourne la case en pixels
        return 235;
    else if(yCoor==11)  //retourne la case en pixels
        return 255;
    else if(yCoor==12)  //retourne la case en pixels
        return 275;
    else if(yCoor==13)  //retourne la case en pixels
        return 295;
    else if(yCoor==14)  //retourne la case en pixels
        return 315;
    else if(yCoor==15)  //retourne la case en pixels
        return 335;
    else if(yCoor==16)
        return 355;
    else if(yCoor==17)  //retourne la case en pixels
        return 375;
    else if(yCoor==18)  //retourne la case en pixels
        return 395;
    else if(yCoor==19)  //retourne la case en pixels
        return 415;
    else if(yCoor==20)  //retourne la case en pixels
        return 435;
    else if(yCoor==21)  //retourne la case en pixels
        return 455;
    else if(yCoor==22)  //retourne la case en pixels
        return 475;
    else if(yCoor==23)  //retourne la case en pixels
        return 495;
    else if(yCoor==24)
        return 515;
    else if(yCoor==25)  //retourne la case en pixels
        return 535;
    else if(yCoor==26)  //retourne la case en pixels
        return 555;
    else if(yCoor==27)  //retourne la case en pixels
        return 575;
    else if(yCoor==28)  //retourne la case en pixels
        return 595;
    else if(yCoor==29)  //retourne la case en pixels
        return 615;
    else if(yCoor==30)  //retourne la case en pixels
        return 635;
    else if(yCoor==31)  //retourne la case en pixels
        return 655;
    else if(yCoor==32)  //retourne la case en pixels
        return 675;
    else if(yCoor==33)  //retourne la case en pixels
        return 695;
    else if(yCoor==34)  //retourne la case en pixels
        return 715;

    else
    {
        return 0;
        allegro_message("Error yCoortoPixel");
    }
}

void AffichageRoute(t_joueur* perso, BITMAP* back,t_bitmap* images) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++)
        {
            if (perso->route[i][j] == 1)  ///ROUTE
                draw_sprite(back, images->route, xCoortoPixel(j), yCoortoPixel(i));

            if (perso->route[i][j] == 2 || perso->route[i][j] == 20) ///TERRAIN
                draw_sprite(back, images->terrain, xCoortoPixel(j - 1), yCoortoPixel(i - 1));

            if (perso->route[i][j] == 8 || perso->route[i][j] == 80)  ///CENTRALE
                draw_sprite(back, images->centrale, xCoortoPixel(j - 1), yCoortoPixel(i-2)); //-2 -3

            if (perso->route[i][j] == 9 || perso->route[i][j] == 90)  ///CHATEAU D'EAU
                draw_sprite(back, images->chateaudeau, xCoortoPixel(j-1), yCoortoPixel(i-2));

        }
    }
    /*
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) ///ROUTE
        {
            printf("%d ", perso->route[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
     */
}

void AffichageCanalisations(t_joueur* perso, BITMAP* back,t_bitmap* images)
{
    for(int i=0;i<LIGNES;i++)
    {
        for(int j=0;j<COLONNES;j++)
        {
            if(perso->route[i][j]==1)
            {
                draw_sprite(back,images->eau,xCoortoPixel(j),yCoortoPixel(i));   ///CHANGEMENT
            }
        }
    }
}

void AffichageEDF(t_joueur* perso, BITMAP* back,t_bitmap* images)
{
    for(int i=0;i<LIGNES;i++)
    {
        for(int j=0;j<COLONNES;j++)
        {
            if(perso->route[i][j]==1)
            {
                draw_sprite(back,images->electricite,xCoortoPixel(j),yCoortoPixel(i));   ///CHANGEMENT
            }
        }
    }
}

void TestConnexionReseau(t_joueur* perso)
{
    for(int i=0;i<LIGNES;i++)
    {
        for(int j=0;j<COLONNES;j++) ///ROUTE
        {
            if(perso->route[i][j]==2)
            {
                if ((perso->route[i - 1][j - 2] == 1) || (perso->route[i][j - 2] == 1) ||
                    (perso->route[i + 1][j - 2] == 1) || (perso->route[i - 1][j + 2] == 1) ||
                    (perso->route[i][j + 2] == 1) || (perso->route[i + 1][j + 2] == 1) ||
                    (perso->route[i - 2][j - 1] == 1) || (perso->route[i - 2][j] == 1) ||
                    (perso->route[i - 2][j + 1] == 1) || (perso->route[i + 2][j - 1] == 1) ||
                    (perso->route[i + 2][j] == 1) || (perso->route[i + 2][j + 1] == 1))
                    perso->route[i][j] = 20;
            }
        }
    }
}

void AffichageTemps(BITMAP* back, int* temps, clock_t t1, t_joueur* perso)
{
    clock_t t2=clock()+1000;
    temps[0]=(int)(t2-t1)/1000;

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

    ///du mal avec le compteur des minutes vu qu'on peut pas le retourner (je regarde par strucutres ou sinon avec time.h)

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

void AffichageReseaudEau(t_joueur* perso,t_bitmap* images);  ///on declare ici pour pouvoir l'appeler partout dans le programme, même si elle aprait après dans le code

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
        AffichageReseaudEau(perso,images);
    }
    else             ///niveau 0 (on skip la fonction)
        rest(200);

}

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
        AffichageReseauElec(perso,images);
    }
    else          ///niveau 0
        rest(200);

}

void EcranDeJeu(t_joueur* perso, t_bitmap* images)
{
    BITMAP *buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    clock_t t1 = clock();

    int* temps= (int*)malloc(2*sizeof(int));
    temps[0]=0;
    temps[1]=0;


    //va nous permettre de sortir de la boucle d'affichage lorsqu'un choix est fait
    int next = 0;

    //boucle d'affichage
    while (next != 1) {

        //routine d'affichage
        blit(images->fond0, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        //blit(grille,background, 0,0,GRILLE_W,GRILLE_H, SCREEN_W,SCREEN_H);
        blit(images->map0, images->fond0, 0, 0, GRILLE_W, GRILLE_H, SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);


        rectfill(images->fond0, 62, 11, 135, 30, makecol(1, 173, 232)); ///argent
        textprintf_ex(images->fond0, font, 85, 20, makecol(0, 0, 0), -1, "%d", perso->flouz);

        rectfill(images->fond0, 235, 11, 300, 30, makecol(1, 173, 232)); ///capacite eau
        textprintf_ex(images->fond0, font, 290, 20, makecol(0, 0, 0), -1, "%d", perso->eau);

        rectfill(images->fond0, 355, 11, 420, 30, makecol(1, 173, 232)); ///capacite elec
        textprintf_ex(images->fond0, font, 410, 20, makecol(0, 0, 0), -1, "%d", perso->electricite);


        rectfill(images->fond0, 900, 11, 1010, 30, makecol(186, 209, 224)); ///nb_hab
        textprintf_ex(images->fond0, font, 982, 21, makecol(0, 0, 0), -1, "%d", perso->nb_habitants);

        AffichageTemps(images->fond0,temps,t1,perso);
        RecupererImpots(perso,temps[0]);
        AffichageRoute(perso, images->fond0, images);
        TestConnexionReseau(perso);

        //correspond aux cases de l'ecran
        if ((mouse_b & 1) && (mouse_x >= 971) && (mouse_x <= 1018) && (mouse_y >= 712 && (mouse_y <= 756)) ) ///quitter
            next = 1;

        //corrrespond aux niveaux du jeu
        if ((mouse_b & 1) && (mouse_x >= 966) && (mouse_x <= 1015) && (mouse_y >= 506) && (mouse_y <= 555)) ///niveau -1
        {
            rest(200);
            AffichageReseaudEau(perso, images);
        }

        if ((mouse_b & 1) && (mouse_x >= 966) && (mouse_x <= 1015) && (mouse_y >= 571) && (mouse_y <= 613)) ///niveau -2
        {
            rest(200);
            AffichageReseauElec(perso, images);
        }

        if ((mouse_b & 1) && (mouse_x >= 5) && (mouse_x <= 55) && (mouse_y >= 148) &&
            (mouse_y <= 200)) /// activation mode edition route
        {
            rest(200);
            if (perso->editroute == false && perso->editmaison == false && perso->editchateaudeau==false &&
                perso->editcentrale == false)
                perso->editroute = true;
            else
                perso->editroute = false;
        }

        if ((mouse_b & 1) && (mouse_x >= 5) && (mouse_x <= 55) && (mouse_y >= 221) &&
            (mouse_y <= 270)) /// activation mode edition maison
        {
            rest(200);
            if (perso->editroute == false && perso->editmaison == false && perso->editchateaudeau==false &&
                perso->editcentrale== false)
                perso->editmaison = true;
            else
                perso->editmaison = false;
        }

        if ((mouse_b & 1) && (mouse_x >= 5) && (mouse_x <= 55) && (mouse_y >= 350) &&
            (mouse_y <= 400)) /// activation mode edition centrale
        {
            rest(200);
            if (perso->editroute == false && perso->editmaison == false && perso->editchateaudeau==false &&
                perso->editcentrale== false)
                perso->editcentrale = true;
            else
                perso->editcentrale = false;
        }

        if ((mouse_b & 1) && (mouse_x >= 5) && (mouse_x <= 55) && (mouse_y >= 287) &&
            (mouse_y <= 335)) /// activation mode edition chateau d'eau
        {
            rest(200);
            if (perso->editroute == false && perso->editmaison == false && perso->editchateaudeau==false &&
                perso->editcentrale==false)
                perso->editchateaudeau = true;
            else
                perso->editchateaudeau = false;
        }

        if (perso->editmaison == true)  ///placement des maisons
        {
            if((mouse_x >=92 && mouse_x<932)&&(mouse_y>=64 && mouse_y<704)) ///affichage surbillance
                draw_sprite(images->fond0,images->surbrillance3x3,mouse_x-30,mouse_y-30);

            if ((mouse_b & 1) && (mouse_x >= 62) && (mouse_x <= 922) && (mouse_y >= 34) && (mouse_y <= 694) &&
                (perso->flouz >= 1000)) ///correspond à la taille de l'écran jouable
                if ((perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x)] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x)] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x)] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 1] == 0)) {
                    perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) + 1] = 21;
                    perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) - 1] = 21;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x)] = 21;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x)] = 21;
                    perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x)] = 2;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 1] = 21;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 1] = 21;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 1] = 21;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 1] = 21;
                    perso->flouz -= 1000;
                }
        }

        if (perso->editroute == true)  ///placement de la route
        {
            if((mouse_x >=72 && mouse_x<952)&&(mouse_y>=44 && mouse_y<724)) ///affichage surbillance
                draw_sprite(images->fond0,images->surbrillance1x1,mouse_x-10,mouse_y-10);


            if ((mouse_b & 1) && (mouse_x >= 62) && (mouse_x <= 962) && (mouse_y >= 34) && (mouse_y <= 734) &&
                (perso->flouz >= 10) && (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x)] ==
                                         0)) ///correspond à la taille de l'écran jouable
            {
                perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x)] = 1;
                perso->flouz -= 10;
            }
        }

        if (perso->editcentrale == true)  ///placement des centrales
        {
            if((mouse_x >=92 && mouse_x<912)&&(mouse_y>=84 && mouse_y<664)) ///affichage surbillance
                draw_sprite(images->fond0,images->surbrillance4x6,mouse_x-30,mouse_y-50); //40 70


            if ((mouse_b & 1) && (mouse_x >= 62) && (mouse_x <= 922) && (mouse_y >= 34) && (mouse_y <= 694) &&
                (perso->flouz >= 100000)) ///correspond à la taille de l'écran jouable
                if ((perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 2] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 2] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 2] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 2] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 2] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 2] == 0)) {
                    perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 0] = 81;
                    perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 2] = 81;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 0] = 81;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 2] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 0] = 8;
                    perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 2] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 0] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 2] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 0] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 2] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 0] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 1] = 81;
                    perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 2] = 81;
                    perso->flouz -= 100000;
                }
        }

        if (perso->editchateaudeau == true)  ///placement des chateau d'eau
        {
            if((mouse_x >=92 && mouse_x<912)&&(mouse_y>=84 && mouse_y<664)) ///affichage surbillance
                draw_sprite(images->fond0,images->surbrillance4x6,mouse_x-30,mouse_y-50); //40 70

            if ((mouse_b & 1) && (mouse_x >= 62) && (mouse_x <= 922) && (mouse_y >= 34) && (mouse_y <= 694) &&
                (perso->flouz >= 100000)) ///correspond à la taille de l'écran jouable
                if ((perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 2] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 2] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 2] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 2] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 2] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 0] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 1] == 0) &&
                    (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 2] == 0)) {
                    perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 0] = 91;
                    perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 2] = 91;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 0] = 91;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 2] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 0] = 9;
                    perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 2] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 0] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 2] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 0] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 2] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 0] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 1] = 91;
                    perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 2] = 91;
                    perso->flouz -= 100000;
                }

        }
    }
    allegro_exit();
}




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
        AffichageCapitaliste(images);
    }

    if(choix==2) //communiste
    {
        perso->capitaliste=false;
        perso->communiste=true;
        AffichageCommuniste(images);
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

void StructureJoueurInit(t_joueur* perso)
{
    perso->eau=0;
    perso->electricite=0;
    perso->flouz=500000;
    perso->nb_habitants=500;
    perso->antispam=true;
    for(int i=0;i<nbantispam;i++ )
    {
        perso->antisp.antispam[i]=true;
    }
    perso->editroute=false;
    perso->editmaison=false;
    perso->editcentrale=false;
    perso->editchateaudeau=false;

    perso->route=(int**)malloc(LIGNES*sizeof(int*));   ///allocation dynamique matrice entiers
    for(int i=0;i<LIGNES;i++)
        perso->route[i]=(int*)malloc(COLONNES*sizeof(int));

    for(int i=0;i<LIGNES;i++)
    {
        for(int j=0;j<COLONNES;j++)
        {
            perso->route[i][j]=0;
        }
    }
}

void StructureBitmapInit(t_bitmap* images)
{
    images->map0 = load_bitmap("Bitmaps/map.bmp",NULL);   ///CHANGEMENT CHEMIN
    images->map1 = load_bitmap("Bitmaps/Egouts.bmp",NULL);
    images->map2 = load_bitmap("Bitmaps/zaapmap.bmp",NULL);
    images->fond0 = load_bitmap("Bitmaps/ecrandejeu.bmp",NULL);
    images->fond1 = load_bitmap("Bitmaps/ecranreseaudeau.bmp",NULL);
    images->fond2 = load_bitmap("Bitmaps/ecranreseaudelec.bmp",NULL);
    images->ecranaccueil = load_bitmap("Bitmaps/ecrandemarrageS3.bmp",NULL);
    images->ecranmode = load_bitmap("Bitmaps/ecranmodedejeu.bmp",NULL);
    images->ecrancapitaliste = load_bitmap("Bitmaps/Capitaliste.bmp",NULL);
    images->ecrancommuniste = load_bitmap("Bitmaps/communiste.bmp",NULL);
    images->chateaudeau = load_bitmap("Bitmaps/binouze.bmp",NULL);
    images->centrale = load_bitmap("Bitmaps/NUCULAIRE.bmp",NULL);
    images->terrain = load_bitmap("Bitmaps/TVAAAGUE.bmp",NULL);
    images->ruine = NULL;
    images->cabane = load_bitmap("Bitmaps/cabane.bmp",NULL);
    images->maison = load_bitmap("Bitmaps/LAMAAAAIIISOONN.bmp",NULL);
    images->immeuble = NULL;
    images->gratteciel = NULL;
    images->route = load_bitmap("Bitmaps/road.bmp",NULL);
    images->eau = load_bitmap("Bitmaps/EAUVERTE.bmp",NULL);
    images->electricite = load_bitmap("Bitmaps/ZAAP.bmp",NULL);
    images->surbrillance1x1 = load_bitmap("Bitmaps/surbrillance1x1.bmp",NULL);
    images->surbrillance3x3 = load_bitmap("Bitmaps/surbrillance3x3.bmp",NULL);
    images->surbrillance4x6 = load_bitmap("Bitmaps/surbrillance4x6.bmp",NULL);
}

void NouvellePartie(t_joueur* perso, t_bitmap* images)
{
    StructureJoueurInit(perso);
    StructureBitmapInit(images);
    ChoixDuMode(perso,images);
    EcranDeJeu(perso,images);
}

void ChargerUnePartie(t_joueur* perso)
{
    printf("charger une partie");
}

void AfficherRegles(t_joueur* perso)
{
    printf("afficher regles");
}

void Quitter(t_joueur* perso, t_bitmap* images)
{
    free(perso);
    free(images);
    for(int i = 0; i < LIGNES; ++i)
        free(perso->route[i]);
    free(perso->route);
    allegro_exit();
}

void QuitterBis()
{
    allegro_exit();
}

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
        ChargerUnePartie(perso);
    if(choix==3)
        AfficherRegles(perso);
    if(choix==4)
        QuitterBis();
}

int main()
{
    initialisationAllegro();
    srand(time(NULL));
    t_joueur* homer=(t_joueur*)malloc(sizeof(t_joueur));
    t_bitmap* images=(t_bitmap*)malloc(sizeof(t_bitmap));

    MenuDemarrage(homer,images);
    free(homer);
    //Quitter(homer,images);
    return 0;
}
END_OF_MAIN();

