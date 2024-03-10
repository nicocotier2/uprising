#include "header.h"

t_joueur* menus(t_joueur *tour,int* nb_joueur)
{
    show_mouse(screen);
    int choix = 0;
    BITMAP* menu = load_bitmap("menu1.bmp",NULL);
    while (choix == 0)
    {
        int x  = 0;
        int y = 0;
        blit(menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        if (mouse_b & 1)
        {
            x = mouse_x;
            y = mouse_y;
            if (x < 790 && x > 415 && y < 350 && y > 215)
            {
                choix = 1;
            }
        }
    }
    menu  = load_bitmap("nombre_joueurs.bmp",NULL);
    while (* nb_joueur == 0) // choix du nombre de joueur
    {
        blit(menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        if ((mouse_b & 1)&& (mouse_x < 645 && mouse_x > 510 && mouse_y < 300 && mouse_y > 160))
        {
            *nb_joueur = 2;
        }
        else if ((mouse_b & 1)&& (mouse_x < 645 && mouse_x > 510 && mouse_y < 445 && mouse_y > 330))
        {
            *nb_joueur = 3;
        }
        else if ((mouse_b & 1)&& (mouse_x < 645 && mouse_x > 510 && mouse_y < 615 && mouse_y > 500))
        {
            *nb_joueur = 4;
        }
    }
    Sleep(100); // fonction pour mettre de la musique
    tour = realloc(tour,*nb_joueur*(sizeof(t_joueur))); // actualisation de notre tableau des infos des joueurs en fonction du nombre de ceux ci
    menu  = load_bitmap("fond_menu.bmp",NULL);
    BITMAP* perso[4];
    for (int i = 0; i < 4; i++)
    {
        char nom[20];
        sprintf(nom,"perso%d.bmp",i);
        perso[i] = load_bitmap(nom,NULL);
    }
    choix = 0;
    for (int i = 0; i < *nb_joueur; i++)
    {
        choix = 0;
        while (choix == 0)
        {
            for (int j = 0; j < 4; j++)
            {
                draw_sprite(menu,perso[j],j * 300,200);
            }
            blit(menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            if ((mouse_b & 1)&& (mouse_x < 300 && mouse_x > 0 && mouse_y < 600 && mouse_y > 200))
            {
                //remplissage kao
                choix = 1;
                strcpy(tour[i].nom, "Kao");
                tour[i].pv = 400;
                tour[i].pa = 16;
                tour[i].pm = 14;

                strcpy(tour[i].pouvoir[0].nom , "Introduction and Rondo Capriccioso");
                strcpy(tour[i].pouvoir[0].explication , "Kao joue cette œuvre pour violon de Saint-Saens en La Mineur et inflige des degats a distance a l’ennemi");
                tour[i].pouvoir[0].coutPa = 6;
                tour[i].pouvoir[0].degats = 30;
                tour[i].pouvoir[0].precision = 100;
                tour[i].pouvoir[0].porte[0] = 1;
                tour[i].pouvoir[0].porte[1] = 8;
                tour[i].pouvoir[0].effet = 1;

                strcpy(tour[i].pouvoir[1].nom , "Kreutzer");
                strcpy(tour[i].pouvoir[1].explication , "Kao s'approprie de maniere eblouissante cette oeuvre de Beethoven pour se soigner");
                tour[i].pouvoir[1].coutPa = 10;
                tour[i].pouvoir[1].degats = 5;
                tour[i].pouvoir[1].precision = 100;
                tour[i].pouvoir[1].porte[0] = 1;
                tour[i].pouvoir[1].porte[1] = 10;
                tour[i].pouvoir[1].effet = 7; //Reprend des pv (40) (sans utiliser le vol de vie)

                strcpy(tour[i].pouvoir[2].nom , "Ballade no 1 in G Minor");
                strcpy(tour[i].pouvoir[2].explication , "Cette oeuvre de Chopin joué par Kao inflige des degats de base et inflige des degats bruts supplementaires");
                tour[i].pouvoir[2].coutPa = 10;
                tour[i].pouvoir[2].degats = 20 ;
                tour[i].pouvoir[2].precision = 100;
                tour[i].pouvoir[2].porte[0] = 1;
                tour[i].pouvoir[2].porte[1] = 5;
                tour[i].pouvoir[2].effet = 5; //Inflige des dégats supplémentaires(40)

                strcpy(tour[i].pouvoir[3].nom , "Liebesleid");
                strcpy(tour[i].pouvoir[3].explication , "Aussi appelee 'Love's Sorrow', Kao joue cette oeuvre magnifique de Kreisler pour se soigner et infliger de lourds degats");
                tour[i].pouvoir[3].coutPa = 12;
                tour[i].pouvoir[3].degats = 70;
                tour[i].pouvoir[3].precision = 100;
                tour[i].pouvoir[3].porte[0] = 1;
                tour[i].pouvoir[3].porte[1] = 5;
                tour[i].pouvoir[3].effet = 2;

                for (int j = 0; j < 4; j++)
                {
                    char nom[50];
                    sprintf(nom,"cat%d.bmp",j);
                    tour[i].deplacement[j] = load_bitmap(nom,NULL);
                }
                tour[i].base = load_bitmap("cat0.bmp",NULL);
            }
            else if ((mouse_b & 1)&& (mouse_x < 600 && mouse_x > 300 && mouse_y < 600 && mouse_y > 200))
            {
                //remplissage shini
                choix = 1;
                strcpy(tour[i].nom, "Shini");
                tour[i].pv = 400;
                tour[i].pa = 16;
                tour[i].pm = 4;

                strcpy(tour[i].pouvoir[0].nom , "Mach 20");
                strcpy(tour[i].pouvoir[0].explication , "Utilise sa vitesse hypersonique pour attaquer son ennemi a distance");
                tour[i].pouvoir[0].coutPa = 6;
                tour[i].pouvoir[0].degats = 30;
                tour[i].pouvoir[0].precision = 100;
                tour[i].pouvoir[0].porte[0] = 1;
                tour[i].pouvoir[0].porte[1] = 8;
                tour[i].pouvoir[0].effet = 1;

                strcpy(tour[i].pouvoir[1].nom , "Tentacules supersoniques");
                strcpy(tour[i].pouvoir[1].explication , "Shini attaque son ennemi à distance avec ses tentacules supersoniques");
                tour[i].pouvoir[1].coutPa = 10;
                tour[i].pouvoir[1].degats = 40;
                tour[i].pouvoir[1].precision = 100;
                tour[i].pouvoir[1].porte[0] = 1;
                tour[i].pouvoir[1].porte[1] = 6;
                tour[i].pouvoir[1].effet = 1;

                strcpy(tour[i].pouvoir[2].nom , "Mue Assassine");
                strcpy(tour[i].pouvoir[2].explication , "Shini peut muer pour reprendre de la vie tout en infligeant des degats explosifs a l'ennemi proche de lui ");
                tour[i].pouvoir[2].coutPa = 10;
                tour[i].pouvoir[2].degats = 60 ;
                tour[i].pouvoir[2].precision = 100;
                tour[i].pouvoir[2].porte[0] = 1;
                tour[i].pouvoir[2].porte[1] = 3;
                tour[i].pouvoir[2].effet = 3; //cout en pv (50)

                strcpy(tour[i].pouvoir[3].nom , "Armure supreme");
                strcpy(tour[i].pouvoir[3].explication , "Shini essaye d'utiliser son armure ultime pour devenir plus resistant aux attaques des ennemis");
                tour[i].pouvoir[3].coutPa = 12;
                tour[i].pouvoir[3].degats = 5;
                tour[i].pouvoir[3].precision = 3;
                tour[i].pouvoir[3].porte[0] = 1;
                tour[i].pouvoir[3].porte[1] = 10;
                tour[i].pouvoir[3].effet = 11; // +1 d'armure
                for (int j = 0; j < 4; j++)
                {
                    char nom[50];
                    sprintf(nom,"Shini_mouvement_%d.bmp",j+1);
                    tour[i].deplacement[j] = load_bitmap(nom,NULL);
                }
                tour[i].base = load_bitmap("Shini_Sprite_1.bmp",NULL);
            }
            else if ((mouse_b & 1)&& (mouse_x < 900 && mouse_x > 600 && mouse_y < 600 && mouse_y > 200))
            {
                //remplissage azonto
                choix = 1;
                strcpy(tour[i].nom, "Azonto");
                tour[i].pv = 400;
                tour[i].pa = 16;
                tour[i].pm = 4;

                strcpy(tour[i].pouvoir[0].nom , "Excalibur");
                strcpy(tour[i].pouvoir[0].explication , "Inflige des degats magiques au corps-a-corps avec son epee ensorcelée");
                tour[i].pouvoir[0].coutPa = 6;
                tour[i].pouvoir[0].degats = 50;
                tour[i].pouvoir[0].precision = 100;
                tour[i].pouvoir[0].porte[0] = 1;
                tour[i].pouvoir[0].porte[1] = 2;
                tour[i].pouvoir[0].effet = 1;

                strcpy(tour[i].pouvoir[1].nom , "Genie de la Lampe");
                strcpy(tour[i].pouvoir[1].explication , "Azonto utilise sa lampe magique ou il reside pour attaquer lourdement son adversaire ");
                tour[i].pouvoir[1].coutPa = 10;
                tour[i].pouvoir[1].degats = 90;
                tour[i].pouvoir[1].precision = 100;
                tour[i].pouvoir[1].porte[0] = 1;
                tour[i].pouvoir[1].porte[1] = 3;
                tour[i].pouvoir[1].effet = 3; //cout en pv (40)

                strcpy(tour[i].pouvoir[2].nom , "Ton meilleur ami");
                strcpy(tour[i].pouvoir[2].explication , "Le Genie se lance dans un show magique tout en infligeant a l'adversaire de lourds degats");
                tour[i].pouvoir[2].coutPa = 10;
                tour[i].pouvoir[2].degats = 70 ;
                tour[i].pouvoir[2].precision = 100;
                tour[i].pouvoir[2].porte[0] = 1;
                tour[i].pouvoir[2].porte[1] = 3;
                tour[i].pouvoir[2].effet = 1;

                strcpy(tour[i].pouvoir[3].nom , "Puissance Cosmique");
                strcpy(tour[i].pouvoir[3].explication , "Azonto a une chance sur 3 de dechainer toute sa puissance phenomenale vers un ennemi proche de lui et subir une partie de ses degats");
                tour[i].pouvoir[3].coutPa = 12;
                tour[i].pouvoir[3].degats = 100;
                tour[i].pouvoir[3].precision = 3;
                tour[i].pouvoir[3].porte[0] = 1;
                tour[i].pouvoir[3].porte[1] = 2;
                tour[i].pouvoir[3].effet = 3;//cout en PV (40)
                for (int j = 0; j < 4; j++)
                {
                    tour[i].deplacement[j] = load_bitmap("genius.bmp",NULL);
                }
                tour[i].base = load_bitmap("genius.bmp",NULL);
            }
            else if ((mouse_b & 1)&& (mouse_x < 1200 && mouse_x > 900 && mouse_y < 600 && mouse_y > 200))
            {
                //remplissage fawkes
                choix = 1;
                strcpy(tour[i].nom, "Fawkes");
                tour[i].pv = 400;
                tour[i].pa = 16;
                tour[i].pm = 4;

                strcpy(tour[i].pouvoir[0].nom , "Tic Tac Tic Tac Tic Tac");
                strcpy(tour[i].pouvoir[0].explication , "Utilise son lance-grenade pour affaiblir son ennemi a distance");
                tour[i].pouvoir[0].coutPa = 6;
                tour[i].pouvoir[0].degats = 50;
                tour[i].pouvoir[0].precision = 100;
                tour[i].pouvoir[0].porte[0] = 1;
                tour[i].pouvoir[0].porte[1] = 8;
                tour[i].pouvoir[0].effet = 1;

                strcpy(tour[i].pouvoir[1].nom , "C est de la bombe");
                strcpy(tour[i].pouvoir[1].explication , "Lance une bombe qu’il fait exploser lorsqu’elle atteint l’ennemi");
                tour[i].pouvoir[1].coutPa = 10;
                tour[i].pouvoir[1].degats = 80;
                tour[i].pouvoir[1].precision = 100;
                tour[i].pouvoir[1].porte[0] = 4;
                tour[i].pouvoir[1].porte[1] = 6;
                tour[i].pouvoir[1].effet = 1;

                strcpy(tour[i].pouvoir[2].nom , "Barbecue, Quelquun ?");
                strcpy(tour[i].pouvoir[2].explication , "Utilise son lance-flamme a distance mais s inflige aussi des degats a lui-meme dans sa folie devastatrice");
                tour[i].pouvoir[2].coutPa = 10;
                tour[i].pouvoir[2].degats = 80 ;
                tour[i].pouvoir[2].precision = 33;
                tour[i].pouvoir[2].porte[0] = 4;
                tour[i].pouvoir[2].porte[1] = 8;
                tour[i].pouvoir[2].effet = 3; //cout en pv (50)

                strcpy(tour[i].pouvoir[3].nom , "Kaboum !");
                strcpy(tour[i].pouvoir[3].explication , "Fawkes deplace a distance un pneu explosif qui une fois declenche fait des degats de zone devastateur");
                tour[i].pouvoir[3].coutPa = 12;
                tour[i].pouvoir[3].degats = 100;
                tour[i].pouvoir[3].precision = 100;
                tour[i].pouvoir[3].porte[0] = 1;
                tour[i].pouvoir[3].porte[1] = 5;
                tour[i].pouvoir[3].effet = 1;
                for (int j = 0; j < 4; j++)
                {
                    char nom[50];
                    sprintf(nom,"Fawkes_mouvement_%d.bmp",j+1);
                    tour[i].deplacement[j] = load_bitmap(nom,NULL);
                }
                tour[i].base = load_bitmap("Fawkes_Sprite_1.bmp",NULL);
            }
            tour[0].position[0] = 4 * 32;
            tour[0].position[1] = 3 * 32;
            tour[1].position[0] = 16 * 32;
            tour[1].position[1] = 2 * 32;
            if (*nb_joueur > 2)
            {
                tour[2].position[0] = 1 * 32;
                tour[2].position[1] = 17 * 32;

            }
            if (*nb_joueur > 3)
            {
                tour[3].position[0] = 13 * 32;
                tour[3].position[1] = 17 * 32;

            }
        }
    Sleep(100);
    }
    return(tour);
}
