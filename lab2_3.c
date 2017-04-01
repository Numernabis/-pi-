//Operations on two arrays, sorting
//Ludwik Ciechanski
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N1 10

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
void sort(int t1[], int n) {
        for(int i = 0; i < n; i++) {
                int pos = i;
                for(int j = i + 1; j < n; j++) {
                        if(t1[pos] > t1[j])
                                pos = j;
                }
                if(pos != i) {
                        int tmp = t1[i];
                        t1[i] = t1[pos];
                        t1[pos] = tmp;
                }
        }
}

int one_two(int t1[], int n1, int t2[], int n2, int w[]) {
        int i = 0, j = 0, k = 0;
        while(i < n1 && j < n2) {
                if(t1[i] == t2[j]) {
                        w[k] = t1[i];
                        i++; j++;
                        while(i < n1 && t1[i] == t1[i - 1]) i++;
                        while(j < n2 && t2[j] == t2[j - 1]) j++;
                }
                else if(t1[i] > t2[j]) {
                        w[k] = t2[j];
                        j++;
                        while(j < n2 && t2[j] == t2[j - 1]) j++;
                }
                else {
                        w[k] = t1[i];
                        i++;
                        while(i < n1 && t1[i] == t1[i - 1]) i++;
                }
                k++;
        }
        while(j < n2)
        {
                w[k] = t2[j];
                j++; k++;
                while(j < n2 && t2[j] == t2[j - 1]) j++;
        }
        while(i < n1)
        {
                w[k] = t1[i];
                i++; k++;
                while(i < n1 && t1[i] == t1[i - 1]) i++;
        }
        return k;
}

int main(void) {
        int t1[N1];
        int t2[N1];
        srand48(time(NULL));

        int i = 0;
        for (i = 0; i < N1; i++) {
                t1[i] = drand48() * 10 + 1;
                t2[i] = drand48() * 10 + 1;
        }

        printf("t1 = ");
        for (i = 0; i < N1; i++)
                printf("%4d", t1[i]);
        printf("\n");
        printf("t2 = ");
        for (i = 0; i < N1; i++)
                printf("%4d", t2[i]);
        printf("\n");

        odwroc(t1, N1);
        printf("odwroc t1\n");
        printf("t1 = ");
        for (i = 0; i < N1; i++)
                printf("%4d", t1[i]);
        printf("\n");

        sort(t2, N1);
        printf("sort t2\n");
        printf("t2 = ");
        for (i = 0; i < N1; i++)
                printf("%4d", t2[i]);
        printf("\n");

        int w[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int t3[10] = {1, 2, 2, 5, 5, 5, 6, 6, 8, 9};
        int t4[15] = {1, 1, 1, 2, 4, 5, 6, 6, 8, 8, 8, 9, 9, 10, 10};
        int k = one_two(t3, 10, t4, 15, w);
        printf("one_two\n");
        printf("w = ");
        for (i = 0; i < k; i++)
                printf("%4d", w[i]);

        printf("\n");
        return 0;
}