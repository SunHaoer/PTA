#include<cstdio>
using namespace std;

int main()
{
    int n, m, cnt1 = 0, cnt2 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        if(m % 2 != 0) cnt1++;
        else cnt2++;
    }
    printf("%d %d\n", cnt1, cnt2);
    return 0;
}
