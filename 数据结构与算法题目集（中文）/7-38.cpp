#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 1000010;
long long num[MAX];

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    sort(num, num + n, cmp);
    printf("%d", num[0]);
    for(int i = 1; i < m && i < n; i++) {       // ²âÊÔµã2: n < m
        printf(" %d", num[i]);
    }
    printf("\n");
    return 0;
}
