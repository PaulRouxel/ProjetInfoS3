#include "header.h"

///PERMET DE FAIRE EVOLUER LES MAISONS SI LES CNDTIONS SONT REUNIS (CAPITALISTE)
void VerifEvolutionCapitaliste(t_joueur* perso,int numero)
{
    int tmp=0;
    ///si le terrain peut évoluer
    if(perso->batiments->maisons[numero].stade==2 && (clock()-perso->batiments->maisons[numero].temps)/1000>=15)
    {
        perso->batiments->maisons[numero].temps=clock();       ///nouveau timer de départ
        perso->batiments->maisons[numero].stade=3;             ///évolution au stade sup
        perso->batiments->maisons[numero].nbhabitants=10;
        perso->route[perso->batiments->maisons[numero].y][perso->batiments->maisons[numero].x]=3;
        perso->actualisationcapacites=true;

        EnleverEauElecCapitaliste(perso,tmp,numero);
    }
        ///si la cabane peut évoluer
    else if(perso->batiments->maisons[numero].stade==3 && (clock()-perso->batiments->maisons[numero].temps)/1000>=15)
    {
        tmp = perso->batiments->maisons[numero].nbhabitants;
        perso->batiments->maisons[numero].temps=clock();       ///nouveau timer de départ
        perso->batiments->maisons[numero].stade=4;             ///évolution au stade sup
        perso->batiments->maisons[numero].nbhabitants=50;
        perso->route[perso->batiments->maisons[numero].y][perso->batiments->maisons[numero].x]=4;
        perso->actualisationcapacites=true;

        EnleverEauElecCapitaliste(perso,tmp,numero);

    }
        ///si la maison peut évoluer
    else if(perso->batiments->maisons[numero].stade==4 && (clock()-perso->batiments->maisons[numero].temps)/1000>=15)
    {
        tmp = perso->batiments->maisons[numero].nbhabitants;
        perso->batiments->maisons[numero].temps=clock();       ///nouveau timer de départ
        perso->batiments->maisons[numero].stade=5;             ///évolution au stade sup
        perso->batiments->maisons[numero].nbhabitants=100;
        perso->route[perso->batiments->maisons[numero].y][perso->batiments->maisons[numero].x]=5;
        perso->actualisationcapacites=true;

        EnleverEauElecCapitaliste(perso,tmp,numero);
    }
        ///si l'immeuble peut évoluer
    else if(perso->batiments->maisons[numero].stade==5 && (clock()-perso->batiments->maisons[numero].temps)/1000>=15)
    {
        tmp = perso->batiments->maisons[numero].nbhabitants;
        perso->batiments->maisons[numero].temps = clock();       ///nouveau timer de départ
        perso->batiments->maisons[numero].stade = 6;             ///évolution au stade sup
        perso->batiments->maisons[numero].nbhabitants = 1000;
        perso->route[perso->batiments->maisons[numero].y][perso->batiments->maisons[numero].x] = 6;
        perso->actualisationcapacites = true;

        EnleverEauElecCapitaliste(perso, tmp, numero);
    }
}

void VerifEvolutionCommuniste(t_joueur* perso,int numero)
{
    ///si le terrain peut évoluer
    if(perso->batiments->maisons[numero].stade==2 && (clock()-perso->batiments->maisons[numero].temps)/1000>=15 && capacitelec(perso,numero)==1)
    {
        perso->batiments->maisons[numero].temps=clock();///nouveau timer de départ
        perso->batiments->maisons[numero].stade+=1;///évolution au stade sup
    }
    ///si la cabane peut évoluer
    if(perso->batiments->maisons[numero].stade==3 && (clock()-perso->batiments->maisons[numero].temps)/1000>=15 && capacitelec(perso,numero)==1)
    {
        perso->batiments->maisons[numero].temps=clock();///nouveau timer de départ
        perso->batiments->maisons[numero].stade+=1;///évolution au stade sup
    }
    ///si la maison peut évoluer
    if(perso->batiments->maisons[numero].stade==4 && (clock()-perso->batiments->maisons[numero].temps)/1000>=15 && capacitelec(perso,numero)==1)
    {
        perso->batiments->maisons[numero].temps=clock();///nouveau timer de départ
        perso->batiments->maisons[numero].stade+=1;///évolution au stade sup
    }
    ///si l'immeuble peut évoluer
    if(perso->batiments->maisons[numero].stade==5 && (clock()-perso->batiments->maisons[numero].temps)/1000>=15 && capacitelec(perso,numero)==1)
    {
        perso->batiments->maisons[numero].temps=clock();///nouveau timer de départ
        perso->batiments->maisons[numero].stade+=1;///évolution au stade sup
    }
}

///PERMET DE VERIFIER SI LA CONSTRUCTION DE LA MAISON EST VIABLE: TOUTE LA PLACE EST DISPONIBLE ET EST CONNECTE A UN RESEAU ROUTIER
void VerifMaison(t_joueur* perso)
{
    if (((perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x) + 1] == 0) &&
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x)] == 0) &&
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x)] == 0) &&
         (perso->route[yPixeltoCoor(mouse_y)][xPixeltoCoor(mouse_x)] == 0) &&
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 1] == 0) &&
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 1] == 0) &&
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 1] == 0) &&
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 1] == 0)) &&
        ((perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 10) &&
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
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 1] == 10)))
    {
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
        perso->actualisationcapacites=true;
    }
}

///PERMET DE VERIFIER SI LA CONSTRUCTION DU CHATEAU D'EAU EST VIABLE: TOUTE LA PLACE EST DISPONIBLE ET EST CONNECTE A UN RESEAU ROUTIER
void VerifChateaux(t_joueur* perso)
{
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
        (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 2] == 0) &&
        ((perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) - 1] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 0] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 1] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) - 1] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 0] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 1] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) - 1] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 0] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 1] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) - 1] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 0] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 1] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) - 1] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 0] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 1] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) - 1] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 0] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 1] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) - 1] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 0] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 1] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) - 1] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 0] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 1] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 3] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 3] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 3] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 3] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 3] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 3] == 10)))
    {
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

///PERMET DE VERIFIER SI LA CONSTRUCTION DE LA CENTRALE EST VIABLE: TOUTE LA PLACE EST DISPONIBLE ET EST CONNECTE A UN RESEAU ROUTIER
void VerifCentrale(t_joueur* perso)
{
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
        (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 2] == 0) &&
        ((perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) - 1] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 0] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 1] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) - 1] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 0] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 1] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 2] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 3] == 1) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) - 1] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 0] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 1] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) - 1] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 0] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 1] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 2] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 3] == 18) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) - 1] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 0] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 1] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) - 1] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 0] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 1] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 2] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 3] == 19) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) - 1] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 0] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 1] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 3][xPixeltoCoor(mouse_x) + 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) - 1] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 0] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 1] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 4][xPixeltoCoor(mouse_x) + 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) - 2] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 2][xPixeltoCoor(mouse_x) + 3] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) - 1][xPixeltoCoor(mouse_x) + 3] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 0][xPixeltoCoor(mouse_x) + 3] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 1][xPixeltoCoor(mouse_x) + 3] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 2][xPixeltoCoor(mouse_x) + 3] == 10) ||
         (perso->route[yPixeltoCoor(mouse_y) + 3][xPixeltoCoor(mouse_x) + 3] == 10)))
    {
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

///PROCEDURE QUI VERIFIE LA CONNEXION DES MAISONS AU RESEAU ROUTIER/D'EAU/ELECTRIQUE
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