#include "header.h"

///INITIALISATION D'ALLEGRO
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

///ALLOCATION ET INITIALISATION DE LA STRUCTURE DU JOUEUR (PERSO)
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
    perso->g = creaGraphe();

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

    for(int i=0;i<LIGNES;i++)
    {
        perso->route[i][0]=7;
        perso->route[i][44]=7;
    }

    for(int j=0;j<COLONNES;j++)
    {
        perso->route[0][j]=7;
        perso->route[34][j]=7;
    }

    ///INITIALISATION STRUCTURE BATIMENTS
    perso->batiments=(t_bat4*)malloc(sizeof(t_bat4));

    perso->batiments->nbmaisons=0;
    perso->batiments->nbcentrales=0;
    perso->batiments->nbchateaux=0;
    perso->batiments->nbruines=0;

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

///INITIALISATION DE LA STRUCTURE BITMAP
void StructureBitmapInit(t_bitmap* images)
{
    images->map0 = load_bitmap("Bitmaps/map.bmp",NULL);
    images->map1 = load_bitmap("Bitmaps/Egouts.bmp",NULL);
    images->map2 = load_bitmap("Bitmaps/zaapmap.bmp",NULL);
    images->fond0 = load_bitmap("Bitmaps/ecrandejeu.bmp",NULL);
    images->fond1 = load_bitmap("Bitmaps/ecranreseaudeau.bmp",NULL);
    images->fond2 = load_bitmap("Bitmaps/ecranreseaudelec.bmp",NULL);
    images->dieu = load_bitmap("Bitmaps/dieu.bmp",NULL);
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
    images->gameover = load_bitmap("Bitmaps/gameoversimpson.bmp",NULL);
}


