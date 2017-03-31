#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {
        //wczytanie rozmiaru tablicy t1
        int N;
        printf("\n");
        printf("N = ");
        scanf("%d", &N);
        printf("\n");
        srand48(time(NULL));

        double *t1;
        double *t2;
        int S = (N+1)/2;
        t1 = (double *)malloc(sizeof(double) * N);      // allocate N doubles
        t2 = (double *)malloc(sizeof(double) * S);      // allocate S doubles

        //wypelnienie tablicy t1 liczbami pseudolosowymi z przedzialu [55,112]
        // + wypisanie tablicy t1
        int i = 0, j = 0;
        printf("t1 = ");
        for(i = 0; i < N; i++){
                int x = drand48() * 57 + 55;
                t1[i] = x;
                printf("%lf\t", t1[i]);
        }
        printf("\n");

        //wypelnienie tablicy t2 i wypisanie jej
        i = 0;
        printf("t2 = ");
        for(j = 0; j < S / 2 * 2; j++){

                t2[j] = (t1[i] + t1[i+1]) / 2;
                i += 2;
                printf("%lf\t\t",t2[j]);
        }
        if(N % 2 != 0) { t2[S - 1] = t1[N - 1]; printf("%lf\t\t",t2[S - 1]); }
        printf("\n");
        return 0;
}