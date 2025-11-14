#include "Plantamiz.h"

int main()
{
    srand(time(NULL));

    char plateau[HAUTEUR][LARGEUR];

    initialisation_plateau(plateau);
    clrscr();
    affichage_plateau(plateau);

    return 0;
}

