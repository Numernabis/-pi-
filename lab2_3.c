#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N1 10
#define N2 10

void zamiana(int t[], int i, int j) {
        int tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
}
void odwroc(int t[], int n) {
        for (int i = 0; i < n / 2; i++) {
                zamiana(t, i, n - 1 - i);
        }
}
void wymien_tablice(int t1[], int t2[], int n) {
        for (int i = 0; i < n; i++) {
                int tmp = t1[i];
                t1[i] = t2[i];
                t2[i] = tmp;  
        }
}
void sort(int t1[]) {

}
int one_two(int t1[], int N1, int t2[], int N2, int w[]) {

}

int main(void) {
        int t1[N1];
        int t2[N2];
        srand48(time(NULL));

        int i = 0;
        for (i = 0; i < N1; i++) {
                t1[i] = drand48() * 10 + 1;
                t2[i] = drand48() * 10 + 1;
        }

        printf("t1 = ");
        for (i = 0; i < N1; i++)
                printf("%d\t", t1[i]);
        printf("\n");
        printf("t2 = ");
        for (i = 0; i < N2; i++)
                printf("%d\t", t2[i]);
        printf("\n");

        odwroc(t1, N1);

        printf("t1 = ");
        for (i = 0; i < N1; i++)
                printf("%d\t", t1[i]);
        printf("\n");

        printf("\n");
        return 0;
}