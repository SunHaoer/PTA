#include<cstdio>
using namespace std;
const int MAX = 10;
int a[MAX], b[MAX], cnt[MAX];

int main()
{
    for(int i = 0; i < 2; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < 3; i++) {
        scanf("%d", &b[i]);
        cnt[b[i]]++;
    }
    if(cnt[0] == 3) printf("The winner is a: %d + 3\n", a[0]);
    else if(cnt[1] == 3) printf("The winner is b: %d + 3\n", a[1]);
    else if(a[0] > a[1]) printf("The winner is a: %d + %d\n", a[0], cnt[0]);
    else printf("The winner is b: %d + %d\n", b[0], cnt[1]);
    return 0;
}
