#include "header.h"


graphe * creaGraphe()
{
    graphe * g;
    g=(graphe*)malloc(sizeof(graphe));
    g->tab_sommet=(sommet*)malloc(500*sizeof(sommet));
    g->tab_arete=(arete*)malloc(1500*sizeof(arete));
    g->ordre=0;
    g->taille=0;
    return g;
}

///permet de remettre le graphe à 0 avec les bonne couleurs pour le prochain algorithme de recherche
void initgraphe(t_joueur* perso)
{
    for(int i=0; i<perso->g->ordre;i++)
    {
        perso->g->tab_sommet[i].blanc=1;
        perso->g->tab_sommet[i].noir=0;
        perso->g->tab_sommet[i].gris=0;
    }

}
///permet de mettre à jour le graphe avec les nouveaux batiments ajoutés
/// route -> 0
/// maison -> 1
/// centrale -> 2
/// chateau -> 3

void editgraphe(t_joueur* perso,int indice, int x, int y)
{
    perso->g->tab_sommet[perso->g->ordre].type=indice;
    perso->g->tab_sommet[perso->g->ordre].x=x;
    perso->g->tab_sommet[perso->g->ordre].y=y;
    perso->g->tab_sommet[perso->g->ordre].blanc=1;
    perso->g->tab_sommet[perso->g->ordre].noir=0;
    perso->g->tab_sommet[perso->g->ordre].gris=0;

    perso->g->tab_sommet[perso->g->ordre].nb_succ=0;
    if(indice==0)///si on ajoute une route
    {
        perso->g->tab_sommet[perso->g->ordre].tabsucc=(sommet *) malloc(sizeof (sommet)* 4);
        ///recherche dans les 4 directions autour de la route si il y a une autre route
        for(int i=0;i<perso->g->ordre;i++)
        {
            if((perso->g->tab_sommet[perso->g->ordre].x+1==perso->g->tab_sommet[i].x && perso->g->tab_sommet[perso->g->ordre].y==perso->g->tab_sommet[i].y) ||
               (perso->g->tab_sommet[perso->g->ordre].x-1==perso->g->tab_sommet[i].x && perso->g->tab_sommet[perso->g->ordre].y==perso->g->tab_sommet[i].y) ||
               (perso->g->tab_sommet[perso->g->ordre].y+1==perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y-1==perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x==perso->g->tab_sommet[i].x) )
            {
                perso->g->tab_sommet[perso->g->ordre].tabsucc[perso->g->tab_sommet[perso->g->ordre].nb_succ] = perso->g->tab_sommet[i];///on l'enregistre dans tabsucc
                perso->g->tab_sommet[perso->g->ordre].nb_succ++;///si oui on l'enregistre dans tabsucc
                perso->g->tab_sommet[i].tabsucc[perso->g->tab_sommet[i].nb_succ] = perso->g->tab_sommet[perso->g->ordre];
                perso->g->tab_sommet[i].nb_succ++;///mutuellement
                ///et on enregistre une nouvelle arete
                perso->g->tab_arete[perso->g->taille].a=perso->g->tab_sommet[i];///sommet a
                perso->g->tab_arete[perso->g->taille].b=perso->g->tab_sommet[perso->g->ordre];///sommet b
                perso->g->tab_arete[perso->g->taille].poids=1;///poids
                perso->g->taille++;
            }
        }
    }
    else if(indice == 1)///si on ajoute une maison
    {
        perso->g->tab_sommet[perso->g->ordre].tabsucc=(sommet *) malloc(sizeof (sommet)* 9);
        ///recherche dans les 4 directions autour de la route si il y a un sommet
        for(int i=0;i<perso->g->ordre;i++)
        {
            ///recherche tout autour de la maison pour trouver des routes
            if((perso->g->tab_sommet[perso->g->ordre].y + 2 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x-1==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y + 2 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x+1==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y + 2 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y - 2 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x-1==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y - 2 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x+1==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y - 2 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y - 1 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x-2==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y + 1 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x-2==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x-2==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y -1 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x+2==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y +1 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x+2==perso->g->tab_sommet[i].x) ||
               (perso->g->tab_sommet[perso->g->ordre].y == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x+2==perso->g->tab_sommet[i].x) )
            {
                perso->g->tab_sommet[perso->g->ordre].tabsucc[perso->g->tab_sommet[perso->g->ordre].nb_succ] = perso->g->tab_sommet[i];///on l'enregistre dans le tabsucc
                perso->g->tab_sommet[perso->g->ordre].nb_succ++;///on augmente le nombre de succ
                perso->g->tab_sommet[i].tabsucc[perso->g->tab_sommet[i].nb_succ] = perso->g->tab_sommet[perso->g->ordre];
                perso->g->tab_sommet[i].nb_succ++;///mutuellement
                ///et on enregistre une nouvelle arete
                perso->g->tab_arete[perso->g->taille].a=perso->g->tab_sommet[i];///sommet a
                perso->g->tab_arete[perso->g->taille].b=perso->g->tab_sommet[perso->g->ordre];///sommet b
                perso->g->tab_arete[perso->g->taille].poids=1;///poids
                perso->g->taille++;
            }
        }

    }
    else if(indice == 2 || indice == 3)///si on ajoute une centrale ou un chateau
    {
        perso->g->tab_sommet[perso->g->ordre].tabsucc = (sommet *) malloc(sizeof(sommet) * 20);
        ///recherche dans les 4 directions autour de la route si il y a un sommet
        for (int i = 0; i < perso->g->ordre; i++) {
            ///recherche tout autour de la centrale/chateau pour trouver des routes
            if ((perso->g->tab_sommet[perso->g->ordre].y - 3 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x - 1 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y - 3 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y - 3 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x + 1 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y - 3 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x + 2 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y + 4 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x - 1 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y + 4 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y + 4 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x + 1 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y + 4 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x + 2 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y - 2 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y - 1 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x - 1 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x + 1 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y + 1 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y + 2 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x - 2 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y + 3 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x - 2 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y - 2 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x - 2 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y - 1 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x - 2 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x - 2 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y + 1 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x + 2 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y + 2 == perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x + 2 == perso->g->tab_sommet[i].x) ||
                (perso->g->tab_sommet[perso->g->ordre].y + 3== perso->g->tab_sommet[i].y && perso->g->tab_sommet[perso->g->ordre].x + 2 == perso->g->tab_sommet[i].x) )
            {
                perso->g->tab_sommet[perso->g->ordre].tabsucc[perso->g->tab_sommet[perso->g->ordre].nb_succ] = perso->g->tab_sommet[i];///on l'enregistre dans le tabsucc
                perso->g->tab_sommet[perso->g->ordre].nb_succ++;///on augmente le nombre de succ
                perso->g->tab_sommet[i].tabsucc[perso->g->tab_sommet[i].nb_succ] = perso->g->tab_sommet[perso->g->ordre];
                perso->g->tab_sommet[i].nb_succ++;///mutuellement
                ///et on enregistre une nouvelle arete
                perso->g->tab_arete[perso->g->taille].a = perso->g->tab_sommet[i];///sommet a
                perso->g->tab_arete[perso->g->taille].b = perso->g->tab_sommet[perso->g->ordre];///sommet b
                perso->g->tab_arete[perso->g->taille].poids = 1;///poids
                perso->g->taille++;
            }
        }
    }
    perso->g->ordre++;
}

