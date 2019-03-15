#include<cstdio>
using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0, cnt = 0;
    for(int i = a; i <= b; i++) {
        printf("%5d", i);
        cnt += i;
        if(++ans % 5 == 0 && i != b) printf("\n");
    }
    printf("\nSum = %d\n", cnt);
    return 0;
}
