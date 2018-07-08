#include<iostream>
#include<cmath>
using namespace std;
int sump = 0, suma = 0, sum = 0;

struct money {
    int g,s,k;
} P, A, result;                  // Ó¦¸¶P,Êµ¸¶A       A-P        1.17.29

void check() {
    sump = P.g * 17 * 29 + P.s * 29 + P.k;
    suma = A.g * 17 * 29 + A.s * 29 + A.k;
    sum = (suma - sump);
}

int main()
{
    scanf("%d.%d.%d", &P.g, &P.s, &P.k);
    scanf("%d.%d.%d", &A.g, &A.s, &A.k);
    check();
    result.k = sum % 29;
    sum = sum / 29;
    result.s = sum % 17;
    sum = sum /17;
    result.g = sum;
    printf("%d.%d.%d\n", result.g, abs(result.s), abs(result.k));
    return 0;
}
