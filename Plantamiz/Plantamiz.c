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



// pour effectuer le déplacement du joueur 
void deplacer_joueur (char grille[HAUTEUR][LARGEUR]){
    int curseur_x = 0; //déclaration de variabless 
    int curseur_y = 0;
    char touche;
    int x_selection, y_selection;
    
    while(1){
        system("cls");

        affichage_plateau(grille);// ici on apelle la fonction qui fait la grille 

        // on va afficher le curseur par dessus 
        gotoligcol(curseur_y,curseur_x);
        printf("[X]"); //surligner l'element 
        
        gotoligcol(26,0);
        printf("position : %d, %d -ZQSD - ECHAP=QUITTER", curseur_x,curseur_y);

        //on passe au déplacement 
        touche = _getch(); //pareil que le getchar mais dans conio.h 
        if(touche == 'z' && curseur_y>0){
            curseur_y--;
        }
        else if(touche == 's'&& curseur_y<24){ // on a mis des conditoins pour  éviter de sortir de la grille 
            curseur_y++;
        }
        else if(touche == 'q'&& curseur_x>0){
            curseur_x--;
        }
        else if(touche == 'd' && curseur_x<44){
            curseur_x++;
        }
        else if(touche == 27){
            break;
        }


    }

    
}
