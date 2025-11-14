#ifndef PLANTAMIZ_H
#define PLANTAMIZ_H

//librairies
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <windows.h>
//#include <conio.h> 

//Variables globales

#define HAUTEUR 25
#define LARGEUR 45



//Structure

// 16 couleurs utilisables en mode console de base
typedef enum{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLORS;

typedef struct Contrat
{
   int nombre_soleil;
    int nombre_fraise;
    int nombre_pomme;
    int nombre_oignons;
    int nombre_mandarines;
    int nombre_coups;
}t_contrat;


//Prototypes des sous programmes

//effacer la console
void clrscr ();
//deplacer le curseur a la position horizontale x, verticale y
void gotoxy(int x, int y);
//effacer la suite de la ligne
void delete_line();
//recuperer la position horizontale du curseur
int wherex ();
//recuperer la position verticale du curseur
int wherey ();
//changer la couleur du texte
void text_color(int color);
//changer la couleur de fond
void bg_color(int color);
//changer la couleur du texte et du fond
void set_color(int colorT,int colorBg);
//cacher le curseur
void hide_cursor();
//montrer le curseur
void show_cursor();
/*savoir si une touche a ete pressee
retour : 1 si une touche a ete pressee (caractere disponible en lecture avec getch), 0 sinon*/
int kbhit();
/*Lire un caractere du clavier immediatement, sans avoir besoin d'appuyer sur Entr�e.
s'utilise generalement avec kbhit :
si une touche a ete pressee, on lit le caract�re correspondant
Retour :  entier ayant le meme code binaire que le caract�re lu (code ASCII du caract�re)
*/
int getch();

void initialisation_plateau(char plat[HAUTEUR][LARGEUR]);
void affichage_plateau(char plat[HAUTEUR][LARGEUR]);




#endif //PLANTAMIZ_H
