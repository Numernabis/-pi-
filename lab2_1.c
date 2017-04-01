//Product of two big numbers
//Ludwik Ciechanski
#include <stdio.h>
#include <math.h>

int main()
{
	const int N = 100;
    unsigned long long a, b;
    printf("First number: ");
    scanf("%llu", &a);
    printf("Second number: ");
    scanf("%llu", &b);
    int i, j = 0;

	int t1[N], t2[N], res[2*N];

	for(i = 0; i < N; i++) {
		t1[i] = a % 10;
		a /= 10;
		t2[i] = b % 10;
		b /= 10;
	}
	for(i = 0; i < 2*N; i++)
		res[i] = 0;

	while(j < 100) {
		for(i = 0; i < N; i++) {
			res[i + j] += t1[i] * t2[j];
		}
		j++;
	}
	for(i = 0; i < 2*N - 1; i++) {
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}

	printf("Product: ");
	for(i = 2*N - 1; i >= 0 && res[i] == 0; i--);
	for(; i >= 0; i--)
	printf("%d", res[i]);

    printf("\n");
    return 0;
}