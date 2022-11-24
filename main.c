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

void verifevolution(t_joueur* perso,int numero);

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
    /*
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) ///ROUTE
        {
            if(perso->route[i][j]<10)
                printf(" %d ", perso->route[i][j]);
            else
                printf("%d ", perso->route[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    */
}

void SauvegardeMap(t_joueur* perso)
{
    FILE* fichier1 = NULL;
    fichier1 = fopen("map.txt", "w+");

    if (fichier1 != NULL)
    {
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++) ///ROUTE
            {
                if(perso->route[i][j]<10)
                    fprintf(fichier1," %d ", perso->route[i][j]);
                else
                    fprintf(fichier1,"%d ", perso->route[i][j]);
            }
            fprintf(fichier1,"\n");
        }
        fclose(fichier1);
    }

    ///FICHIER TEXTE LISIBLE PAR ORDI
    FILE* fichier4 = NULL;
    fichier4 = fopen("mapbis.txt", "w+");

    if (fichier4 != NULL)
    {
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++) ///ROUTE
            {
                    fprintf(fichier4,"%d ", perso->route[i][j]);
            }
            fprintf(fichier4,"\n");
        }
        fclose(fichier4);
    }
}

void SauvegardeInfos(t_joueur* perso)
{
    FILE* fichier2 = NULL;
    fichier2 = fopen("infos.txt", "w+");

    if (fichier2 != NULL)
    {
        ///STRUCUTURE JOUEUR
        fprintf(fichier2,"Communiste:                %d\n",perso->communiste);
        fprintf(fichier2,"Capitaliste:               %d\n",perso->capitaliste);
        fprintf(fichier2,"ECEflouz:                  %d\n",perso->flouz);
        fprintf(fichier2,"Capacité de l'eau:         %d\n",perso->eau);
        fprintf(fichier2,"Capacité de l'électricité: %d\n",perso->electricite);
        fprintf(fichier2,"Nombre d'habitants:        %d\n\n",perso->nb_habitants);
        ///la route se charge dans l'autre fichier

        ///STRUCTURE BATIMENTS
        fprintf(fichier2,"Nombre de maisons:         %d\n",perso->batiments->nbmaisons);
        fprintf(fichier2,"Nombre de centrales:       %d\n",perso->batiments->nbcentrales);
        fprintf(fichier2,"Nombre de chateaux d'eau:  %d\n\n",perso->batiments->nbchateaux);

        for(int i=0;i<perso->batiments->nbmaisons;i++)
        {
            fprintf(fichier2,"Infos maison N°%d:\n",i);
            fprintf(fichier2,"Coordonnées:            (%d,%d)\n",perso->batiments->maisons[i].x,perso->batiments->maisons[i].y);
            fprintf(fichier2,"Niveau d'évolution:         %d\n",perso->batiments->maisons[i].stade-2);
            fprintf(fichier2,"Nombre d'habitants:         %d\n\n",perso->batiments->maisons[i].nbhabitants);
        }
        fprintf(fichier2,"\n");

        for(int i=0;i<perso->batiments->nbcentrales;i++)
        {
            fprintf(fichier2,"Infos centrale N°%d:\n",i);
            fprintf(fichier2,"Coordonnées:            (%d,%d)\n",perso->batiments->centrales[i].x,perso->batiments->centrales[i].y);
            fprintf(fichier2,"Capacité maximale:          %d\n\n",perso->batiments->centrales[i].capacitemax);
        }
        fprintf(fichier2,"\n");

        for(int i=0;i<perso->batiments->nbchateaux;i++)
        {
            fprintf(fichier2,"Infos chateaux d'eau N°%d:\n",i);
            fprintf(fichier2,"Coordonnées:               (%d,%d)\n",perso->batiments->chateaux[i].x,perso->batiments->chateaux[i].y);
            fprintf(fichier2,"Capacité maximale:           %d\n\n",perso->batiments->chateaux[i].capacitemax);
        }
        fclose(fichier2);

        ///VERSION LISIBLE PAR ORDINATEUR
        FILE* fichier3 = NULL;
        fichier3 = fopen("infosbis.txt", "w+");

        if (fichier3 != NULL) {
            ///STRUCUTURE JOUEUR
            fprintf(fichier3, "%d\n", perso->communiste);
            fprintf(fichier3, "%d\n", perso->capitaliste);
            fprintf(fichier3, "%d\n", perso->flouz);
            fprintf(fichier3, "%d\n", perso->eau);
            fprintf(fichier3, "%d\n", perso->electricite);
            fprintf(fichier3, "%d\n", perso->nb_habitants);
            ///la route se charge dans l'autre fichier

            ///STRUCTURE BATIMENTS
            fprintf(fichier3, "%d\n", perso->batiments->nbmaisons);
            fprintf(fichier3, "%d\n", perso->batiments->nbcentrales);
            fprintf(fichier3, "%d\n", perso->batiments->nbchateaux);

            for (int i = 0; i < perso->batiments->nbmaisons; i++) {
                fprintf(fichier3, "%d\n", perso->batiments->maisons[i].x);
                fprintf(fichier3, "%d\n", perso->batiments->maisons[i].y);
                fprintf(fichier3, "%d\n", perso->batiments->maisons[i].stade);
                fprintf(fichier3, "%d\n", perso->batiments->maisons[i].nbhabitants);
            }

            for (int i = 0; i < perso->batiments->nbcentrales; i++) {
                fprintf(fichier3, "%d\n", perso->batiments->centrales[i].x);
                fprintf(fichier3, "%d\n", perso->batiments->centrales[i].y);
                fprintf(fichier3, "%d\n", perso->batiments->centrales[i].capacitemax);
            }

            for (int i = 0; i < perso->batiments->nbchateaux; i++) {
                fprintf(fichier3, "%d\n", perso->batiments->chateaux[i].x);
                fprintf(fichier3, "%d\n", perso->batiments->chateaux[i].y);
                fprintf(fichier3, "%d\n", perso->batiments->chateaux[i].capacitemax);
            }
            fclose(fichier3);
        }
    }
}

