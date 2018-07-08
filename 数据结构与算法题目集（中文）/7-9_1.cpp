#include<iostream>
using namespace std;
const int INF = 510;
const int MAX = 510;
int dist[MAX][MAX], cost[MAX][MAX];      // 距离dist, 费用cost
int nowDist[MAX], nowCost[MAX];          // 当前距离nowDist, 当前费用nowCost
int v, e, s, d;         // 节点个数v, 边个数e, 起始节点s, 终点节点d
bool visited[MAX] = { false };

void Init() {           // 初始化
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            dist[i][j] = dist[j][j] = INF;
            cost[i][j] = cost[j][i] = 0;
        }
    }
}

void Dijkstra() {       // 搜索最短路径算法
    nowDist[s] = 0;
    visited[0] = true;
    int minn = INF;
    for(int i = 1; i < v; i++) {        // 循环执行v次
        minn = INF;
        for(int w = 0; w < v; w++) {            // 当前节点到其他节点的距离
            if(visited[w] == false && nowDist[w] < minn) {          // 找到最短路径节点
                minn = nowDist[w];
                s = w;
            }
        }
        visited[s] = true;
        for(int w = 0; w < v; w++) {            // 更新最短路径
            if(visited[w] == false && minn + dist[s][w] < nowDist[w]) {
                nowDist[w] = minn + dist[s][w];
                nowCost[w] = nowCost[s] + cost[s][w];
            } else if(visited[w] == false && minn + dist[s][w] == nowDist[w] && nowCost[w] > nowCost[s] + cost[s][w]) {
                nowCost[w] = nowCost[s] + cost[s][w];
            }
        }
    }
}

int main()
{
    cin>>v>>e>>s>>d;
    Init();
    for(int i = 0; i < e; i++) {            // 输入边
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        dist[a][b] = dist[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    for(int i = 0; i < v; i++) {            // 记录当前节点到出发点的距离和费用
        nowDist[i] = dist[s][i];
        nowCost[i] = cost[s][i];
    }
    Dijkstra();
    cout<<nowDist[d]<<" "<<nowCost[d]<<endl;
    return 0;
}
