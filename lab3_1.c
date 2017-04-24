/* operacje na tablicach dwuwymiarowych */
/* Ludwik Ciechanski */
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N = 10;

void init(int tab[N][N]) {
        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        tab[i][j] = drand48() * 32 + 12;
                        //tab[i][j] = drand48() * 3 + 1;
                        //tab[i][j] = 1;
                }
        }
}
void wypisz(int tab[N][N]) {
        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        printf("%d\t", tab[i][j]);
                }
                printf("\n");
        }
}
int suma_przekatnej(int tab[N][N]) {
        int suma = 0;
        for(int i = 0; i < N; i++) {
                suma += tab[i][i];
        }
        return suma;
}
int suma_pod_przekatna(int tab[N][N]) {
        int suma = 0;
        for(int i = 1; i < N; i++) {
                for(int j = 0; j < N - i; j++) {
                        suma += tab[j][j+1];
                }
        }
        return suma;
}
int suma_wszystko(int tab[N][N]) {
        int suma = 0;
        for(int i = 1; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        suma += tab[i][j];
                }
        }
        return suma;
}
void iloczyn(int tab1[N][N], int tab2[N][N], int tab3[N][N]) {

        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {

                        for(int k = 0; k < N; k++) {
                                tab3[i][j] += tab1[i][k] * tab2[k][j];
                        }
                }
        }
}

int main()
{
        srand48(time(NULL));
        int tab1[N][N];
        int tab2[N][N];
        int tab3[N][N];
        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        tab1[i][j] = 0;
                        tab2[i][j] = 0;
                        tab3[i][j] = 0;
                }
        }

        init(tab1);
        init(tab2);
        wypisz(tab1);
        printf("\n\n");
        wypisz(tab2);
        printf("\n\n");
        //printf("%d\n", suma_przekatnej(tab1) );
        //printf("%d\n", suma_pod_przekatna(tab1) );
        //printf("%d\n", suma_wszystko(tab1) );

        iloczyn(tab1, tab2, tab3);
        wypisz(tab3);
        printf("\n\n");

        return 0;
}
