#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "commandes_jeu.h"

//Mettre en pause le jeu
void pause_jeu(){
    char touche;
    printf("Le jeu est en pause. Appuyer sur la touche espace pour reprendre. \n ");
    do {
        touche=getch();
    } while (touche != 'p');

    printf("Reprise du jeu");
}


// Déplacer le joueur selon la touche appuyée
void deplacer_joueur(char touche, int *x, int *y) {
    switch(touche) {
        case 'z': *y=(*y)-1;
        break;
        case 's': *y=(*y)+1;
        break;
        case 'q': *x=(*x)-1;
        break;
        case 'd': *x=(*x)+1;
        break;
        }
}

//Sélection d'un item
void selection_item(int* select_item, int* select_item_x, int* select_item_y, int* x_joueur, int* y_joueur, char grille[HAUTEUR][LARGEUR]){
    
    //Si aucun item n'a été sélectionné
    if (*select_item == 0){

        //On le sélectionne
        *select_item = 1;

        *select_item_x = *x_joueur;
        *select_item_y = *y_joueur;

        //Faire ressortir l'item sélectionné en le faisant passer en minuscule
        grille[*select_item_y][*select_item_x] = (grille[*select_item_y][*select_item_x]) + 32;
    }

    //Un item était sélectionné
    else{
        //On le désélectionne
        *select_item = 0;

        //Ne plus faire ressortir l'item sélectionné en le refaisant passer en majuscule
        grille[*select_item_y][*select_item_x] = (grille[*select_item_y][*select_item_x]) - 32;

        *select_item_x = -1;
        *select_item_y = -1;
    }
}

//Permutation items
int permutation_item(int select_item_x, int select_item_y, int x_joueur, int y_joueur, char grille[HAUTEUR][LARGEUR]){
    char stock_item1; //pour éviter de permuter le mauvais item

    //Les deux items que l'on veut permuter doivent être côte à côte. On calcule la distance entre les deux items, si elle est de 1 alors les items sont côte à côte
    if ((select_item_x == x_joueur && abs(select_item_y - y_joueur) == 1) || (select_item_y == y_joueur && abs(select_item_x - x_joueur) == 1) ){

        //On stocke l'item qui va prendre la place du joueur
        stock_item1 = grille[select_item_y][select_item_x];

        //On remplace l'item sélectionné par l'item situé à la place du joueur
        grille[select_item_y][select_item_x]=grille[y_joueur][x_joueur];

        //On met l'ancien item à la place du joueur
        grille[select_item_y][select_item_x]=stock_item1;

        return 1; //pour permutation réussie
    }

    return 0; //pas de permutation
}


//Jouer une partie
void jouer_partie(){
    int x_joueur = 0;
    int y_joueur = 0;

    char touche =0;

    int select_item = 0;
    int select_item_x = -1;
    int select_item_y = -1;

}

       