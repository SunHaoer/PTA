#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        int num = 1, i = 0, ans = 0;
        while(num<n){
            num = num + pow(2, i++);
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
