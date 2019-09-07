#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF = 510;
const int MAX = 510;
int table[MAX][MAX];    // 图
int weight[MAX];        // 节点权重
int d[MAX], c[MAX];     // 当前节点到起点的距离d, 费用c
bool visited[MAX];
int cmax, n, s, m;      // 最大容量cmax, 节点数量n, 终点s, 边数m
vector<int> pre[MAX];        // 前驱节点
vector<int> tempPath, path;  // 临时路径tempPath, 最优路径path
int minNeed = INF, minRemain = INF;      // 最少携带数目minNeed, 最少带回数目minRemain

void init() {           // 初始化
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(d, d + MAX, INF);
    fill(c, c + MAX, INF);
    fill(visited, visited + MAX, false);
    d[0] = 0;
    c[0] = 0;
}

void Dijkstra() {       // 只求最短路径
    for(int i = 0; i <= n; i++) {
        int u = -1, minn = INF;
        for(int j = 0; j <= n; j++) {
            if(visited[j] == false && d[j] < minn) {
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int v = 0; v <= n; v++) {
            if(visited[v] == false && d[u] + table[u][v] < d[v]) {
                d[v] = d[u] + table[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            } else if(visited[v] == false && d[u] + table[u][v] == d[v]) {
                pre[v].push_back(u);
            }
        }
    }
}

void DFS(int v) {           // 在最短路径中寻找最优路径
    if(v == 0) {
        tempPath.push_back(v);
        int need = 0, remain = 0;       // tempPath上需要携带的数目need, 带回数目remain
        for(int i = tempPath.size() - 1; i >= 0; i--) {
            int id = tempPath[i];
            if(weight[id] > 0) {        // 带走
                remain += weight[id];
            } else {                    // 带来
                if(remain > abs(weight[id])) {      // 当前持有足够补给
                    remain -= abs(weight[id]);
                } else {
                    need += (abs(weight[id]) - remain);
                    remain = 0;
                }
            }
        }
        if(need < minNeed) {            // 需要带的数目更少(路径更优)
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        } else if(need == minNeed && remain < minRemain) {      // 带回的数目更少
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    scanf("%d%d%d%d", &cmax, &n, &s, &m);
    for(int i = 1; i <= n; i++) {        // 输入各节点权重
        scanf("%d", &weight[i]);
        weight[i] -= (cmax / 2);         // 完美状态为0
    }
    init();

    for(int i = 0; i < m; i++) {         // 建图
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        table[a][b] = table[b][a] = c;
    }
    Dijkstra();
    DFS(s);
    printf("%d ", minNeed);
    for(int i = path.size() - 1; i >= 0; i--) {     // 输出路径
        printf("%d", path[i]);
        if(i > 0) printf("->");
    }
    printf(" %d", minRemain);
    return 0;
}
