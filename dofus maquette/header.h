#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
//#include<windows.h>

typedef struct
{
    char nom[50];
    int coutPa;
    int precision;
    int degats;
    int porte[2];
    int effet;
    char explication[200];
}t_sort;

typedef struct
{
    char nom[20];
    int pa;
    int pm;
    int pv;
    t_sort pouvoir[4];
    int armure;
    int position[2];//les coordonés du joueur sur la bitmap(pour l'affichage)
    BITMAP* deplacement[4];// les bitmaps du perso quand il se deplace
    BITMAP* attaque[4]; // les bitmap du perso quand il attaque
    BITMAP* base;
}t_joueur;

t_joueur* menus(t_joueur *tour,int* nb_joueur);
void jeu(int nb_joueur, t_joueur* tour, int terrain[21][21]);
void dessin(t_joueur* tour, int terrain[21][21],int tours, int nb_joueur,BITMAP* decor2,BITMAP* page);
void affichage_jeu(int nb_joueur, t_joueur* tour, int a_qui,BITMAP* decor, BITMAP* buffer, int coul);
int test_porte(t_joueur attaquant, t_joueur victime, int lequel);
void attaque(int a_qui, int nb_joueur, t_joueur* tour, int lequel, int plato[21][21],BITMAP* decor,BITMAP* buffer);
#endif // HEADER_H_INCLUDED
