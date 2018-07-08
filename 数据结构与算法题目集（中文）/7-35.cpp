#include<iostream>
#include<cstring>
using namespace std;
const int INF = 510;
const int MAX = 510;
int table[MAX][MAX];        // ͼ
int weight[MAX], w[MAX];    // ��������Ȩ��weight, ·��Ȩ�غ�w
int d[MAX], num[MAX], pre[MAX];               // ÿ�����㵽���ľ���d, ���·����num, ��һ�ڵ�pre
bool visited[MAX];
int n, m, st, ed;           // ������n, ����m, ���st, �յ�ed

void init() {               // ��ʼ��
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(d, d + MAX, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[st] = 0;               // �����ľ���
    w[st] = weight[st];      // ����Ȩ��
    num[st] = 1;
}

void Dijkstra() {
    for(int i = 0; i < n; i++) {
        int u = -1, minn = INF;         // ��������Ľڵ�u, ��̵ľ���minn
        for(int j = 0; j < n; j++) {
            if(visited[j] == false && d[j] < minn) {
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) return;             // û���ܹ���ͨ�Ķ���
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(visited[v] == false && table[u][v] != INF) {         // vΪδ���ʽڵ�, ��u-v��ͨ
                if(d[u] + table[u][v] < d[v]) {                     // ��uΪ�н�·������
                    d[v] = d[u] + table[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pre[v] = u;
                } else if(d[u] + table[u][v] == d[v]) {
                    if(w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                        pre[v] = u;
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

void DFS(int now) {
    if(now == st) {
        cout<<now;
        return;
    }
    DFS(pre[now]);
    cout<<" "<<now;
}

int main()
{
    cin>>n>>m>>st>>ed;
    for(int i = 0; i < n; i++) {
        cin>>weight[i];
    }
    init();
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        table[a][b] = table[b][a] = c;
    }

    Dijkstra();
    cout<<num[ed]<<" "<<w[ed]<<endl;
    DFS(ed);
    cout<<endl;
    return 0;
}
