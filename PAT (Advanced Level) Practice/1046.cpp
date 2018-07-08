#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100010;
int n, arr1[MAX], arr2[MAX];        // 单端路arr1, 到起点距离arr2

int fun1(int a, int b) {
    int ans1 = 0, ans2 = 0;
    ans1 = arr2[b - 1] - arr2[a - 1];
    ans2 = arr2[n] - arr2[b - 1] + arr2[a - 1];
    return min(ans1, ans2);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr1[i]);
        arr2[i] = arr2[i - 1] + arr1[i];
    }
    int m, a, b;
    scanf("%d", &m);
    for(int i = 0; i <m; i++) {
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        int ans = fun1(a, b);
        printf("%d\n", ans);
    }
    return 0;
}
