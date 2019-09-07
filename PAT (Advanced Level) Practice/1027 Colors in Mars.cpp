#include<cstdio>
using namespace std;

int main()
{
    char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("#%c%c%c%c%c%c\n", table[a / 13], table[a % 13], table[b / 13], table[b % 13], table[c / 13], table[c % 13]);
    return 0;
}


/*
 * 此题有点懵逼
 */
