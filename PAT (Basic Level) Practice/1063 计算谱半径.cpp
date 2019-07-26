#include<cstdio>
#include<cmath>
using namespace std;

struct number {
    double a, b, r;          //Êµ²¿a, Ðé²¿b, °ë¾¶r
}num[10001];

int main()
{
    int n;
    double maxn = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &num[i].a, &num[i].b);
        num[i].r = sqrt( num[i].a * num[i].a + num[i].b * num[i].b );
        if(num[i].r > maxn) {
            maxn = num[i].r;
        }
    }
    printf("%.2f", maxn);
    return 0;
}
