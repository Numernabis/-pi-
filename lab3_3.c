/* Rozwiazywanie rownan liniowych */
/* Ludwik Ciechanski */
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int n, double **A) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%f\t", A[i][j]);
            if (j == n - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void gauss(int n, double **A, double *X) {

        for (int i = 0; i < n; i++) {
                /* Znajdz maksimum w i-tej kolumnie */
                double max_el = abs(A[i][i]);
                int max_row = i;
                for (int p = i + 1; p < n; p++) {
                        if (abs(A[p][i]) > max_el) {
                                max_el = abs(A[p][i]);
                                max_row = p;
                        }
                }

                /* Zamien znaleziony wiersz maksymalny z biezacym */
                for (int p = i; p < n + 1; p++) {
                        double tmp = A[max_row][p];
                        A[max_row][p] = A[i][p];
                        A[i][p] = tmp;
                }

                /* Wyzeruj (w aktualnej kolumnie wszystkie wiersze ponizej maksymalnego */
                for (int p = i + 1; p < n; p++) {
                        double c = - A[p][i] / A[i][i];
                        for (int j = i; j < n + 1; j++) {
                                if (i == j) {
                                        A[p][j] = 0;
                                } else {
                                        A[p][j] += c * A[i][j];
                                }
                        }
                }
        }

        /* Rozwiaz rownanie Ax=B dla macierzy trojkatnej gornej A */
        for (int i = n - 1; i >= 0; i--) {
                X[i] = A[i][n] / A[i][i];
                for (int p = i - 1 ; p >= 0; p--) {
                        A[p][n] -= X[i] * A[p][i];
                }
        }
}

int main() {
        int n;
        printf("n = ");
        scanf("%d", &n);

        double **A;
        A = (double **)malloc(sizeof(double*) * (n + 1));
        for(int i = 0; i < n; i++) {
                A[i] = (double *)malloc(sizeof(double) * n);
        }
        double *X;
        X = (double *)malloc(sizeof(double) * n);

        /* Wczytaj dane do tablicy A (macierz wspolczynnikow) */
        printf("Podaj macierz wspolczynnikow A (wierszami)\n");
        for(int i = 0; i < n; i++) {
                int j = 0;
                while(j < n) {
                        scanf("%lf", &A[i][j]);
                        j++;
                }
        }
        printf("Podaj kolumne wyrazow wolnych\n");
        for(int i = 0; i < n; i++) {
                scanf("%lf", &A[i][n]);
        }

        /* Wypisz wczytane dane */
        print(n, A);

        /* Obliczenia */
        gauss(n, A, X);

        /* Wypisz wyniki */
        printf("Rozwiazania danego ukladu:\n");
        for (int i = 0; i < n; i++) {
                printf("x_%d = %f\n", i, X[i]);
        }
        printf("\n");
        return 0;
}