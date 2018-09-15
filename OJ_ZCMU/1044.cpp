#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n, m, ans = 0;
    while(scanf("%d%d", &n, &m)!=EOF){
        ans = m * n - 1;
        cout<<ans<<endl;
    }
    return 0;
}
