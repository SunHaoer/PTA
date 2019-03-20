#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 550, INF = 550;
int n, m, st, ed;
int weight[MAX];      // 每个节点权值
int table[MAX][MAX];    // 表示路径的表
int d[MAX], w[MAX];
int num[MAX];   // 最短路径条数
bool visited[MAX];
int pre[MAX];

void init() {
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(d, d + MAX, INF);
    fill(w, w + MAX, 0);
    fill(num, num + MAX, 0);
    fill(visited, visited + MAX, false);
    d[st] = 0;
    num[st] = 1;
    w[st] = weight[st];
}

void dijkstra() {
    for(int i = 0; i < n; i++) {
        int u = -1, minn = INF;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && d[j] < minn) {
                minn = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(!visited[v] && d[u] + table[u][v] < d[v]) {
                d[v] = d[u] + table[u][v];
                w[v] = w[u] + weight[v];
                num[v] = num[u];
                pre[v] = u;
            } else if(!visited[v] && d[u] + table[u][v] == d[v]) {
                if(w[u] + weight[v] > w[v]) {
                    w[v] = w[u] + weight[v];
                    pre[v] = u;
                }
                num[v] += num[u];
            }
        }
    }
}

void getPath(int now) {
    if(now == st) {
        printf("%d", now);
    } else {
        getPath(pre[now]);
        printf(" %d", now);
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    init();
    int a, b, c;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        table[a][b] = table[b][a] = c;
    }
    dijkstra();
    printf("%d %d\n", num[ed], w[ed]);
    getPath(ed);
    return 0;
}
