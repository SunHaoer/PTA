#include<cstdio>
using namespace std;

int fun1(int n) {
    int cnt = 1;
    for(int i = 1; i <= n; i++) {
        cnt *= i;
    }
    return cnt;
}

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        cnt += fun1(i);
    }
    printf("%d\n", cnt);
    return 0;
}
