#include<cstdio>
using namespace std;
const int INF = 510;
const int MAX = 510;
int dist[MAX][MAX], cost[MAX][MAX];           // ����dist, ����cost
int nowDist[MAX], nowCost[MAX];     // ��ǰ��������nowDist, ��ǰ����nowCost
int v, e, s, d;         // �ڵ����v, ����e, ���s, �յ�d
bool visited[MAX] = { false };

void Init() {                   // ��ʼ��
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
            cost[i][j] = 0;
        }
    }
}

void Floyd() {                 // Floyed�㷨������ڵ�����С����
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
    for(int i = 0; i < e; i++) {        // ����
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
 * �޸�Floyd�㷨, ���������·��, ʱ�����ܸ���
 */
