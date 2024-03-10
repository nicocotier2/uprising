#include "header.h"

int main()
{
    int terrain[21][21]=
{
    {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
    {5,4,4,4,4,4,5,5,4,4,4,4,5,5,4,4,4,4,4,5,5},
    {5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
    {5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
    {5,4,4,4,4,4,4,4,5,5,4,4,5,5,4,5,4,4,5,4,5},
    {5,4,4,4,5,5,4,4,5,5,4,4,5,5,5,5,4,4,5,5,5},
    {5,4,4,4,5,5,4,4,4,4,4,4,5,5,5,5,4,4,5,5,5},
    {5,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,4,4,5,5,5},
    {5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
    {5,5,5,5,5,5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,5},
    {5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,4,4,4,5},
    {5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,5,4,4,5},
    {5,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,4,5},
    {5,4,5,5,5,5,5,5,5,5,4,4,4,4,5,5,5,5,5,5,5},
    {5,4,5,5,5,5,5,5,5,5,4,4,4,4,5,5,5,5,5,5,5},
    {5,4,5,5,5,5,5,5,5,5,4,4,4,4,5,5,5,5,5,5,5},
    {5,4,5,5,5,5,5,5,5,5,4,4,4,4,5,5,5,5,5,4,5},
    {5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
    {5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
    {5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
    {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},

};

    allegro_init();
    install_keyboard();
    install_mouse();
    show_mouse(screen);

    set_color_depth(desktop_color_depth());
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,700,0,0)!=0)
    {
        allegro_message("pb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    int nb_joueur = 0;
    t_joueur* tour = NULL;
    tour = (t_joueur*)malloc(sizeof(t_joueur));//ce tableau contient toutes les informations de chaque joueur ainsi que l'ordre de passage;
    tour = menus(tour,&nb_joueur); //on va connaitre ici le nombre de joueur et on va remplir le tableau des infos des joueurs
    jeu(nb_joueur,tour,terrain);// c'est dans ce sous programme que va se derouler le jeu
    free(tour);

    return 0;

}END_OF_MAIN();

/* liens utilisé pr le code:
https://allegro.developpez.com/5/livre/?page=page_10
https://codes-sources.commentcamarche.net/source/43580-jeu-de-plateforme-allegro
https://szadiart.itch.io/houses-pack/download/eyJpZCI6NjE1MjcwLCJleHBpcmVzIjoxNjUyOTg3NjAxfQ%3d%3d.Ov%2fmAWbCVM%2bVZeGZXqmb21gyC4M%3d
https://codes-sources.commentcamarche.net/source/31767-dessin-d-un-bouton-a-enfoncer-en-allegro-c
https://forums.commentcamarche.net/forum/affich-12318693-allegro-souris
https://www.developpez.net/forums/d728575/applications/developpement-2d-3d-jeux/api-graphiques/allegro/clic-souris-deplacement/
*/