void AffichageCanalisations(t_joueur* perso, BITMAP* back,t_bitmap* images)
{
    for(int i=0;i<LIGNES;i++)
    {
        for(int j=0;j<COLONNES;j++)
        {
            if(perso->route[i][j]==1 || perso->route[i][j]==18 || perso->route[i][j]==19 || perso->route[i][j]==10)
            {
                draw_sprite(back,images->eau,xCoortoPixel(j),yCoortoPixel(i));   ///CHANGEMENT
            }
            if (perso->route[i][j] == 9 || perso->route[i][j] == 90)  ///CHATEAU D'EAU
                draw_sprite(back, images->chateaudeau, xCoortoPixel(j-1), yCoortoPixel(i-2));
        }
    }
}

void AffichageEDF(t_joueur* perso, BITMAP* back,t_bitmap* images)
{
    for(int i=0;i<LIGNES;i++)
    {
        for(int j=0;j<COLONNES;j++)
        {
            if(perso->route[i][j]==1 || perso->route[i][j]==18 || perso->route[i][j]==19 || perso->route[i][j]==10)
            {
                draw_sprite(back,images->electricite,xCoortoPixel(j),yCoortoPixel(i));   ///CHANGEMENT
            }
            if (perso->route[i][j] == 8 || perso->route[i][j] == 80)  ///CENTRALE
            {
                draw_sprite(back, images->centrale, xCoortoPixel(j-1), yCoortoPixel(i-2));
                rectfill(back, xCoortoPixel(j-1), yCoortoPixel(i+4)+5, xCoortoPixel(j+3), yCoortoPixel(i+4)+15, makecol(0,0,0));
                //textprintf(back,font, xCoortoPixel(j), yCoortoPixel(i+4)+8,makecol(255,255,255),"%d",perso->batiments->centrales[0].capacitemax);
            }
        }
    }
}

