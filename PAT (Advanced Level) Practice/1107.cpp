#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 10010;
int table[MAX], cnt[MAX], ans;         // table[hobby] = id
bool visited[MAX];
int father[MAX];

void init() {           // 初始化
    fill(table, table + MAX, -1);
    fill(cnt, cnt + MAX, 0);
    for(int i = 0; i < MAX; i++) {
        father[i] = i;
    }
}

int findFather(int x) {          // 寻找父亲节点
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[a] = x;
    }
    return x;
}

void Union(int a, int b) {        // 合并集合
    int faA = findFather(a);
    int faB = findFather(b);
    father[faB] = faA;
}

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    init();
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {    // 输入
        scanf("%d: ", &k);
        for(int j = 0; j < k; j++) {
            int hobby;
            scanf("%d", &hobby);
            if(table[hobby] == -1) table[hobby] = i;
            Union(i, table[hobby]);
        }
    }
    for(int i = 0; i < n; i++) {    // 统计
        if(!visited[findFather(i)]) {
            ans++;                  // 团体数
            visited[findFather(i)] = true;
        }
        cnt[findFather(i)]++;       // 每个团体人数
    }
    sort(cnt, cnt + n, cmp);
    printf("%d\n", ans);            // 输出
    for(int i = 0; i < ans; i++) {
        if(i != 0) printf(" ");
        printf("%d", cnt[i]);
    }
    return 0;
}

