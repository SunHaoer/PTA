#include<cstdio>
using namespace std;

int main()
{
    int n, cnt = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cnt *= 2;
    }
    printf("2^%d = %d\n", n, cnt);
    return 0;
}
