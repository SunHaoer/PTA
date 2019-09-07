#include<iostream>
#include<vector>
using namespace std;
const int INF = 510;
const int MAX = 510;
int table[MAX][MAX], cost[MAX][MAX];        // 图table, 费用cost
int d[MAX], c[MAX], minCost = INF;             // 每个节点到起点的距离d, 费用c
bool visited[MAX];
int n, m, st, ed;
vector<int> pre[MAX];
vector<int> tempPath, path;     // 临时路径tempPath, 最优路径path

void init() {
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(cost[0], cost[0] + MAX * MAX, INF);
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
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) return;             // 没有连通的节点
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(visited[v] == false && d[u] + table[u][v] < d[v]) {
                d[v] = d[u] + table[u][v];
                pre[v].clear();         // 清空pre[v]节点
                pre[v].push_back(u);    // 把u放入v的前驱节点
            } else if(visited[v] == false && d[u] + table[u][v] == d[v]) {
                pre[v].push_back(u);    // 把u放入v的前驱节点
            }
        }
    }
}

void DFS(int now) {
    if(now == st) {         // 递归到路径起点
        tempPath.push_back(now);
        int tempCost = 0;
        for(int i = tempPath.size() - 1; i > 0; i--) {      // 倒着访问
            int id = tempPath[i], idNext = tempPath[i - 1];
            tempCost += cost[id][idNext];
        }
        if(tempCost < minCost) {        // 当前路径的边权和更小
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(now);
    for(int i = 0; i < pre[now].size(); i++) {
        DFS(pre[now][i]);
    }
    tempPath.pop_back();
}

int main()
{
    cin>>n>>m>>st>>ed;
    init();
    for(int i = 0; i < m; i++) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        table[a][b] = table[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    Dijkstra();
    DFS(ed);
    for(int i = path.size() - 1; i >= 0; i--) {
        cout<<path[i]<<" ";
    }
    cout<<d[ed]<<" "<<minCost<<endl;
    return 0;
}
