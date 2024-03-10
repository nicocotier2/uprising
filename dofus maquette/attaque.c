#include "header.h"

void attaque(int a_qui, int nb_joueur, t_joueur* tour, int lequel, int plato[21][21],BITMAP* decor,BITMAP* buffer)
/* lequel est le numero du sort utilisé
a_qui est le numero joueur a qui c'est le tour
*/
{
    int choix = 0; // le choix de la victime
    int retour = 0;
    while (choix == 0 && retour == 0)// tant que le joueur ne clique pas sur la case sur laquelle se situe un joueur ou sur la case retour
    {

        int x = mouse_x;
        int y = mouse_y;
        x = x / 32;
        y = y / 32;
        if (mouse_b &1 && plato[y][x] >= 0 && plato[y][x] <= 3) //si le joueur clique sur un perso
        {
            choix = 1;
            int test = test_porte(tour[a_qui], tour[plato[y][x]], lequel);
            //printf("%d",test);
            if (test == 0 && tour[a_qui].pa >= tour[a_qui].pouvoir[lequel].coutPa) //si le joueur est à porté
            {
                //printf("3");
                tour[a_qui].pa = tour[a_qui].pa - tour[a_qui].pouvoir[lequel].coutPa;
                int al = rand() % tour[a_qui].pouvoir[lequel].precision; // pour le test de precision

                if (al == 1)//on test si l'attaque touche ou non
                {
                    test = 1; // si on tire 1 l'attaque ne touche pas
                }
                if (test == 0)// si l'attaque est réussi
                {
                    //printf("4");
                    al = (rand() % tour[a_qui].pouvoir[lequel].degats) - ((tour[a_qui].pouvoir[lequel].degats) / 2); // on calcule la quantité de degat
                    int degat = (tour[a_qui].pouvoir[lequel].degats + al)/tour[plato[y][x]].armure;
                    if (degat > 0)
                    {
                        //printf("2");
                        tour[plato[y][x]].pv = tour[plato[y][x]].pv - degat;
                        //ici on peut rajouter les effets secondaire comme du vol de vie
                        if ((tour[a_qui].pouvoir[lequel].effet)/2)
                        {
                            tour[a_qui].pv = tour[a_qui].pv + degat;
                            if (tour[a_qui].pv > 400)
                            {
                                tour[a_qui].pv = 400;
                            }
                        }
                        if ((tour[a_qui].pouvoir[lequel].effet)/3)
                        {
                            tour[a_qui].pv = tour[a_qui].pv - 50;
                        }
                        if ((tour[a_qui].pouvoir[lequel].effet)/5)
                        {
                            tour[plato[y][x]].pv = tour[plato[y][x]].pv - 70;
                        }
                        if ((tour[a_qui].pouvoir[lequel].effet)/7)
                        {
                            tour[a_qui].pv = tour[a_qui].pv + 100;
                            if (tour[a_qui].pv > 400)
                            {
                                tour[a_qui].pv = 400;
                            }
                        }
                        if ((tour[a_qui].pouvoir[lequel].effet)/11)
                        {
                            tour[a_qui].armure = tour[a_qui].armure + 1;
                        }

                        //animation de l'attaque

                        // ensuite on fait le test du game over pour les 2 joueurs
                        if (tour[a_qui].pv <=0)
                        {
                            for(int i = a_qui; i < nb_joueur - 1;i++)
                            {
                                tour[i].pv = tour[i+1].pv;
                                tour[i].position[0] = tour[i+1].position[0];
                                tour[i].position[1] = tour[i+1].position[1];
                                strcpy(tour[i].pouvoir[0].nom , tour[i+1].pouvoir[0].nom);
                                strcpy(tour[i].pouvoir[0].explication , tour[i+1].pouvoir[0].explication);
                                tour[i].pouvoir[0].coutPa = tour[i+1].pouvoir[0].coutPa;
                                tour[i].pouvoir[0].degats = tour[i+1].pouvoir[0].degats;
                                tour[i].pouvoir[0].precision = tour[i+1].pouvoir[0].precision;
                                tour[i].pouvoir[0].porte[0] = tour[i+1].pouvoir[0].porte[0];
                                tour[i].pouvoir[0].porte[1] = tour[i+1].pouvoir[0].porte[1];
                                tour[i].pouvoir[0].effet = tour[i+1].pouvoir[0].effet;

                                strcpy(tour[i].pouvoir[1].nom , tour[i+1].pouvoir[1].nom);
                                strcpy(tour[i].pouvoir[1].explication , tour[i+1].pouvoir[1].explication);
                                tour[i].pouvoir[1].coutPa = tour[i+1].pouvoir[1].coutPa;
                                tour[i].pouvoir[1].degats = tour[i+1].pouvoir[1].degats;
                                tour[i].pouvoir[1].precision = tour[i+1].pouvoir[1].precision;
                                tour[i].pouvoir[1].porte[0] = tour[i+1].pouvoir[1].porte[0];
                                tour[i].pouvoir[1].porte[1] = tour[i+1].pouvoir[1].porte[1];
                                tour[i].pouvoir[1].effet = tour[i+1].pouvoir[1].effet;

                                strcpy(tour[i].pouvoir[2].nom , tour[i+1].pouvoir[2].nom);
                                strcpy(tour[i].pouvoir[2].explication , tour[i+1].pouvoir[2].explication);
                                tour[i].pouvoir[2].coutPa =  tour[i+1].pouvoir[2].coutPa;
                                tour[i].pouvoir[2].degats =tour[i+1].pouvoir[2].degats;
                                tour[i].pouvoir[2].precision = tour[i+1].pouvoir[2].precision;
                                tour[i].pouvoir[2].porte[0] = tour[i+1].pouvoir[2].porte[0];
                                tour[i].pouvoir[2].porte[1] = tour[i+1].pouvoir[2].porte[1];
                                tour[i].pouvoir[2].effet = tour[i+1].pouvoir[2].effet ; //cout en pv (50)

                                strcpy(tour[i].pouvoir[3].nom , tour[i+1].pouvoir[3].nom);
                                strcpy(tour[i].pouvoir[3].explication , tour[i+1].pouvoir[3].explication);
                                tour[i].pouvoir[3].coutPa = tour[i+1].pouvoir[3].coutPa;
                                tour[i].pouvoir[3].degats = tour[i+1].pouvoir[3].degats;
                                tour[i].pouvoir[3].precision = tour[i+1].pouvoir[3].precision;
                                tour[i].pouvoir[3].porte[0] = tour[i+1].pouvoir[3].porte[0];
                                tour[i].pouvoir[3].porte[1] = tour[i+1].pouvoir[3].porte[1];
                                tour[i].pouvoir[3].effet = tour[i+1].pouvoir[3].effet;

                            }
                            nb_joueur--;
                        }
                        if (tour[plato[x][y]].pv <=0)
                        {
                            for(int i = plato[x][y]; i < nb_joueur - 1;i++)
                            {
                                tour[i].pv = tour[i+1].pv;
                                tour[i].position[0] = tour[i+1].position[0];
                                tour[i].position[1] = tour[i+1].position[1];
                                strcpy(tour[i].pouvoir[0].nom , tour[i+1].pouvoir[0].nom);
                                strcpy(tour[i].pouvoir[0].explication , tour[i+1].pouvoir[0].explication);
                                tour[i].pouvoir[0].coutPa = tour[i+1].pouvoir[0].coutPa;
                                tour[i].pouvoir[0].degats = tour[i+1].pouvoir[0].degats;
                                tour[i].pouvoir[0].precision = tour[i+1].pouvoir[0].precision;
                                tour[i].pouvoir[0].porte[0] = tour[i+1].pouvoir[0].porte[0];
                                tour[i].pouvoir[0].porte[1] = tour[i+1].pouvoir[0].porte[1];
                                tour[i].pouvoir[0].effet = tour[i+1].pouvoir[0].effet;

                                strcpy(tour[i].pouvoir[1].nom , tour[i+1].pouvoir[1].nom);
                                strcpy(tour[i].pouvoir[1].explication , tour[i+1].pouvoir[1].explication);
                                tour[i].pouvoir[1].coutPa = tour[i+1].pouvoir[1].coutPa;
                                tour[i].pouvoir[1].degats = tour[i+1].pouvoir[1].degats;
                                tour[i].pouvoir[1].precision = tour[i+1].pouvoir[1].precision;
                                tour[i].pouvoir[1].porte[0] = tour[i+1].pouvoir[1].porte[0];
                                tour[i].pouvoir[1].porte[1] = tour[i+1].pouvoir[1].porte[1];
                                tour[i].pouvoir[1].effet = tour[i+1].pouvoir[1].effet;

                                strcpy(tour[i].pouvoir[2].nom , tour[i+1].pouvoir[2].nom);
                                strcpy(tour[i].pouvoir[2].explication , tour[i+1].pouvoir[2].explication);
                                tour[i].pouvoir[2].coutPa =  tour[i+1].pouvoir[2].coutPa;
                                tour[i].pouvoir[2].degats =tour[i+1].pouvoir[2].degats;
                                tour[i].pouvoir[2].precision = tour[i+1].pouvoir[2].precision;
                                tour[i].pouvoir[2].porte[0] = tour[i+1].pouvoir[2].porte[0];
                                tour[i].pouvoir[2].porte[1] = tour[i+1].pouvoir[2].porte[1];
                                tour[i].pouvoir[2].effet = tour[i+1].pouvoir[2].effet ; //cout en pv (50)

                                strcpy(tour[i].pouvoir[3].nom , tour[i+1].pouvoir[3].nom);
                                strcpy(tour[i].pouvoir[3].explication , tour[i+1].pouvoir[3].explication);
                                tour[i].pouvoir[3].coutPa = tour[i+1].pouvoir[3].coutPa;
                                tour[i].pouvoir[3].degats = tour[i+1].pouvoir[3].degats;
                                tour[i].pouvoir[3].precision = tour[i+1].pouvoir[3].precision;
                                tour[i].pouvoir[3].porte[0] = tour[i+1].pouvoir[3].porte[0];
                                tour[i].pouvoir[3].porte[1] = tour[i+1].pouvoir[3].porte[1];
                                tour[i].pouvoir[3].effet = tour[i+1].pouvoir[3].effet;
                            }
                             nb_joueur--;
                        }

                    }
                    //printf("votre attaque n'a pas fait de degat");
                }
            }
        }
        if (mouse_b &2)//si le joueur clique sur le bouton droit de la souris
        {
            choix = 1;
            printf("l'attaque est annulé");
        }
        affichage_jeu(nb_joueur,tour,a_qui,decor,buffer,2);
    }
}
int test_porte(t_joueur attaquant, t_joueur victime, int lequel)
{
    int distance_x = attaquant.position[0] - victime.position[0];
    if (distance_x < 0)
    {
        distance_x = distance_x * (-1);
    }
    int distance_y = attaquant.position[1] - victime.position[1];
    if (distance_y < 0)
    {
        distance_y = distance_y * (-1);
    }
    int distance = distance_x + distance_y;
    //printf("%s ",attaquant.nom[0]);
    printf("%d ",distance_y);
    printf("%d\n",distance);
    if (distance <= attaquant.pouvoir[lequel].porte[1] && distance >= attaquant.pouvoir[lequel].porte[0])
    {
        return 0;
    }
    return 1;
}
