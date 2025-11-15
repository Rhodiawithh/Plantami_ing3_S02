#ifndef COMMANDES_JEU_H
#define COMMANDES_JEU_H

#include "Plantamiz.h"
#include "sauvegarde.h"

//Mettre le jeu en pause
void pause_jeu();


//Afficher où se trouve le joueur PAS FINI


//Sélection d'un item
void selection_item(int* select_item, int* select_item_x, int* select_item_y, int* x_joueur, int* y_joueur, char grille[HAUTEUR][LARGEUR]);

//Permutation items
int permutation_item(int select_item_x, int select_item_y, int x_joueur, int y_joueur, char grille[HAUTEUR][LARGEUR]);

//Jouer une partie PAS FINI
void jouer_partie();

#endif