#include "header.h"

///CALCUL DES CAPACITES EN FONCTION DES CAPACITES DE CHAQUE CENTRALES/CHATEAUX D'EAU
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
}

///CALCUL DES HABITANTS EN FONCTION DE TOUTES LES CENTRALES
void ActualisationHabitants(t_joueur* perso)
{
    perso->nb_habitants=0;
    for(int i=0;i<perso->batiments->nbmaisons;i++)
    {
        perso->nb_habitants+=perso->batiments->maisons[i].nbhabitants;
    }
}

///CALCUL LES IMPOTS EN FONCTION DES HABITANTS
void RecupererImpots(t_joueur* perso, int time)
{
    if(time%15==0 && perso->antispam==true)        ///toutes les 15 secondes et une fois grâce à un antispam
    {
        perso->flouz+=10*perso->nb_habitants;
        perso->antispam=false;
    }
    if((time+2)%15==0)                            ///on actualise l'antispam
        perso->antispam=true;
}

///AJUSTE L'ACTUALISATION DES CAPACITES
void EnleverEauElecCapitaliste(t_joueur* perso, int tmp,int numero)
{
    ///ca retire l'elec
    if(perso->batiments->nbcentrales==1)
    {
        perso->batiments->centrales[0].capacitemax=perso->batiments->centrales[0].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
        if(perso->batiments->centrales[0].capacitemax<0)
            perso->batiments->centrales[0].capacitemax=0;
    }

    if(perso->batiments->nbcentrales==2)
    {
        perso->batiments->centrales[0].capacitemax=perso->batiments->centrales[0].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
        if(perso->batiments->centrales[0].capacitemax<0)
        {
            perso->batiments->centrales[0].capacitemax=0;
            perso->batiments->centrales[1].capacitemax=perso->batiments->centrales[1].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
            if(perso->batiments->centrales[1].capacitemax<0)
                perso->batiments->centrales[1].capacitemax=0;
        }
    }

    if(perso->batiments->nbcentrales==3)
    {
        perso->batiments->centrales[0].capacitemax=perso->batiments->centrales[0].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
        if(perso->batiments->centrales[0].capacitemax<0)
        {
            perso->batiments->centrales[0].capacitemax=0;
            perso->batiments->centrales[1].capacitemax=perso->batiments->centrales[1].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
            if(perso->batiments->centrales[1].capacitemax<=0 && perso->batiments->centrales[0].capacitemax<=0)
            {
                perso->batiments->centrales[0].capacitemax=0;
                perso->batiments->centrales[1].capacitemax=0;
                perso->batiments->centrales[2].capacitemax=perso->batiments->centrales[2].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
                if(perso->batiments->centrales[2].capacitemax<0)
                    perso->batiments->centrales[2].capacitemax=0;
            }
        }
    }

    if(perso->batiments->nbcentrales==4)
    {
        perso->batiments->centrales[0].capacitemax=perso->batiments->centrales[0].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
        if(perso->batiments->centrales[0].capacitemax<0)
        {
            perso->batiments->centrales[0].capacitemax=0;
            perso->batiments->centrales[1].capacitemax=perso->batiments->centrales[1].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
            if(perso->batiments->centrales[1].capacitemax<=0 && perso->batiments->centrales[0].capacitemax<=0)
            {
                perso->batiments->centrales[0].capacitemax=0;
                perso->batiments->centrales[1].capacitemax=0;
                perso->batiments->centrales[2].capacitemax=perso->batiments->centrales[2].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
                if(perso->batiments->centrales[2].capacitemax<=0 && perso->batiments->centrales[1].capacitemax<=0 && perso->batiments->centrales[0].capacitemax<=0)
                {
                    perso->batiments->centrales[0].capacitemax=0;
                    perso->batiments->centrales[1].capacitemax=0;
                    perso->batiments->centrales[2].capacitemax=0;
                    perso->batiments->centrales[3].capacitemax=perso->batiments->centrales[3].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
                    if(perso->batiments->centrales[3].capacitemax<=0)
                        perso->batiments->centrales[3].capacitemax=0;
                }
            }
        }
    }


    ///ca retire l'eau
    if(perso->batiments->nbchateaux==1)
    {
        perso->batiments->chateaux[0].capacitemax=perso->batiments->chateaux[0].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
        if(perso->batiments->chateaux[0].capacitemax<0)
            perso->batiments->chateaux[0].capacitemax=0;
    }

    if(perso->batiments->nbchateaux==2)
    {
        perso->batiments->chateaux[0].capacitemax=perso->batiments->chateaux[0].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
        if(perso->batiments->chateaux[0].capacitemax<0)
        {
            perso->batiments->chateaux[0].capacitemax=0;
            perso->batiments->chateaux[1].capacitemax=perso->batiments->chateaux[1].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
            if(perso->batiments->chateaux[1].capacitemax<0)
                perso->batiments->chateaux[1].capacitemax=0;
        }
    }

    if(perso->batiments->nbchateaux==3)
    {
        perso->batiments->chateaux[0].capacitemax=perso->batiments->chateaux[0].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
        if(perso->batiments->chateaux[0].capacitemax<0)
        {
            perso->batiments->chateaux[0].capacitemax=0;
            perso->batiments->chateaux[1].capacitemax=perso->batiments->chateaux[1].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
            if(perso->batiments->chateaux[1].capacitemax<=0 && perso->batiments->chateaux[0].capacitemax<=0)
            {
                perso->batiments->chateaux[0].capacitemax=0;
                perso->batiments->chateaux[1].capacitemax=0;
                perso->batiments->chateaux[2].capacitemax=perso->batiments->chateaux[2].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
                if(perso->batiments->chateaux[2].capacitemax<0)
                    perso->batiments->chateaux[2].capacitemax=0;
            }
        }
    }

    if(perso->batiments->nbchateaux==4)
    {
        perso->batiments->chateaux[0].capacitemax=perso->batiments->chateaux[0].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
        if(perso->batiments->chateaux[0].capacitemax<0)
        {
            perso->batiments->chateaux[0].capacitemax=0;
            perso->batiments->chateaux[1].capacitemax=perso->batiments->chateaux[1].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
            if(perso->batiments->chateaux[1].capacitemax<=0 && perso->batiments->chateaux[0].capacitemax<=0)
            {
                perso->batiments->chateaux[0].capacitemax=0;
                perso->batiments->chateaux[1].capacitemax=0;
                perso->batiments->chateaux[2].capacitemax=perso->batiments->chateaux[2].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
                if(perso->batiments->chateaux[2].capacitemax<=0 && perso->batiments->chateaux[1].capacitemax<=0 && perso->batiments->chateaux[0].capacitemax<=0)
                {
                    perso->batiments->chateaux[0].capacitemax=0;
                    perso->batiments->chateaux[1].capacitemax=0;
                    perso->batiments->chateaux[2].capacitemax=0;
                    perso->batiments->chateaux[3].capacitemax=perso->batiments->chateaux[3].capacitemax-perso->batiments->maisons[numero].nbhabitants+tmp;
                    if(perso->batiments->chateaux[3].capacitemax<=0)
                        perso->batiments->chateaux[3].capacitemax=0;
                }
            }
        }
    }
}

