#include<cstdio>
using namespace std;

int main()
{
    int n;
    long long a, b, c;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a > 0 && b > 0 && a + b < 0) {       // 向上超出long long 范围, 必定大于c
            printf("Case #%d: true\n", i);
        } else if(a < 0 && b < 0 && a + b > 0) {    // 向下超出longlong范围, 必定小于c
            printf("Case #%d: false\n", i);
        } else if(a + b > c) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
    }
    return 0;
}
