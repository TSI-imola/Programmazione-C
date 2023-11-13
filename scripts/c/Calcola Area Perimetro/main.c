#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include "esercizi/calc_perim_area.c"
#include "esercizi/esercizi.c"


int main() {
    int esercizi;
    printf("Quale dei due esercizi vuoi fare?\n");
    printf("INDICE:\n"
           "1. Calcola Area e Perimetro\n");

    scanf("%d", &esercizi);

    switch (esercizi) {
        case 1:
            Esercizio1();
            break;
        case 2:
            Esercizio2();
            break;
        case 3:
            Esercizio3();
            break;
        case 4:
            Esercizio4();
            break;
        case 5:
            Esercizio5();
            break;
    }
    return 0;

}

