#include "header.h"

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