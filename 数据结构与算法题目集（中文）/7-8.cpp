#include<iostream>
using namespace std;
const int INF = 110;
const int MAX = 110;
int dist[MAX][MAX];     // 2个顶点的距离
int v, e;           // 顶点v, 边e

void Init() {           // 初始化
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            if(i == j) {            // 自己跟自己的距离
                dist[i][j] = 0;
            } else {                // 未知顶点距离标记为无穷大
                dist[i][j] = INF;
            }
        }
    }
}

void Floyd() {     // 求最短路径算法
    for(int k = 1; k <= v; k++) {               // k为i, j的中介
        for(int i = 1; i <= v; i++) {
            for(int j = 1; j <= v; j++) {       // 距离i->k->j < i->j
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    cin>>v>>e;
    Init();
    for(int i = 0; i < e; i++) {    // 输入
        int a, b, c;
        cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = c;
    }
    Floyd();
    int minn = INF, maxn = -INF, index;
    for(int i = 1; i <= v; i++) {       // 求最远距离的最小值
        maxn = 0;
        for(int j = 1; j <= v; j++) {
           maxn = max(maxn, dist[i][j]);
        }
        if(maxn < minn) {               // 更新最小值
            minn = maxn;
            index = i;
        }
    }
    if(minn == INF) cout<<"0"<<endl;
    else cout<<index<<" "<<minn<<endl;
    return 0;
}
