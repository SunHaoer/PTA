#include<cstdio>
using namespace std;

int main()
{
    int n;
    long long a1, b1;
    scanf("%d", &n);
    scanf("%lld/%lld", &b1, &a1);
    for(int i = 1; i < n; i++) {        // 输入，累加
        long long a2, b2;
        long long a, b;
        scanf("%lld/%lld", &b2, &a2);
        a = a1 * a2;
        b = b1 * a2 + a1 * b2;
        a1 = a;
        b1 = b;
        for(long long j = 2; j < a1 && j < b1; j++) {   // 约分
            while(a1 % j == 0 && b1 % j == 0) {
                a1 /= j;
                b1 /= j;
            }
        }
    }
    long long n1 = b1 / a1;         // 输出
    long long n2 = b1 % a1;
    if(n1 != 0) printf("%lld", n1);
    if(n1 != 0 && n2 != 0) printf(" ");
    if(n2 != 0 && a1 != 0) printf("%lld/%lld", n2, a1);
    if(n1 == 0 && n2 == 0) printf("0\n");
    return 0;
}
