#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 1010;
int table[MAX][MAX];        // 图table
bool visited[MAX];
int n, m, k;           // 顶点数n, 边数m, 查询数k

void DFS(int now, int dis) {
    if(now == dis) return;      // 该节点不存在
    visited[now] = true;
    for(int i = 1; i <= n; i++) {
        if(table[now][i] == 1 && visited[i] == false) {
            DFS(i, dis);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {        // 建图
        int a, b;
        scanf("%d%d", &a, &b);
        table[a][b] = table[b][a] = 1;
    }
    for(int i = 0; i < k; i++) {        // 查询
        int dis;            // 消失节点dis
        scanf("%d", &dis);
        memset(visited, false, sizeof(visited));
        int ans = 0;        // 块数
        for(int v = 1; v <= n; v++) {
            if(v != dis && visited[v] == false) {        // 该节点未删除 && 未访问
                DFS(v, dis);
                ans++;
            }
        }
        printf("%d\n", ans - 1);
    }
}
