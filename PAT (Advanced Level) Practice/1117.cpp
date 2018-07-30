#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100000;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int n, day[MAX], E = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {    // ÊäÈë
        scanf("%d", &day[i]);
    }
    sort(day, day + n, cmp);
    for(int i = 0; i < n; i++) {    // ¼ÆËã
        if(i + 1 < day[i]) {
            E = i + 1;
        }
    }
    printf("%d\n", E);
    return 0;
}
