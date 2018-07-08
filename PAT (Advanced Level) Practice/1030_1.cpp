#include<iostream>
using namespace std;
const int INF = 510;
const int MAX = 510;
int table[MAX][MAX], cost[MAX][MAX];        // 图table, 费用cost
int d[MAX], c[MAX];     // 每个节点到起点的距离d, 费用c
bool visited[MAX];
int n, m, st, ed;       // 顶点数n, 边数m, 起点st, 终点ed
int pre[MAX];           // 前驱节点

void init() {
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(d, d + MAX, INF);
    fill(c, c + MAX, INF);
}

void Dijkstra() {
    d[st] = 0;
    c[st] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = INF;
        for(int j = 0; j < n; j++) {        // 寻找距离最近的节点
            if(visited[j] == false && d[j] < minn) {
                minn = d[j];
                u = j;
            }
        }
        if(u == -1) return;                 // 无剩下连通节点
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(visited[v] == false && d[u] + table[u][v] < d[v]) {     // 更新最短路径
                d[v] = d[u] + table[u][v];
                c[v] = c[u] + cost[u][v];
                pre[v] = u;
            } else if(visited[v] == false && d[u] + table[u][v] == d[v]) {
                if(c[u] + cost[u][v] < c[v]) {
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}

void DFS(int now) {        // 输出路径
    if(now == st) {
        cout<<now<<" ";
        return;
    }
    DFS(pre[now]);
    cout<<now<<" ";
}

int main()
{
    cin>>n>>m>>st>>ed;
    init();
    for(int i = 0; i < m; i++) {        // 读入图
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        table[a][b] = table[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    Dijkstra();
    DFS(ed);
    cout<<d[ed]<<" "<<c[ed]<<endl;
    return 0 ;
}
