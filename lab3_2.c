#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
        int N, R;
        printf("N = ");
        scanf("%d", &N);
        printf("R = ");
        scanf("%d", &R);

        int **F, **W;
        F = (int **)malloc(sizeof(int*) * N);
        W = (int **)malloc(sizeof(int*) * N);
        for(int i = 0; i < N; i++) {
                F[i] = (int *)malloc(sizeof(int) * N);
                W[i] = (int *)malloc(sizeof(int) * N);
        }

        for(int i = 0; i < N; i++) {
                int j = 0;
                while( j < N ) {
                        scanf("%d", &F[i][j]);
                        j++;
                }

        }
        printf("input array:\n");
        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        printf("%2d", F[i][j]);
                }
                printf("\n");
        }

        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        int sum = 0;
                        for(int k = i - R; k < i + R + 1; k++) {
                                if(k >= 0 && k < N) {
                                        for(int m = j - R; m < j + R + 1; m++) {
                                                if(m >= 0 && m < N) {
                                                        sum += F[k][m];
                                                }
                                        }
                                }
                        }
                        W[i][j] = sum;
                }
        }
        printf("output array:\n");
        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        printf("%2d", W[i][j]);
                }
                printf("\n");
        }

        printf("\n");
        free(F);
        free(W);
        return 0;
}