void affichage_sommet(graphe* g)            //Affichage basique de chaque element du graphe
{
    printf("Ordre : %d \n",g->ordre);

    for(int i=0;i<g->ordre;i++)
    {
        printf("Sommet : %d \n",g->tab_sommet[i].type);
    }
    printf("Taille : %d\n",g->taille);
    printf("Aretes :\n");

    for(int i=0;i<g->taille;i++)
    {
        printf("%d, %d --> %d\n",g->tab_arete[i].a.type,g->tab_arete[i].b.type,g->tab_arete[i].poids);
    }
    for(int i=0;i<g->ordre;i++)
    {
        printf("\n Sommet %d :  \n",i);
        for(int j=0;j<g->tab_sommet[i].nb_succ;j++) {
            printf(" %d avec ",g->tab_sommet[i].tabsucc[j].type);
            printf(" x : %d",g->tab_sommet[i].tabsucc[j].x);
            printf("et y : %d",g->tab_sommet[i].tabsucc[j].y);
        }
    }
}

///permet de transformer des coordonnées d'un sommet en son indice dans le graphe
int transformerswoow(graphe* g, int x, int y)
{
    for(int i=0;i<g->ordre;i++)
    {
        if(g->tab_sommet[i].x == x && g->tab_sommet[i].y == y)
        {
            return i;
        }
    }
}

