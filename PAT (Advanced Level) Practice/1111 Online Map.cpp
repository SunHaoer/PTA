#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 510, INF = 100010;
int table1[MAX][MAX], table2[MAX][MAX];
bool visited[MAX];
int dist[MAX];
int n, m;       // n个节点, m条边
int s, e;       // 起点s, 终点e
int dist1, dist2;   // 最短路径, 最短时间
vector<int> pre[MAX];       // 保存前驱节点

void init() {       // 初始化
    fill(visited, visited + MAX, false);
    fill(dist, dist + MAX, INF);
}

void Dijkstra(int table[MAX][MAX]) {       // 求最短路径
    init();
    dist[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = INF;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < minn) {
                u = j;
                minn = dist[j];
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(!visited[v] && dist[u] + table[u][v] < dist[v]) {
                dist[v] = dist[u] + table[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            } else if(!visited[v] && dist[u] + table[u][v] == dist[v]) {
                pre[v].push_back(u);
            }
        }
    }
}

vector<int> tempDistPath, distPath;
int minTime = INF;
void DFSDist(int v) {           // 最短路径中选出最短时间
    if(v == s) {
        int tempTime = 0;
        tempDistPath.push_back(v);
        for(int i = tempDistPath.size() - 1; i >= 1; i--) {
            int id = tempDistPath[i], idNext = tempDistPath[i - 1];
            tempTime += table2[id][idNext];
        }
        if(tempTime < minTime) {
            minTime = tempTime;
            distPath = tempDistPath;
        }
        tempDistPath.pop_back();
        return;
    }
    tempDistPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFSDist(pre[v][i]);
    }
    tempDistPath.pop_back();
}

vector<int> tempTimePath, timePath;
int minNode = INF;
void DFSTime(int v) {       // 最短时间中选出最短距离
    if(v == s) {
        tempTimePath.push_back(v);
        int tempNode = tempTimePath.size();
        if(tempNode < minNode) {
            minNode = tempNode;
            timePath = tempTimePath;
        }
        tempTimePath.pop_back();
        return;
    }
    tempTimePath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFSTime(pre[v][i]);
    }
    tempTimePath.pop_back();
}

void printPath(vector<int> path) {      // 输出路径
    printf("%d", path[path.size() - 1]);
    for(int i = path.size() - 2; i >= 0; i--) {
        printf(" -> %d", path[i]);
    }
    printf("\n");
}


int main()
{
    scanf("%d %d", &n, &m);
    fill(table1[0], table1[0] + MAX * MAX, INF);
    fill(table2[0], table2[0] + MAX * MAX, INF);
    for(int i = 0; i < m; i++) {        // 建图
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        table1[a][b] = d;
        table2[a][b] = e;
        if(c == 0) {        // 单行线(没有对应测试点)
          table1[b][a] = d;
          table2[b][a] = e;
        }
    }
    scanf("%d %d", &s, &e);
    Dijkstra(table1);                   // 计算
    dist1 = dist[e];
    DFSDist(e);
    Dijkstra(table2);
    dist2 = dist[e];
    DFSTime(e);
    if(distPath == timePath) {          // 最短距离与最短时间相同
        printf("Distance = %d; Time = %d: ", dist1, dist2);
        printPath(distPath);
    } else {                            // 最短距离与最短时间不同
        printf("Distance = %d: ", dist1);
        printPath(distPath);
        printf("Time = %d: ", dist2);
        printPath(timePath);
    }
    return 0;
}
