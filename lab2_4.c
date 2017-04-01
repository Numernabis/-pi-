//Armstrong numbers in base b in given compartment
//Ludwik Ciechanski
#include <stdio.h>
#include <math.h>

int change_base(int num, int base) {
    int b = 1, res = 0, digit = 0;
    while(num / b >= base) b *= base;

    while(b > 0) {
        digit = num / b;
        num = num % b;
        res = res*10 + digit;
        b /= base;
    }
    return res;
}

int is_Armstrong(int num, int base) {
    
    int tmp;        //just to count length of number
    int r;          //remainder
    int res = 0;    //result
    int digits = 0; //number of digits

    int copy = change_base(num, base);
    tmp = copy;
    while (tmp != 0)
    {
        tmp /= 10;
        ++digits;
    }

    while (copy != 0)
    {
        r = copy % 10;
        res += pow(r, digits);
        copy /= 10;
    }

    if(res == num)
        return 1;
    else
        return 0;
}

int main()
{
    int from, to, base;
    printf("Armstrong numbers in base b in given compartment\n");
    printf("b = ");
    scanf("%d", &base);
    printf("Enter lower limit: ");
    scanf("%d", &from);
    printf("Enter upper limit: ");
    scanf("%d", &to);

    for(int i = from; i <= to ; i++){
        if(is_Armstrong(i, base) == 1)
            printf("%d\n", i);
    }

    printf("(written in base 10)\n");
    return 0;
}