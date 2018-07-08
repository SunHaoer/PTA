#include<iostream>
using namespace std;
const int INF = 510;
const int MAX = 510;
int dist[MAX][MAX], cost[MAX][MAX];      // ����dist, ����cost
int nowDist[MAX], nowCost[MAX];          // ��ǰ����nowDist, ��ǰ����nowCost
int v, e, s, d;         // �ڵ����v, �߸���e, ��ʼ�ڵ�s, �յ�ڵ�d
bool visited[MAX] = { false };

void Init() {           // ��ʼ��
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            dist[i][j] = dist[j][j] = INF;
            cost[i][j] = cost[j][i] = 0;
        }
    }
}

void Dijkstra() {       // �������·���㷨
    nowDist[s] = 0;
    visited[0] = true;
    int minn = INF;
    for(int i = 1; i < v; i++) {        // ѭ��ִ��v��
        minn = INF;
        for(int w = 0; w < v; w++) {            // ��ǰ�ڵ㵽�����ڵ�ľ���
            if(visited[w] == false && nowDist[w] < minn) {          // �ҵ����·���ڵ�
                minn = nowDist[w];
                s = w;
            }
        }
        visited[s] = true;
        for(int w = 0; w < v; w++) {            // �������·��
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
    for(int i = 0; i < e; i++) {            // �����
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        dist[a][b] = dist[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    for(int i = 0; i < v; i++) {            // ��¼��ǰ�ڵ㵽������ľ���ͷ���
        nowDist[i] = dist[s][i];
        nowCost[i] = cost[s][i];
    }
    Dijkstra();
    cout<<nowDist[d]<<" "<<nowCost[d]<<endl;
    return 0;
}
