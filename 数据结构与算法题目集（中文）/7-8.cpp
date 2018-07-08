#include<iostream>
using namespace std;
const int INF = 110;
const int MAX = 110;
int dist[MAX][MAX];     // 2������ľ���
int v, e;           // ����v, ��e

void Init() {           // ��ʼ��
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            if(i == j) {            // �Լ����Լ��ľ���
                dist[i][j] = 0;
            } else {                // δ֪���������Ϊ�����
                dist[i][j] = INF;
            }
        }
    }
}

void Floyd() {     // �����·���㷨
    for(int k = 1; k <= v; k++) {               // kΪi, j���н�
        for(int i = 1; i <= v; i++) {
            for(int j = 1; j <= v; j++) {       // ����i->k->j < i->j
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    cin>>v>>e;
    Init();
    for(int i = 0; i < e; i++) {    // ����
        int a, b, c;
        cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = c;
    }
    Floyd();
    int minn = INF, maxn = -INF, index;
    for(int i = 1; i <= v; i++) {       // ����Զ�������Сֵ
        maxn = 0;
        for(int j = 1; j <= v; j++) {
           maxn = max(maxn, dist[i][j]);
        }
        if(maxn < minn) {               // ������Сֵ
            minn = maxn;
            index = i;
        }
    }
    if(minn == INF) cout<<"0"<<endl;
    else cout<<index<<" "<<minn<<endl;
    return 0;
}
