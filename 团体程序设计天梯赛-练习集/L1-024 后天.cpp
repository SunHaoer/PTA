#include<cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if(n + 2 <= 7) printf("%d\n", n + 2);
    else printf("%d\n", n + 2 - 7);
    return 0;
}
