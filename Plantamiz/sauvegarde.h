#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include "Plantamiz.h"

//Structure pour donner les caractéristiques du joueur
typedef struct joueur{
    char pseudo_joueur[25];
    int nb_vies;
    int niveau_jeu;
 } t_joueur;

 //Fonction de création du fichier de sauvergarde puis sauvegarde des données du joueur et de la grille
int sauvergarde_progression(t_joueur j, char grille[HAUTEUR][LARGEUR]);

//Reprise d'un fichier de sauvegarde si déjà existant
int reprendre_sauv(t_joueur* j, char grille[HAUTEUR][LARGEUR]);

#endif