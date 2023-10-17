#include <stdio.h>
#include <math.h>
#include <float.h>

int Esercizio1(), Esercizio2();


int main() {
    int esercizi;
    printf("Quale dei due esercizi vuoi fare?\n");
    scanf("%d", &esercizi);

    if (esercizi == 1) {
        Esercizio1();
    } else {
        Esercizio2();
    }
    return 0;
}


int Esercizio1() {
    int a;
    scanf("%5d", &a);
    printf("%d", a);
    return 0;
}

int Esercizio2() {
    int x1 = 4;
    int x2 = 3;
    int x3 = 4;
    int y1 = 5;
    int y2 = 6;
    int y3 = 7;
    double A = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    double B = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
    double C = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));

    float P = A + B + C;

    double Area = sqrt((P / 2) * ((P / 2) - A) * ((P / 2) - B) * ((P / 2) - C));

    printf("A: %.1f, B: %.1f, C: %.1f\n", A, B, C);
    printf("Perimetro: %.1f\n", P);
    printf("Area: %.1f", Area);
    return 0;
}
