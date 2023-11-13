#include "stdio.h"
#include "string.h"

void Esercizio3() {
    printf("Inserisci la Grandezza della Matrice (Es. 3x3)\n");
    int row_mat, col_mat;
    scanf("%d %d", &row_mat, &col_mat);
    int mat[row_mat][col_mat];

    for (int r = 0; r < (row_mat * col_mat); r++) {
        printf("Inserisci gli elementi della matrice (%d/ %d)\n", r, (row_mat * col_mat));
        scanf("%d", &mat[row_mat][col_mat]);
    }
    printf("%d\n", mat[row_mat][col_mat]);


    printf("La matrice inserita è:\n");
    // Ruota le Righe
    for (int r = 0; r < row_mat; r++) {
        // Ruota le Colonne
        for (int c = 0; c < col_mat; ++c) {
            printf("%d ", mat[r][c]);
        }
        printf("\n");
    }

}

void Esercizio4() {
    enum mesi {
        GENNAIO = 1,
        FEBBRAIO,
        MARZO,
        APRILE,
        MAGGIO,
        GIUGNO,
        LUGLIO,
        AGOSTO,
        SETTEMBRE,
        OTTOBRE,
        NOVEMBRE,
        DICEMBRE
    };

    enum mesi mesi;


    for (int i = 1; i <= 12; i++) {
        printf("MESE: %d = %d\n", mesi, i);
    }
}

    struct studente {
        char nome[50];
        char cognome[50];
        int matricola;
        int anno_iscrizione;
    };

void Esercizio5() {

    struct studente s = {"Mario", "Rossi", 123456, 2023};
    printf("Nome: %s\n", s.nome);
    printf("Cognome: %s\n", s.cognome);
    printf("Matricola: %d\n", s.matricola);
    printf("Anno Iscrizione: %d\n", s.anno_iscrizione);


};
