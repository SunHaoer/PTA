#include<iostream>
using namespace std;
const int INF = 1010;
const int MAX = 1010;
int table[MAX][MAX];        // 图table
int d[MAX];              // 到集合的花费d
bool visited[MAX];
int n, m;       // 顶点数n, 边数m

void init() {
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(d, d + MAX, INF);
    fill(visited, visited + MAX, false);
    d[1] = 0;
}

int prim() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int u = -1, minn = INF;
        for(int j = 1; j <= n; j++) {           // 寻找到集合的最短距离
            if(visited[j] == false && d[j] < minn) {
                minn = d[j];
                u = j;
            }
        }
        if(u == -1) return -1;                  // 剩下节点不连通
        visited[u] = true;
        ans += d[u];                            // 加入最小生成树的权值
        for(int v = 1; v <= n; v++) {           // 更新各节点最小距离
            if(visited[v] == false && table[u][v] < d[v]) {
                d[v] = table[u][v];
            }
        }
    }
    return ans;
}

int main()
{
    cin>>n>>m;
    init();
    for(int i = 0; i < m; i++) {        // 输入 图
        int a, b, c;
        cin>>a>>b>>c;
        table[a][b] = table[b][a] = c;
    }
    int ans = prim();
    cout<<ans<<endl;
    return 0;
}
