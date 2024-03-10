#include "header.h"

void jeu(int nb_joueur, t_joueur* tour, int terrain[21][21])
{
    int quel_joueur = 0;// variable qui nous dit c'est à quelle joueur de jouer
    BITMAP* decor = load_bitmap("decor_final_2.bmp",NULL);
    BITMAP* buffer = create_bitmap(1200,700);
    while (!key[KEY_ESC] || nb_joueur == 1)//on continue tant que l'on ne veut pas arreter ou lorsqu'un seul joueur est en vie
    {
        //PlaySound("musique_uprising_projet_info.wav", NULL, SND_FILENAME | SND_SYNC); // fonction pour mettre de la musique
        int fin = 0;
        while (fin == 0)
        {

            if ((mouse_b & 1)&& mouse_x < 672 && mouse_y < 672)
            {
                 dessin(tour,terrain,quel_joueur,nb_joueur,decor,buffer);// fonction de deplacement du joueur
                 Sleep(200);// on met des sleep pour eviter que le programme ne pense que l'on clique plusieurs fois
            }


            if ((mouse_b & 1)&& mouse_x < 1000 && mouse_x > 700 && mouse_y < 125 && mouse_y > 105)
            {
                //printf("1");
                //sleep(200);
                attaque(quel_joueur,nb_joueur,tour,0,terrain,decor,buffer);
            }
            if ((mouse_b & 1)&& mouse_x < 1000 && mouse_x > 700 && mouse_y < 145 && mouse_y > 125)
            {
                sleep(200);
                attaque(quel_joueur,nb_joueur,tour,1,terrain,decor,buffer);
            }
            if ((mouse_b & 1)&& mouse_x < 1000 && mouse_x > 700 && mouse_y < 165 && mouse_y > 145)
            {
                sleep(200);
                attaque(quel_joueur,nb_joueur,tour,2,terrain,decor,buffer);
            }
            if ((mouse_b & 1)&& mouse_x < 1000 && mouse_x > 700 && mouse_y < 185 && mouse_y > 165)
            {
                sleep(200);
                attaque(quel_joueur,nb_joueur,tour,3,terrain,decor,buffer);
            }

            //fonction attaque
            affichage_jeu(nb_joueur,tour,quel_joueur,decor,buffer,1);//on affiche le plateau de jeu actualisé
            if (mouse_b & 2)
                {
                    Sleep(200);
                    fin = 1;
                    tour[quel_joueur].pm = 4;
                    tour[quel_joueur].pa = 16;
                }
        }
        quel_joueur++;
        if (quel_joueur == nb_joueur)
        {
            quel_joueur = 0;
        }
    }
}

void affichage_jeu(int nb_joueur, t_joueur* tour, int a_qui,BITMAP* decor, BITMAP* buffer,int coul)
{
    int x = mouse_x / 32;
    x  = x * 32;
    int y = mouse_y / 32;
    y  = y * 32;
    blit(decor,buffer,0,0,0,0,1200,700);
    if (x < 672 && y < 672 && coul == 1)
        {
            rect(buffer, x , y, x + 32, y + 32, makecol(255,255,0));
        }
    else if (x < 672 && y < 672 && coul == 2)
        {
            rect(buffer, x , y, x + 32, y + 32, makecol(255,0,0));
        }
    for (int i = 0; i < nb_joueur; i++)
    {
        draw_sprite(buffer,tour[i].base,tour[i].position[0],tour[i].position[1]);// affichage des bitmaps des joueurs
        textprintf_ex(buffer,font,700,20+(10*i),makecol(255,255,255),0,"%s",tour[i].nom);//affichage de l'ordre des joueurs
    }
    // affichage des pv, des pm, des pa et des capacités
    textprintf_ex(buffer,font,700,60,makecol(255,0,0),0,"pv : %d",tour[a_qui].pv);
    textprintf_ex(buffer,font,700,70,makecol(0,255,0),0,"pm : %d",tour[a_qui].pm);
    textprintf_ex(buffer,font,700,80,makecol(0,0,255),0,"pa : %d",tour[a_qui].pa);
    textprintf_ex(buffer,font,700,90,makecol(255,255,255),"c'est le tour de : %s",tour[a_qui].nom);
    textprintf_ex(buffer,font,700,110,makecol(255,255,255),"%s",tour[a_qui].pouvoir[0].nom);
    textprintf_ex(buffer,font,700,140,makecol(255,255,255),"%s",tour[a_qui].pouvoir[1].nom);
    textprintf_ex(buffer,font,700,170,makecol(255,255,255),"%s",tour[a_qui].pouvoir[2].nom);
    textprintf_ex(buffer,font,700,200,makecol(255,255,255),"%s",tour[a_qui].pouvoir[3].nom);
    blit(buffer,screen,0,0,0,0,1200,700);
}

void dessin(t_joueur *tour, int terrain[21][21],int tours, int nb_joueur, BITMAP* decor2, BITMAP* page)
{
    int clicx = mouse_x /32;//ici on a besoin des coordonné dans la matrice de la case que le joueur selectionne
    int clicy = mouse_y /32; //on garde en mémoire le clic de lutilisateur
    int test_x = (tour[tours].position[0])/ 32 - clicx;
    if (test_x < 0)
    {
        test_x = test_x * (-1);
    }
    int test_y = (tour[tours].position[1])/ 32 - clicy;
    if (test_y < 0)
    {
        test_y = test_y * (-1);
    }
    if (terrain[clicy][clicx] == 4 && (tour[tours].pm > 0)&&((test_x == 1 && test_y == 0)||(test_x == 0 && test_y == 1)))
    {
        terrain[(tour[tours].position[1])/32][(tour[tours].position[0])/32] = 4;
        tour[tours].pm --;
        terrain[clicy][clicx] = tours;
        int i = 0;
        while (tour[tours].position[0] != clicx * 32 || tour[tours].position[1] != clicy * 32)
        {
            //printf("non");
            blit(decor2,page,0,0,0,0,SCREEN_W,SCREEN_H);
            if (tour[tours].position[0]< clicx * 32) //si le perso est a gauche de lendroit darrivee
                tour[tours].position[0]++ ; // on augmente labcisse du perso > on va a droite

            else if (tour[tours].position[0] > clicx * 32) //si le perso est a gauche de lendroit darrivee
                tour[tours].position[0]--;// on diminue labcisse du perso > on va a gauche


            else if (tour[tours].position[1] < clicy * 32) //si le perso est en haut de lendroit darrivee
                tour[tours].position[1]++;// on augmente l'oordonnee du perso > on va en bas


            else if (tour[tours].position[1] > clicy * 32) //si le perso est en bas de lendroit darrivee
                tour[tours].position[1]--;// on diminue l'ordonnee du perso > on va en haut

            for (int j = 0; j < nb_joueur; j++)
            {
                if (j == tours)
                {
                    draw_sprite(page, tour[j].deplacement[i], tour[j].position[0],tour[j].position[1]);
                }
                else
                {
                    draw_sprite(page, tour[j].base, tour[j].position[0],tour[j].position[1]);
                }
            }
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            rest(30);
            i++;
            if (i == 4)
                i = 0;
        }
        terrain[(tour[tours].position[1])/32][(tour[tours].position[0])/32] = tours;
    }
}

