#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 1010;
int table[MAX][MAX];        // ͼtable
bool visited[MAX];
int n, m, k;           // ������n, ����m, ��ѯ��k

void DFS(int now, int dis) {
    if(now == dis) return;      // �ýڵ㲻����
    visited[now] = true;
    for(int i = 1; i <= n; i++) {
        if(table[now][i] == 1 && visited[i] == false) {
            DFS(i, dis);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {        // ��ͼ
        int a, b;
        scanf("%d%d", &a, &b);
        table[a][b] = table[b][a] = 1;
    }
    for(int i = 0; i < k; i++) {        // ��ѯ
        int dis;            // ��ʧ�ڵ�dis
        scanf("%d", &dis);
        memset(visited, false, sizeof(visited));
        int ans = 0;        // ����
        for(int v = 1; v <= n; v++) {
            if(v != dis && visited[v] == false) {        // �ýڵ�δɾ�� && δ����
                DFS(v, dis);
                ans++;
            }
        }
        printf("%d\n", ans - 1);
    }
}
