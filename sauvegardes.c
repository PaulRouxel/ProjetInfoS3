#include "header.h"


///ECRITURE DE L'ETAT DE LA CARTE DANS UN FICHIER TEXTE, UNE VERSION LISIBLE POUR L'HUMAIN ET L'AUTRE PAR L'ORDINATEUR
void SauvegardeMap(t_joueur* perso)
{
    FILE* fichier1 = NULL;
    fichier1 = fopen("map.txt", "w+");

    if (fichier1 != NULL)
    {
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++)
            {
                if(perso->route[i][j]<10)
                    fprintf(fichier1," %d ", perso->route[i][j]); ///permet d'avoir une matrice bien affichée et régulière
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
            for (int j = 0; j < COLONNES; j++)
            {
                fprintf(fichier4,"%d ", perso->route[i][j]); ///matrice écrite telle que
            }
            fprintf(fichier4,"\n");
        }
        fclose(fichier4);
    }
}

///ECRITURE DES INFORMATIONS DU JOUEUR DANS UN FICHIER TEXTE, UNE VERSION LISIBLE PAR L'HUMAIN ET L'AUTRE PAR L'ORDINATEUR
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

///PERMET DE CHARGER UNE PARTIE PRECEDENTE ET DE RELANCER LE JEU
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

