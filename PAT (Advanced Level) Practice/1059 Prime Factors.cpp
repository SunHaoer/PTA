#include<cstdio>
#include<cmath>
using namespace std;
const int MAX = 100001;
int table[MAX], ans = 0;

void fun1(int n) {
    table[ans++] = 2;
    for(int i = 3; i <= MAX ; i++) {
        bool flag = true;
        for(int j = 2; j <= sqrt(i); j++) {
            if(i % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) table[ans++] = i;
    }
}

int main()
{
    long long n;
    scanf("%lld", &n);
    fun1(n);
    ans = 0;
    printf("%d=", n);
    if(n == 1) printf("1\n");
    else {
        bool flag1 = false;     // 控制第一个符号
        while(true) {
            int flag2 = 0;      // 相同数的个数
            while(n % table[ans] == 0) {
                flag2++;
                n /= table[ans];
            }
            if(flag1 == true && flag2 != 0) {
                printf("*");
            }
            if(flag2 == 1) {
                printf("%d", table[ans]);
                flag1 = true;
            } else if(flag2 > 1) {
                printf("%d^%d", table[ans], flag2);
                flag1 = true;
            }
            ans++;
            if(table[ans] > n) break;
            if(n == 1) break;
        }
        printf("\n");
    }
    return 0;
}


