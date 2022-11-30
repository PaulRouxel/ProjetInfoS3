#include "header.h"


int recupid(t_joueur * perso, int x, int y)
{
    for(int i=0;i<perso->batiments->nbmaisons;i++)
    {
        if(perso->batiments->maisons[i].x == x && perso->batiments->maisons[i].y == y)
        {
            return i;
        }
    }
}


void cherchercentrale(t_joueur* perso)
{
    int compconnexe[perso->g->ordre];
    int nbsom=0;
    compconnexe[nbsom]=perso->g->tab_sommet[perso->g->ordre].num;
    nbsom++;
    for(int i=0;i<nbsom-1;i++)
    {
        for(int j=0;j<perso->g->taille;j++)
        {
            if(compconnexe[i] == perso->g->tab_arete[j].a.num)
            {
                compconnexe[nbsom]=perso->g->tab_arete[i].b.num;
                nbsom++;
                if(perso->g->tab_arete[i].b.type == 2)
                {
                    perso->batiments->centrales->alimentees[perso->batiments->centrales->nbalim][0]=perso->batiments->nbmaisons;
                    perso->batiments->centrales->alimentees[perso->batiments->centrales->nbalim][1]=perso->batiments->maisons[perso->batiments->nbmaisons].nbhabitants;
                    perso->batiments->centrales->alimentees[perso->batiments->centrales->nbalim][2]=0; //sad
                    perso->batiments->centrales->nbalim++;
                }
            }
            else if(perso->g->tab_sommet[perso->g->ordre].num == perso->g->tab_arete[j].b.num)
            {
                compconnexe[nbsom]=perso->g->tab_arete[i].a.num;
                nbsom++;
                if(perso->g->tab_arete[i].a.type == 2)
                {
                    perso->batiments->centrales->alimentees[perso->batiments->centrales->nbalim][0]=perso->g->tab_sommet[perso->g->ordre].num;
                    perso->batiments->centrales->alimentees[perso->batiments->centrales->nbalim][1]=perso->batiments->maisons[perso->batiments->nbmaisons].nbhabitants;
                    perso->batiments->centrales->alimentees[perso->batiments->centrales->nbalim][2]=0; //sad
                    perso->batiments->centrales->nbalim++;
                }
            }
        }

    }
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
                {
                    peutevo = 1;
                    return peutevo;
                }
                else
                    peutevo=0;
            }
        }
    }
    return peutevo;
}