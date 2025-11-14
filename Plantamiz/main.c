#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    char grille[25][45];
    char lettre[5]={'S','F','O','P','M'}; //les lettres du jeu
    int carre;
    
    
    
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 45; j++) {
            carre = rand() % 5; //ds chaque carré on met notre valeur aleatoire
            grille[i][j] = lettre[carre]; //ds chaque case on la valeur aleatoire parmi les 5 lettres
            printf("%c\t",grille[i][j] );
        }
        printf("\n"); //saut de ligne pour faire matrice
    }
    return 0;
}
