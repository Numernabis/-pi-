//Product of two big numbers
//Ludwik Ciechanski
#include <stdio.h>
#include <math.h>

int main()
{
	const int N = 100;
    unsigned long a, b;
    printf("First number: ");
    scanf("%lu", &a);
    printf("Second number: ");
    scanf("%lu", &b);
    int i, j = 0, s = 1;

   	int t1[N], t2[N], res[2*N];

   	for(i = 0; i < N; i++) {
   		res[i] = 0;
   		t1[i] = a % 10;
   		a /= 10;
   		t2[i] = b % 10 * s;
   		b /= 10;
   		s *= 10;
   	}

   	while(j < 100) {
   		for(i = 0; i < N; i++) {
	   		res[i] += t1[i] * t2[j];
	   	}
	   	for(i = 0; i < N - 1; i++) {
	   		res[i + 1] += res[i] / 10;
	   		res[i] %= 10;
	   	}
	   	j++;
	}

	printf("Product: ");
   	for(i = N - 1; i >= 0 && res[i] == 0; i--);
   	for(; i >= 0; i--)
   		printf("%d", res[i]);

    printf("\n");
    return 0;
}