void EvolutionBatiments(t_joueur* perso, int secondes)
{
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (perso->route[i][j] == 20 && secondes % 15 == 0)  /// terrain -> cabane  (décalage de quelques secondes pour pas que tout se fasse d'affilé)
            {
                perso->route[i][j] = 3;
            }


            if (perso->route[i][j] == 3 && (secondes+1) % 15 == 0)  /// cabane -> maison
            {
                perso->route[i][j] = 4;
            }


            if (perso->route[i][j] == 4 && (secondes+2) % 15 == 0)  /// maison -> immeuble
            {
                perso->route[i][j] = 5;
            }


            if (perso->route[i][j] == 5 && (secondes+3) % 15 == 0)  /// immeuble -> gratte-ciel
            {
                perso->route[i][j] = 6;
            }

        }
    }
}

void TestConnexionReseau(t_joueur* perso)
{
    for(int i=0;i<LIGNES;i++)
    {
        for(int j=0;j<COLONNES;j++)
        {
            if(perso->route[i][j]==1)  ///si route connecte à une centrale
            {
                if ((perso->route[i - 1][j] == 81) || (perso->route[i + 1][j] == 81) ||
                    (perso->route[i][j - 1] == 81) || (perso->route[i][j + 1] == 81) ||
                    (perso->route[i - 1][j] == 18) || (perso->route[i + 1][j] == 18) ||
                    (perso->route[i][j - 1] == 18) || (perso->route[i][j + 1] == 18))
                    perso->route[i][j] = 18;

            }

            if(perso->route[i][j]==1)  ///si route connecte à un chateau d'eau
            {
                if ((perso->route[i - 1][j] == 91) || (perso->route[i + 1][j] == 91) ||
                    (perso->route[i][j - 1] == 91) || (perso->route[i][j + 1] == 91) ||
                    (perso->route[i - 1][j] == 19) || (perso->route[i + 1][j] == 19) ||
                    (perso->route[i][j - 1] == 19) || (perso->route[i][j + 1] == 19))
                    perso->route[i][j] = 19;

            }

            if(perso->route[i][j]==18)  ///si route deja connecte à une centrale devient connecte en eau
            {
                if ((perso->route[i - 1][j] == 91) || (perso->route[i + 1][j] == 91) ||
                    (perso->route[i][j - 1] == 91) || (perso->route[i][j + 1] == 91) ||
                    (perso->route[i - 1][j] == 10) || (perso->route[i + 1][j] == 10) ||
                    (perso->route[i][j - 1] == 10) || (perso->route[i][j + 1] == 10))
                    perso->route[i][j] = 10;
            }

            if(perso->route[i][j]==19)  ///si route deja connecte à un chateau d'eau devient connecte en elec
            {
                if ((perso->route[i - 1][j] == 81) || (perso->route[i + 1][j] == 81) ||
                    (perso->route[i][j - 1] == 81) || (perso->route[i][j + 1] == 81) ||
                    (perso->route[i - 1][j] == 10) || (perso->route[i + 1][j] == 10) ||
                    (perso->route[i][j - 1] == 10) || (perso->route[i][j + 1] == 10))
                    perso->route[i][j] = 10;
            }

            if(perso->route[i][j]==2) ///si terrain connecté à route alimentée en elec et en eau
            {
                if ((perso->route[i - 1][j - 2] == 10) || (perso->route[i][j - 2] == 10) ||
                    (perso->route[i + 1][j - 2] == 10) || (perso->route[i - 1][j + 2] == 10) ||
                    (perso->route[i][j + 2] == 10) || (perso->route[i + 1][j + 2] == 10) ||
                    (perso->route[i - 2][j - 1] == 10) || (perso->route[i - 2][j] == 10) ||
                    (perso->route[i - 2][j + 1] == 10) || (perso->route[i + 2][j - 1] == 10) ||
                    (perso->route[i + 2][j] == 10) || (perso->route[i + 2][j + 1] == 10))
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

void ActualisationCapacites(t_joueur* perso)
{
    ///ACTUALISATION DE L'ELECTRICITE
    perso->electricite=0;
    for(int i=0;i<perso->batiments->nbcentrales;i++)
    {
        perso->electricite+=perso->batiments->centrales[i].capacitemax;
    }

    ///ACTUALISATION DE L'EAU
    perso->eau=0;
    for(int i=0;i<perso->batiments->nbchateaux;i++)
    {
        perso->eau+=perso->batiments->chateaux[i].capacitemax;
    }

    perso->actualisationcapacites=false;
}

void AffichageReseaudEau(t_joueur* perso,t_bitmap* images);  ///on declare ici pour pouvoir l'appeler partout dans le programme, même si elle aprait après dans le code

void Quitter(t_joueur* perso, t_bitmap* images);

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


/*
 * S-P pour vérifier si la maison en parametre pourrai passer au niveau supp avec la capacité eau
 * chercher ca dans les différentes composantes connexes
 * si la maison est dans le taleau maison d'une C-C on vérifie si son alimentation est ON (tab[indice][3]==1)
 * ensuite on vérifie si ca passera après évolution
 */
int capacitelec(t_joueur* perso,int numero)
{
    int chargetot=0;
    int peutevo=0;
    for(int i=0;i<=perso->batiments->nbcentrales;i++)///parcours des centrales
    {
        for(int j=0;j<perso->batiments->centrales[i].nbalim;j++)///parcours des maisons liées à la centrale
        {
            if(numero==perso->batiments->centrales[i].alimentees[j][0])///si la maison est trouvée dans une des centrales
            {
                for(int k=0;k<j;k++)
                {
                    chargetot+=perso->batiments->centrales[i].alimentees[k][1];///on calcule la charges prise par les maisons précedentes
                }
                if(perso->batiments->centrales[i].alimentees[j][1]==0 && chargetot+10<=5000 ||
                   perso->batiments->centrales[i].alimentees[j][1]==10 && chargetot+50<=5000 ||
                   perso->batiments->centrales[i].alimentees[j][1]==50 && chargetot+100<=5000 ||
                   perso->batiments->centrales[i].alimentees[j][1]==100 && chargetot+1000<=5000)///on vérifie que le batiment puisse évoluer avec la quantité d'elec suffisante
                    peutevo=1;
                else
                    peutevo=0;
            }
        }
    }
    return peutevo;
}

///permet de faire évoluer les maisons si toute les condition sont réunies
void verifevolution(t_joueur* perso,int numero)
{
    ///si le terain peut évoluer
    if(perso->batiments->maisons[numero].stade==2 && (perso->batiments->maisons[numero].temps-clock())/1000>=15 && capacitelec(perso,numero)==1)
    {
        perso->batiments->maisons[numero].temps=clock();///nouveau timer de départ
        perso->batiments->maisons[numero].stade+=1;///évolution au stade sup
    }
    ///si la cabane peut évoluer
    else if(perso->batiments->maisons[numero].stade==3 && (perso->batiments->maisons[numero].temps-clock())/1000>=15 && capacitelec(perso,numero)==1)
    {
        perso->batiments->maisons[numero].temps=clock();///nouveau timer de départ
        perso->batiments->maisons[numero].stade+=1;///évolution au stade sup
    }
    ///si la maison peut évoluer
    else if(perso->batiments->maisons[numero].stade==4 && (perso->batiments->maisons[numero].temps-clock())/1000>=15 && capacitelec(perso,numero)==1)
    {
        perso->batiments->maisons[numero].temps=clock();///nouveau timer de départ
        perso->batiments->maisons[numero].stade+=1;///évolution au stade sup
    }
    ///si l'immeuble peut évoluer
    else if(perso->batiments->maisons[numero].stade==5 && (perso->batiments->maisons[numero].temps-clock())/1000>=15 && capacitelec(perso,numero)==1)
    {
        perso->batiments->maisons[numero].temps=clock();///nouveau timer de départ
        perso->batiments->maisons[numero].stade+=1;///évolution au stade sup
    }
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
        EvolutionBatiments(perso,temps[0]);
        SauvegardeMap(perso);
        SauvegardeInfos(perso);

        if(perso->actualisationcapacites==true)
            ActualisationCapacites(perso);


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

        if ((mouse_b & 1) && (mouse_x >= 966) && (mouse_x <= 1015) && (mouse_y >= 628) && (mouse_y <= 670)) ///niveau +1
        {
            rest(200);
            AffichageDieu(images);
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
                (perso->flouz >= 1000)) { ///correspond à la taille de l'écran jouable
                if (((perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) + 1] == 0) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x)] == 0) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x)] == 0) &&
                     (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x)] == 0) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 1] == 0) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 1] == 0) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 1] == 0) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 1] == 0)) &&
                    ((perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 1) &&
                     (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) - 2] == 1) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 1) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 2] == 1) &&
                     (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) + 2] == 1) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 2] == 1) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 1] == 1) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x)] == 1) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 1] == 1) ||
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 1] == 1) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x)] == 1) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 1] == 1) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 10) &&
                     (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) - 2] == 10) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 10) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 2] == 10) &&
                     (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) + 2] == 10) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 2] == 10) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 1] == 10) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x)] == 10) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 1] == 10) ||
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 1] == 10) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x)] == 10) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 1] == 10) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 18) &&
                     (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) - 2] == 18) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 18) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 2] == 18) &&
                     (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) + 2] == 18) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 2] == 18) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 1] == 18) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x)] == 18) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 1] == 18) ||
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 1] == 18) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x)] == 18) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 1] == 18) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 19) &&
                     (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) - 2] == 19) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 19) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 2] == 19) &&
                     (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) + 2] == 19) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 2] == 19) ||
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 1] == 19) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x)] == 19) &&
                     (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 1] == 19) ||
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 1] == 19) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x)] == 19) &&
                     (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 1] == 19))) {
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
                    perso->batiments->maisons[perso->batiments->nbmaisons].stade = 2;
                    perso->batiments->maisons[perso->batiments->nbmaisons].nbhabitants = 0;
                    perso->batiments->maisons[perso->batiments->nbmaisons].x = xPixeltoCoor(mouse_x);
                    perso->batiments->maisons[perso->batiments->nbmaisons].y = yPixeltoCoor(mouse_y);
                    perso->batiments->maisons[perso->batiments->nbmaisons].temps = clock();
                    perso->batiments->nbmaisons += 1;
                }
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


        ///test si les maisons peuvent évoluer -> dépends du mode
        for(int i=0;i<=perso->batiments->nbmaisons;i++)
        {
            verifevolution(perso,i);
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
                    perso->batiments->centrales[perso->batiments->nbcentrales].x= xPixeltoCoor(mouse_x-30);
                    perso->batiments->centrales[perso->batiments->nbcentrales].y= yPixeltoCoor(mouse_y-50);
                    perso->batiments->centrales[perso->batiments->nbcentrales].capacitemax= 5000;
                    perso->batiments->nbcentrales+=1;
                    perso->actualisationcapacites=true;
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
                    perso->batiments->chateaux[perso->batiments->nbchateaux].x= xPixeltoCoor(mouse_x-30);
                    perso->batiments->chateaux[perso->batiments->nbchateaux].y= yPixeltoCoor(mouse_y-50);
                    perso->batiments->chateaux[perso->batiments->nbchateaux].capacitemax= 5000;
                    perso->batiments->nbchateaux+=1;
                    perso->actualisationcapacites=true;
                }
        }
    }
    Quitter(perso,images);
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


