#include<iostream>
#include<cstring>
using namespace std;
const int INF = 510;
const int MAX = 510;
int table[MAX][MAX];        // 图
int weight[MAX], w[MAX];    // 单个顶点权重weight, 路径权重和w
int d[MAX], num[MAX], pre[MAX];               // 每个顶点到起点的距离d, 最短路径数num, 上一节点pre
bool visited[MAX];
int n, m, st, ed;           // 顶点数n, 边数m, 起点st, 终点ed

void init() {               // 初始化
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(d, d + MAX, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[st] = 0;               // 到起点的距离
    w[st] = weight[st];      // 起点的权重
    num[st] = 1;
}

void Dijkstra() {
    for(int i = 0; i < n; i++) {
        int u = -1, minn = INF;         // 距离最近的节点u, 最短的距离minn
        for(int j = 0; j < n; j++) {
            if(visited[j] == false && d[j] < minn) {
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) return;             // 没有能过连通的顶点
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(visited[v] == false && table[u][v] != INF) {         // v为未访问节点, 且u-v连通
                if(d[u] + table[u][v] < d[v]) {                     // 以u为中介路径更优
                    d[v] = d[u] + table[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pre[v] = u;
                } else if(d[u] + table[u][v] == d[v]) {
                    if(w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                        pre[v] = u;
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

void DFS(int now) {
    if(now == st) {
        cout<<now;
        return;
    }
    DFS(pre[now]);
    cout<<" "<<now;
}

int main()
{
    cin>>n>>m>>st>>ed;
    for(int i = 0; i < n; i++) {
        cin>>weight[i];
    }
    init();
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        table[a][b] = table[b][a] = c;
    }

    Dijkstra();
    cout<<num[ed]<<" "<<w[ed]<<endl;
    DFS(ed);
    cout<<endl;
    return 0;
}
