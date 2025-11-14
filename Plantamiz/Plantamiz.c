#include "Plantamiz.h"



int evite_repetition_element(char plat[HAUTEUR][LARGEUR], int i, int j, char c)
{
    // Vérification horizontale à gauche et à droite de l'élément
    if (j >= 2)
    {
        if (plat[i][j-1] == c && plat[i][j-2] == c) // si on crée un groupe de 3
            return 1;
    }

    // Vérification verticale  en haut et en bas de l'élément
    if (i >= 2)
    {
        if (plat[i-1][j] == c && plat[i-2][j] == c)
            return 1;
    }

    // Vérification d'apparition des groupes de 5  horizontale à gauche et à droite  de l'élément
    if (j >= 4)
    {
        if (plat[i][j-1] == c && plat[i][j-2] == c && plat[i][j-3] == c && plat[i][j-4] == c) // si on crée un groupe de 5
            return 1;
    }

    //Vérification d'apparition des groupes de 5 verticale  en haut et en bas de l'élément
    if (i >= 4)
    {
        if (plat[i-1][j] == c && plat[i-2][j] == c && plat[i-3][j] == c && plat[i-4][j] == c)
            return 1;
    }

    return 0; // OK, pas de suite
}
char generer_element ()
{
    int val = rand() % 5;
    switch(val)
    {
        case 0:
           return 'S';
        case 1:
            return 'F';
        case 2:
            return 'P';
        case 3:
            return 'O';
        case 4:
            return 'M';
    }
}
void initialisation_plateau(char plat[HAUTEUR][LARGEUR])
{
    for (int i = 0; i < HAUTEUR; i++)
    {
        for (int j = 0; j < LARGEUR; j++)
        {
           char c;
            do
            {
                c = generer_element();
            }while (evite_repetition_element(plat, i, j, c));

            plat[i][j] = c;
        }
    }
}

void affichage_plateau(char plat[HAUTEUR][LARGEUR])
{
    for (int i = 0; i < HAUTEUR; i++)
    {
        for (int j = 0; j < LARGEUR; j++)
        {
            char element = plat[i][j];

            switch(element)
            {
                case 'S':
                    text_color(YELLOW);
                break;
                case 'F':
                    text_color(MAGENTA);
                break;
                case 'P':
                    text_color(GREEN);
                break;
                case 'O':
                    text_color(WHITE);
                break;
                case 'M':
                    text_color(RED);
                break;
            }

            printf("%c", element);

            text_color(WHITE); // Remet la couleur normale
        }
        printf("\n");
    }
}