///permet de rechercher le poids et donc la distance entre deux sommet du graphe crée par les batiments et routes
void dijkstra(graphe* g, int debut, int fin, maillon* tabmaillon)
{
    int k=0,poids=0,memoire;
    int indice;
    int tabResultat[8];
    int NbSomResultat;
    tabmaillon[k].act = g->tab_sommet[debut];    //Initialisation du premier element avec le debut
    tabmaillon[k].PoidRelatif=0;            //Initialisation du poid qui servira a calculer le poid total de chaque chemin
    tabmaillon[k].pred.num=-1;          //Initialisation pour la fin du programme
    memoire=k;
    k++;
    while(memoire<9){//parcours de la file
        tabmaillon[memoire].act.noir=1;
        for(int i=0; i<tabmaillon[memoire].act.nb_succ;i++)//parcours des successeurs
        {
            for(int j=0;j<g->ordre;j++)
            {
                if(tabmaillon[j].act.num == tabmaillon[memoire].act.tabsucc[i].num)
                {
                    if(tabmaillon[j].act.noir==1 && tabmaillon[j].act.num!=fin) {
                        tabmaillon[memoire].act.tabsucc[i].noir = 1; //Verification des sommets noirs, impossible si le sommet est notre fin
                    }
                }
            }
            if(tabmaillon[memoire].act.tabsucc[i].noir!=1) { //vérification de si le successeur n'est pas déjà noir
                for(int j=0;j<g->ordre;j++)
                {
                    if(tabmaillon[j].act.num == tabmaillon[memoire].act.tabsucc[i].num)
                    {   //Remise en gris des successeurs qui sont deja gris
                        if(tabmaillon[j].act.gris==1) {
                            tabmaillon[memoire].act.tabsucc[i].gris = 1;
                        }
                    }
                }
                if (tabmaillon[memoire].act.tabsucc[i].gris !=1) //Verif si gris
                {
                    ///PAS GRIS
                    /*
                     * Modif du sommet exploré :
                     * Calcul du poids total
                     * Initialisation predecesseur
                     * Passage en  Gris
                     * */
                    tabmaillon[k].act=g->tab_sommet[tabmaillon[memoire].act.tabsucc[i].num];
                    //poids=recherchesommet(g,tabmaillon[memoire].act.num,tabmaillon[k].act.num);
                    tabmaillon[k].PoidRelatif = tabmaillon[memoire].PoidRelatif+poids;
                    tabmaillon[k].pred=tabmaillon[memoire].act;
                    tabmaillon[k].act.gris=1;
                    k++;

                }
                else
                {
                    ///GRIS
                    /*
                     * Modif du sommet exploré :
                     * Calcul du poids total
                     * Comparaison poids avec l'ancien
                     * SI poid avantageux, changer :
                     *      Predecesseur
                     *      Poids
                     *
                     *      Boucle :
                     *      Rechercher l'indice de celui qui est gris
                     *      recup l'indice dans GrisIndice
                     *
                     * */
                    int GrisIndice;

                    for(int j=0;j<g->ordre;j++)
                    {
                        if(tabmaillon[j].act.num == tabmaillon[memoire].act.tabsucc[i].num)
                        {
                            GrisIndice=j;
                        }
                    }
                    int poidcomp;
                    //poids=recherchesommet(g,tabmaillon[memoire].act.num,tabmaillon[GrisIndice].act.num);
                    poidcomp=tabmaillon[memoire].PoidRelatif+poids;
                    if(tabmaillon[GrisIndice].PoidRelatif>poidcomp)
                    {
                        tabmaillon[GrisIndice].PoidRelatif = poidcomp;
                        tabmaillon[GrisIndice].pred=tabmaillon[memoire].act;
                    }
                }
            }
        }
        memoire++;
    }
    /*
     * -Recuperation de l'indice du sommet de fin dans le maillon
     * -Remplir un tableau avec chaque sommet jusqu'au sommet de début
     * -Affichage du tableau à l'envers et du poid total du chemin
     * */
    for(int i=0;i<9;i++)
    {
        if(fin == tabmaillon[i].act.num)
        {
            indice=i;
        }
    }
    NbSomResultat=0;
    while(tabmaillon[indice].pred.num!=-1)//NB SOM RES Jusqu'a fin
    {
        tabResultat[NbSomResultat]=tabmaillon[indice].act.num;
        NbSomResultat++;
        for(int i=0;i<9;i++)
        {
            if(tabmaillon[i].act.num == tabmaillon[indice].pred.num)
            {
                indice=i;
            }
        }
    }

    printf("\nChemin : ");
    printf("%d",g->tab_sommet[debut].num);
    for(int i=0;i<NbSomResultat;i++)
    {
        printf("--> %d ",tabResultat[NbSomResultat-1-i]);
    }

    for(int i=0;i<9;i++)
    {
        if(fin == tabmaillon[i].act.num)
        {
            indice=i;
        }
    }
    printf("\nPoids total du chemin : %d",tabmaillon[indice].PoidRelatif);
}
