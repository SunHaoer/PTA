#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 10010;
int n, m;

struct Peo {
    int index, cnt, ans;
} peo[MAX];

bool cmp(Peo a, Peo b) {
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    else return a.ans > b.ans;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        peo[i].index = i;
        peo[i].cnt = 0;
        peo[i].ans = 0;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            peo[i].cnt -= b;
            peo[a].cnt += b;
            peo[a].ans++;
        }
    }
    sort(peo + 1, peo + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        printf("%d %.2f\n", peo[i].index, peo[i].cnt * 1.0 / 100);
    }
    return 0;
}
