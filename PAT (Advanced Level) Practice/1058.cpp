#include<cstdio>
using namespace std;

int main()
{
    int a1 = 0, b1 = 0, c1 = 0;
    int a2 = 0, b2 = 0, c2 = 0;
    int a3 = 0, b3 = 0, c3 = 0;
    scanf("%d.%d.%d", &a1, &b1, &c1);
    scanf("%d.%d.%d", &a2, &b2, &c2);
    c3 += c1 + c2;
    while(c3 >= 29) {
        c3 -= 29;
        b3++;
    }
    b3 += (b1 + b2);
    while(b3 >= 17) {
        b3 -= 17;
        a3++;
    }
    a3 += (a1 + a2);
    printf("%d.%d.%d\n", a3, b3, c3);
    return 0;
}
