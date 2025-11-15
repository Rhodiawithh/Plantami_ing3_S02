#include <stdio.h>
#include <stdlib.h>
#include "sauvegarde.h"
#include "Plantamiz.h"

//Création fichier de sauvegarde
int sauvergarde_progression(t_joueur j, char grille[HAUTEUR][LARGEUR]){
    FILE* f_sauv = fopen("sauvegarde.dat","w");

    if (f_sauv== NULL) {
        perror("Erreur d'ouverture");
    return 1;
    }

    //Ecriture dans le fichier des informations du joueur
    fwrite(&j, sizeof(t_joueur), 1, f_sauv);

    //Ecriture dans le fichier des informations de la grille
    fwrite(grille, sizeof(char), HAUTEUR*LARGEUR, f_sauv);

    //Fermeture du fichier
    fclose(f_sauv);

    printf("Votre partie est bien sauvergardée");
}

//Reprise fichier de sauvegarde si existant
int reprendre_sauv(t_joueur* j, char grille[HAUTEUR][LARGEUR]){
    FILE* f_sauv = fopen("sauvegarde.dat","r");

    if (f_sauv == NULL){
        perror("Le fichier n'existe pas");
    return 0;
    }

    //On lit les informations du joueur qui sont dans le fichier
    fread(&j, sizeof(t_joueur), 1, f_sauv);

    //On lit les informations de la grille qui sont dans le fichier
    fread(grille, sizeof(char), HAUTEUR*LARGEUR, f_sauv);

    //Fermeture du fichier
    fclose(f_sauv);

    return 1;
}