#include<cstdio>
using namespace std;

int main()
{
    int n, ans = 0;
    while(scanf("%d", &n) != EOF) {
        ans++;
        if(n == 250) break;
    }
    printf("%d\n", ans);
    return 0;
}
