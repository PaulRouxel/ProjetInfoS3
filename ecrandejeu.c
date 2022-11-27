#include "header.h"

///AFFICHAGE PRINCIPAL: ECRAN DU JEU ET CENTRALISE TOUTES LES FONCTIONS
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
    int gameover=0;

    //boucle d'affichage
    while (next != 1) {

        //routine d'affichage
        blit(images->fond0, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        //blit(grille,background, 0,0,GRILLE_W,GRILLE_H, SCREEN_W,SCREEN_H);
        blit(images->map0, images->fond0, 0, 0, GRILLE_W, GRILLE_H, SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        clear_bitmap(buffer);


        rectfill(images->fond0, 62, 11, 135, 30, makecol(1, 173, 232));                                     ///argent
        textprintf_ex(images->fond0, font, 85, 20, makecol(0, 0, 0), -1, "%d", perso->flouz);

        rectfill(images->fond0, 235, 11, 320, 30, makecol(1, 173, 232));                                    ///capacite eau
        textprintf_ex(images->fond0, font, 270, 20, makecol(0, 0, 0), -1, "%d", perso->eau);


        rectfill(images->fond0, 355, 11, 450, 30, makecol(1, 173, 232));                                    ///capacite elec
        textprintf_ex(images->fond0, font, 390, 20, makecol(0, 0, 0), -1, "%d", perso->electricite);


        rectfill(images->fond0, 900, 11, 1010, 30, makecol(186, 209, 224));                                 ///nb_hab
        textprintf_ex(images->fond0, font, 982, 21, makecol(0, 0, 0), -1, "%d", perso->nb_habitants);


        AffichageTemps(images->fond0,temps,t1,perso);
        RecupererImpots(perso,temps[0]);
        AffichageRoute(perso, images->fond0, images);
        TestConnexionReseau(perso);
        SauvegardeMap(perso);
        SauvegardeInfos(perso);
        Regression(perso);

        if(perso->flouz==0 && perso->nb_habitants==0 ||(mouse_b & 2) && (mouse_b & 1))
        {
            gameover=1;
            next=1;
        }


        if(perso->actualisationcapacites==true)
        {
            ActualisationCapacites(perso);
            ActualisationHabitants(perso);
            perso->actualisationcapacites=false;
        }

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
                VerifMaison(perso);
            }
        }

        if (perso->editroute == true)  ///placement de la route
        {
            if((mouse_x >=72 && mouse_x<952)&&(mouse_y>=44 && mouse_y<724)) ///affichage surbillance
                draw_sprite(images->fond0,images->surbrillance1x1,mouse_x-10,mouse_y-10);

            if ((mouse_b & 1) && (mouse_x >= 62) && (mouse_x <= 962) && (mouse_y >= 34) && (mouse_y <= 734) &&
                (perso->flouz >= 10) && (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x)] == 0)) ///correspond à la taille de l'écran jouable
            {
                perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x)] = 1;
                perso->flouz -= 10;
            }
        }

        if(perso->capitaliste==true)
        {
            ///test si les maisons peuvent évoluer -> dépends du mode
            for(int i=0;i<=perso->batiments->nbmaisons;i++)
                VerifEvolutionCapitaliste(perso,i);
        }

        if(perso->communiste==true)
        {
            ///test si les maisons peuvent évoluer -> dépends du mode
            for(int i=0;i<=perso->batiments->nbmaisons;i++)
                VerifEvolutionCommuniste(perso,i);
        }


        if (perso->editcentrale == true)  ///placement des centrales
        {
            if((mouse_x >=92 && mouse_x<912)&&(mouse_y>=84 && mouse_y<664)) ///affichage surbillance
                draw_sprite(images->fond0,images->surbrillance4x6,mouse_x-30,mouse_y-50); //40 70


            if ((mouse_b & 1) && (mouse_x >= 62) && (mouse_x <= 922) && (mouse_y >= 34) && (mouse_y <= 694) &&
                (perso->flouz >= 100000)) ///correspond à la taille de l'écran jouable
                VerifCentrale(perso);
        }

        if (perso->editchateaudeau == true)  ///placement des chateau d'eau
        {
            if((mouse_x >=92 && mouse_x<912)&&(mouse_y>=84 && mouse_y<664)) ///affichage surbillance
                draw_sprite(images->fond0,images->surbrillance4x6,mouse_x-30,mouse_y-50); //40 70

            if ((mouse_b & 1) && (mouse_x >= 62) && (mouse_x <= 922) && (mouse_y >= 34) && (mouse_y <= 694) &&
                (perso->flouz >= 100000)) ///correspond à la taille de l'écran jouable
                VerifChateaux(perso);

        }
    }
    if(gameover==1)
        GameOver(images);
    Quitter(perso,images);
}