void StructureJoueurInit(t_joueur* perso)
{
    ///INITIALISATION STRUCTURE JOUEUR
    perso->eau=0;
    perso->electricite=0;
    perso->flouz=500000;
    perso->nb_habitants=0;
    perso->antispam=true;
    for(int i=0;i<nbantispam;i++ )
    {
        perso->antisp.antispam[i]=true;
    }
    perso->editroute=false;
    perso->editmaison=false;
    perso->editcentrale=false;
    perso->editchateaudeau=false;
    perso->actualisationcapacites=false;

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

    ///INITIALISATION STRUCTURE BATIMENTS
    perso->batiments=(t_bat4*)malloc(sizeof(t_bat4));

    perso->batiments->nbmaisons=0;
    perso->batiments->nbcentrales=0;
    perso->batiments->nbchateaux=0;

    perso->batiments->maisons=(t_terter*)malloc(NBMAISONSMAX*sizeof(t_terter));
    perso->batiments->centrales=(t_centrale*)malloc(NBCENTRALESMAX*sizeof(t_centrale));
    perso->batiments->chateaux=(t_chateau*)malloc(NBCHATEAUXMAX*sizeof(t_chateau));

    perso->batiments->centrales->nbalim=0;



    perso->batiments->centrales->alimentees=(int**)malloc(NBMAISONSMAX*sizeof(int*));

    for(int i=0;i<NBMAISONSMAX;i++)
        perso->batiments->centrales->alimentees[i]=(int*)malloc(NBCOLONNESMAXMATRICEALIMENTEES*sizeof(int));

    for(int i=0;i<NBMAISONSMAX;i++)
    {
        for(int j=0;j<NBCOLONNESMAXMATRICEALIMENTEES;j++)
        {
            perso->batiments->centrales->alimentees[i][j]=0;
        }
    }



    ///INITIALISATION STRUCTURE COMPOSANTE CONNEXE

    perso->composante=(t_connexe*)malloc(NBCONNEXESMAX*sizeof(t_connexe));

    perso->composante->tab=(int**)malloc(NBMAISONSMAX*sizeof(int*));   ///allocation dynamique matrice entiers
    for(int i=0;i<NBMAISONSMAX;i++)
        perso->composante->tab[i]=(int*)malloc(NBCOLONNESMAXTABCONNEXE*sizeof(int));

    for(int i=0;i<NBMAISONSMAX;i++)
    {
        for(int j=0;j<NBCOLONNESMAXTABCONNEXE;j++)
        {
            perso->composante->tab[i][j]=0;
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
    images->dieu = load_bitmap("Bitmaps/dieu.bmp",NULL);
    images->ecranaccueil = load_bitmap("Bitmaps/ecrandemarrageS3.bmp",NULL);
    images->ecranmode = load_bitmap("Bitmaps/ecranmodedejeu.bmp",NULL);
    images->ecrancapitaliste = load_bitmap("Bitmaps/Capitaliste.bmp",NULL);
    images->ecrancommuniste = load_bitmap("Bitmaps/communiste.bmp",NULL);
    images->chateaudeau = load_bitmap("Bitmaps/binouze.bmp",NULL);
    images->centrale = load_bitmap("Bitmaps/NUCULAIRE.bmp",NULL);
    images->terrain = load_bitmap("Bitmaps/TVAAAGUE.bmp",NULL);
    images->ruine = load_bitmap("Bitmaps/ruine.bmp",NULL);
    images->cabane = load_bitmap("Bitmaps/cabane.bmp",NULL);
    images->maison = load_bitmap("Bitmaps/LAMAAAAIIISOONN.bmp",NULL);
    images->immeuble = load_bitmap("Bitmaps/immeuble.bmp",NULL);
    images->gratteciel = load_bitmap("Bitmaps/gratteciel.bmp",NULL);
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

void ChargerUnePartie(t_joueur* perso,t_bitmap* images)
{
    int tmp=0; ///variable tampon pour lire les booleen

    StructureBitmapInit(images);

    perso->editchateaudeau=false;
    perso->editcentrale=false;
    perso->editmaison=false;
    perso->editroute=false;
    perso->antispam=false;
    perso->actualisationcapacites=false;

    for(int i=0;i<nbantispam;i++ )
    {
        perso->antisp.antispam[i]=true;
    }

    ///ALLOCATION DE LA MATRICE ROUTE
    perso->route=(int**)malloc(LIGNES*sizeof(int*));   ///allocation dynamique matrice entiers
    for(int i=0;i<LIGNES;i++)
        perso->route[i]=(int*)malloc(COLONNES*sizeof(int));

    ///ALLOCATION STRUCTURE BATIMENTS
    perso->batiments=(t_bat4*)malloc(sizeof(t_bat4));
    perso->batiments->maisons=(t_terter*)malloc(NBMAISONSMAX*sizeof(t_terter));
    perso->batiments->centrales=(t_centrale*)malloc(NBCENTRALESMAX*sizeof(t_centrale));
    perso->batiments->chateaux=(t_chateau*)malloc(NBCHATEAUXMAX*sizeof(t_chateau));

    ///ALLOCATION STRUCTURE COMPOSANTE CONNEXE
    perso->composante=(t_connexe*)malloc(NBCONNEXESMAX*sizeof(t_chateau));
    perso->composante->tab=(int**)malloc(NBMAISONSMAX*sizeof(int*));   ///allocation dynamique matrice entiers
    for(int i=0;i<NBMAISONSMAX;i++)
        perso->composante->tab[i]=(int*)malloc(NBCOLONNESMAXTABCONNEXE*sizeof(int));

    ///REMPLISSAGE STRUCTURE TAB CONNEXE EN ATTENDANT DE L'UTILISER
    for(int i=0;i<NBMAISONSMAX;i++)
    {
        for(int j=0;j<NBCOLONNESMAXTABCONNEXE;j++)
        {
            perso->composante->tab[i][j]=0;
        }
    }

    ///LECTURE DES INFOS NECESSAIRES DANS INFOSBIS
    FILE* fichier5 = NULL;
    fichier5 = fopen("infosbis.txt", "r");

    if (fichier5 != NULL)
    {
        fscanf(fichier5,"%d",&tmp); ///communiste
        if(tmp==1)
            perso->communiste=true;
        else
            perso->communiste=false;

        fscanf(fichier5,"%d",&tmp);  ///capitaliste
        if(tmp==1)
            perso->capitaliste=true;
        else
            perso->capitaliste=false;

        fscanf(fichier5,"%d",&perso->flouz);
        fscanf(fichier5,"%d",&perso->eau);
        fscanf(fichier5,"%d",&perso->electricite);
        fscanf(fichier5,"%d",&perso->nb_habitants);
        fscanf(fichier5,"%d",&perso->batiments->nbmaisons);
        fscanf(fichier5,"%d",&perso->batiments->nbcentrales);
        fscanf(fichier5,"%d",&perso->batiments->nbchateaux);

        for(int i=0;i<perso->batiments->nbmaisons;i++)
        {
            fscanf(fichier5,"%d",&perso->batiments->maisons[i].x);
            fscanf(fichier5,"%d",&perso->batiments->maisons[i].y);
            fscanf(fichier5,"%d",&perso->batiments->maisons[i].stade);
            fscanf(fichier5,"%d",&perso->batiments->maisons[i].nbhabitants);
        }

        for(int i=0;i<perso->batiments->nbcentrales;i++)
        {
            fscanf(fichier5,"%d",&perso->batiments->centrales[i].x);
            fscanf(fichier5,"%d",&perso->batiments->centrales[i].y);
            fscanf(fichier5,"%d",&perso->batiments->centrales[i].capacitemax);
        }

        for(int i=0;i<perso->batiments->nbchateaux;i++)
        {
            fscanf(fichier5,"%d",&perso->batiments->chateaux[i].x);
            fscanf(fichier5,"%d",&perso->batiments->chateaux[i].y);
            fscanf(fichier5,"%d",&perso->batiments->chateaux[i].capacitemax);
        }
        fclose(fichier5);
    }

    ///REMPLISSAGE DE LA MATRICE ROUTE VIA LE FICHIER MAPBIS

    FILE* fichier6 = NULL;
    fichier6 = fopen("mapbis.txt", "r");

    ///LECTURE ROUTE DU FICHIER MAP BIS
    if (fichier6 != NULL)
    {
        for(int i=0;i<LIGNES;i++)
        {
            for(int j=0;j<COLONNES;j++)
            {
                fscanf(fichier6,"%d",&perso->route[i][j]);
            }
        }
        fclose(fichier6);
    }
    ///il faut encore ecrire et lire la matrice alimentees
    EcranDeJeu(perso,images);
}

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

void Quitter(t_joueur* perso, t_bitmap* images)
{
    free(perso);
    free(images);
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
        ChargerUnePartie(perso,images);
    if(choix==3)
        AfficherRegles();
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
    allegro_exit();
    return 0;
}
END_OF_MAIN();
