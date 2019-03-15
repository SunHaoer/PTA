#include<cstdio>
#include<cmath>
using namespace std;
long long a = 0, b = 0, c = 1;

void reduce() {
    for(int i = 1; i <= abs(c) && i <= abs(b); ) {
        if((b % i == 0) && (c % i == 0)) {
            b /= i;
            c /= i;
            if(i == 1) i++;
        } else {
            i++;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    long long z, m;
    for(int i = 0; i < n; i++) {
        scanf("%lld%*c%lld", &z, &m);
        b = b * m + z * c;
        c = c * m;
        reduce();
    }
    a = b / c;
    b = b % c;
    if(a != 0) printf("%lld", a);
    if(a != 0 && b != 0) printf(" ");
    if(b != 0) printf("%lld/%lld", b, c);
    if(a == 0 && b == 0) printf("0");
    return 0;
}
