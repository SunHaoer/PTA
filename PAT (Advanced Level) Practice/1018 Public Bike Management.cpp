#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF = 510;
const int MAX = 510;
int table[MAX][MAX];    // ͼ
int weight[MAX];        // �ڵ�Ȩ��
int d[MAX], c[MAX];     // ��ǰ�ڵ㵽���ľ���d, ����c
bool visited[MAX];
int cmax, n, s, m;      // �������cmax, �ڵ�����n, �յ�s, ����m
vector<int> pre[MAX];        // ǰ���ڵ�
vector<int> tempPath, path;  // ��ʱ·��tempPath, ����·��path
int minNeed = INF, minRemain = INF;      // ����Я����ĿminNeed, ���ٴ�����ĿminRemain

void init() {           // ��ʼ��
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(d, d + MAX, INF);
    fill(c, c + MAX, INF);
    fill(visited, visited + MAX, false);
    d[0] = 0;
    c[0] = 0;
}

void Dijkstra() {       // ֻ�����·��
    for(int i = 0; i <= n; i++) {
        int u = -1, minn = INF;
        for(int j = 0; j <= n; j++) {
            if(visited[j] == false && d[j] < minn) {
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int v = 0; v <= n; v++) {
            if(visited[v] == false && d[u] + table[u][v] < d[v]) {
                d[v] = d[u] + table[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            } else if(visited[v] == false && d[u] + table[u][v] == d[v]) {
                pre[v].push_back(u);
            }
        }
    }
}

void DFS(int v) {           // �����·����Ѱ������·��
    if(v == 0) {
        tempPath.push_back(v);
        int need = 0, remain = 0;       // tempPath����ҪЯ������Ŀneed, ������Ŀremain
        for(int i = tempPath.size() - 1; i >= 0; i--) {
            int id = tempPath[i];
            if(weight[id] > 0) {        // ����
                remain += weight[id];
            } else {                    // ����
                if(remain > abs(weight[id])) {      // ��ǰ�����㹻����
                    remain -= abs(weight[id]);
                } else {
                    need += (abs(weight[id]) - remain);
                    remain = 0;
                }
            }
        }
        if(need < minNeed) {            // ��Ҫ������Ŀ����(·������)
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        } else if(need == minNeed && remain < minRemain) {      // ���ص���Ŀ����
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    scanf("%d%d%d%d", &cmax, &n, &s, &m);
    for(int i = 1; i <= n; i++) {        // ������ڵ�Ȩ��
        scanf("%d", &weight[i]);
        weight[i] -= (cmax / 2);         // ����״̬Ϊ0
    }
    init();

    for(int i = 0; i < m; i++) {         // ��ͼ
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        table[a][b] = table[b][a] = c;
    }
    Dijkstra();
    DFS(s);
    printf("%d ", minNeed);
    for(int i = path.size() - 1; i >= 0; i--) {     // ���·��
        printf("%d", path[i]);
        if(i > 0) printf("->");
    }
    printf(" %d", minRemain);
    return 0;
}
