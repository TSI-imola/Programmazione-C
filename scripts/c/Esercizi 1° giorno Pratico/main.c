#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void es1();

void es2();

void es3();

void es4();

void es5();

void es6();

void es7();

void es8();

void es9();

int main() {
    printf("Che esercizio vuoi svolgere?\n");
    int es;
    scanf("%d", &es);
    switch (es) {
        case 1:
            es1();
            break;
        case 2:
            es2();
            break;
        case 3:
            es3();
            break;
        case 4:
            es4();
            break;
        case 5:
            es5();
            break;
        case 6:
            es6();
            break;
        case 7:
            es7();
            break;
        case 8:
            es8();
            break;
        case 9:
            es9();
            break;
    }
}

void es1() {
    int num;
    int calc;
    printf("Inserisci un numero:\n");
    scanf("%d", &num);

    calc = num % 2;

    if (calc == 0) {
        printf("pari");
    } else {
        printf("dispari");
    }
}

void es2() {
    int num1;
    int num2;
    printf("Inserisci due numeri:");
    scanf("%d %d", &num1, &num2);

    if (num1 > num2) {
        printf("%d > %d", num1, num2);
    } else if (num1 == num2) {
        printf("%d = %d", num1, num2);
    } else {
        printf("%d < %d", num1, num2);
    }
}


void es3() {
    float val1 = 6;
    float val2 = 15;
    float val3 = 8;
    float val4 = 2;

    float es1;
    float es2;
    float es3;
    float es4;

    printf("Inserisci i voti dei 4 esercizi da 0.0 a 1.0:\n");
    scanf("%f %f %f %f", &es1, &es2, &es3, &es4);
    if (es1 < 0 || es1 > 1 || es2 < 0 || es2 > 1 || es3 < 0 || es3 > 1 || es4 < 0 || es4 > 1) {
        printf("I voti devono essere compresi tra 0.0 e 1.0");
        return;
    }

    float calc = (val1 * es1) + (val2 * es2) + (val3 * es3) + (val4 * es4);
    printf("Il tuo voto e': %f\n", calc);

    if (calc < 18) {
        printf("Sei: Non Sufficiente");
    } else if (calc >= 18 && calc <= 30) {
        printf("Sei: Promosso");
    } else {
        printf("Sei: Promosso con lode");
    }
}

void es4() {
    char lettera;
    printf("Inserisci una lettera dell'alfabeto:\n");
    scanf(" %c", &lettera);

    switch (lettera) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("'%c': e' una vocale", lettera);
            break;
        default:
            printf("'%c': e' una consonante", lettera);

    }
}

void es5() {
    int num;
    int guess;
    int try = 0;

    printf("Inserisci un numero da indovinare:\n");
    scanf("%d", &num);

    while (try < 5) {
        printf("Inserisci un numero:\n");
        scanf("%d", &guess);
        if (guess == num) {
            printf("Hai indovinato");
            return;
        } else {
            printf("Riprova\n");
            try++;
        }
    }
}

void es6() {
    srand(time(NULL));
    int num = rand() % 100;
    int guess;
    int try = 0;

    while (try < 5) {
        printf("Inserisci un numero (%d/5) [%d]:\n", try, num);
        scanf("%d", &guess);
        if (guess == num) {
            printf("Hai indovinato");
            try = 6;
        } else if (guess > num) {
            printf("Riprova (%d < ?)\n", guess);
            try++;
        } else if (guess < num) {
            printf("Riprova (%d > ?)\n", guess);
            try++;
        }
    }
    printf("Hai finito i tentativi. Il numero era: %d", num);
}

void es7() {
    float num;
    int i = 0;
    float calc;
    while (i < 10) {
        printf("Inserisci un numero: (%d/10)\n", i);
        scanf("%f", &num);
        calc += num;
        i++;
    }
    printf("La somma e': %f\n", calc);
    printf("La media e': %f", calc / 10);
}

void es8() {
    float num;
    int i = 0;
    float calc;
    int val;
    printf("Quanti valori vuoi inserire?:\n");
    scanf("%d", &val);
    while (i < val) {
        printf("Inserisci un numero: (%d/%d)\n", i, val);
        scanf("%f", &num);
        if (num <= 0) {
            printf("Devi inserire un numero Positivo, Riprova.\n");
        } else {
            i++;
            calc += num;
        }
    }
    printf("La somma e': %f\n", calc);
    printf("La media e': %f\n", calc / 10);
}

void es9() {


}
