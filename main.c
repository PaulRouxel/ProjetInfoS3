#include "header.h"

int main()
{
    initialisationAllegro();                                    ///routine d'initialisation d'Allegro
    srand(time(NULL));                               ///routine pour mettre le temps à 0
    t_joueur* homer=(t_joueur*)malloc(sizeof(t_joueur));   ///allocation dynamique de la structure joueur
    t_bitmap* images=(t_bitmap*)malloc(sizeof(t_bitmap));  ///allocation dynamique de la structure des bitmaps
    MenuDemarrage(homer,images);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
