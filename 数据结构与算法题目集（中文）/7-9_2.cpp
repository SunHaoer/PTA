#include<cstdio>
using namespace std;
const int INF = 510;
const int MAX = 510;
int dist[MAX][MAX], cost[MAX][MAX];           // 距离dist, 费用cost
int nowDist[MAX], nowCost[MAX];     // 当前到起点距离nowDist, 当前花费nowCost
int v, e, s, d;         // 节点个数v, 边数e, 起点s, 终点d
bool visited[MAX] = { false };

void Init() {                   // 初始化
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
            cost[i][j] = 0;
        }
    }
}

void Floyd() {                 // Floyed算法计算各节点间的最小距离
    for(int k = 0; k < v; k++) {
        for(int j = 0; j < v; j++) {
            if(dist[s][j] > dist[s][k] + dist[k][j]) {
                dist[s][j] = dist[s][k] + dist[k][j];
                cost[s][j] = cost[s][k] + cost[k][j];
            } else if(dist[s][j] == dist[s][k] + dist[k][j] && cost[s][j] > cost[s][k] + cost[k][j]) {
                cost[s][j] = cost[s][k] + cost[k][j];
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &v, &e, &s, &d);
    Init();
    for(int i = 0; i < e; i++) {        // 输入
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        dist[a][b] = dist[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    Floyd();
    printf("%d %d\n", dist[s][d], cost[s][d]);
    return 0;
}


/*
 * 修改Floyd算法, 不计算具体路线, 时间性能更高
 */
