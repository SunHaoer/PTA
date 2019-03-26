#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 1010;

struct Paper {
    int index, cnt;
    Paper() {
        cnt = 0;
    }
} paper[MAX];

bool cmp(Paper a, Paper b) {
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    else return a.index > b.index;
}

int main()
{
    int n, m, index;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &index);
            paper[index].index = index;
            paper[index].cnt++;
        }
    }
    sort(paper, paper + MAX, cmp);
    printf("%d %d\n", paper[0].index, paper[0].cnt);
    return 0;
}
