    #ifndef MENU_H
    #define MENU_H

    #include <stdlib.h>
    #include <unistd.h>
    #include <graph.h>

    #define LONGUEUR 1200
    #define HAUTEUR 1000

    #define X1_START 264
    #define X2_START 981
    #define Y1_START 882
    #define Y2_START 980

    #define X1_REGLE 1000
    #define X2_REGLE 1200
    #define Y1_REGLE 800
    #define Y2_REGLE 943

    #define X1_EXIT 0
    #define X2_EXIT 101
    #define Y1_EXIT 875
    #define Y2_EXIT 916

    #define X1_BACK 0
    #define X2_BACK 101
    #define Y1_BACK 0
    #define Y2_BACK 45

    #define X1_FACILE 48
    #define X2_FACILE 315
    #define Y1_FACILE 572
    #define Y2_FACILE 677

    #define X1_MOYEN 473
    #define X2_MOYEN 734
    #define Y1_MOYEN 567
    #define Y2_MOYEN 668

    #define X1_DIFFICILE 903
    #define X2_DIFFICILE 1166
    #define Y1_DIFFICILE 563
    #define Y2_DIFFICILE 662

    void menu(void);

    #endif
