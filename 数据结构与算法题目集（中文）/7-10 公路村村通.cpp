#include<iostream>
using namespace std;
const int INF = 1010;
const int MAX = 1010;
int table[MAX][MAX];        // ͼtable
int d[MAX];              // �����ϵĻ���d
bool visited[MAX];
int n, m;       // ������n, ����m

void init() {
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(d, d + MAX, INF);
    fill(visited, visited + MAX, false);
    d[1] = 0;
}

int prim() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int u = -1, minn = INF;
        for(int j = 1; j <= n; j++) {           // Ѱ�ҵ����ϵ���̾���
            if(visited[j] == false && d[j] < minn) {
                minn = d[j];
                u = j;
            }
        }
        if(u == -1) return -1;                  // ʣ�½ڵ㲻��ͨ
        visited[u] = true;
        ans += d[u];                            // ������С��������Ȩֵ
        for(int v = 1; v <= n; v++) {           // ���¸��ڵ���С����
            if(visited[v] == false && table[u][v] < d[v]) {
                d[v] = table[u][v];
            }
        }
    }
    return ans;
}

int main()
{
    cin>>n>>m;
    init();
    for(int i = 0; i < m; i++) {        // ���� ͼ
        int a, b, c;
        cin>>a>>b>>c;
        table[a][b] = table[b][a] = c;
    }
    int ans = prim();
    cout<<ans<<endl;
    return 0;
}
