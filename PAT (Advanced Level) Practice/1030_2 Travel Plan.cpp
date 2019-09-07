#include<iostream>
#include<vector>
using namespace std;
const int INF = 510;
const int MAX = 510;
int table[MAX][MAX], cost[MAX][MAX];        // ͼtable, ����cost
int d[MAX], c[MAX], minCost = INF;             // ÿ���ڵ㵽���ľ���d, ����c
bool visited[MAX];
int n, m, st, ed;
vector<int> pre[MAX];
vector<int> tempPath, path;     // ��ʱ·��tempPath, ����·��path

void init() {
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(cost[0], cost[0] + MAX * MAX, INF);
    fill(d, d + MAX, INF);
    fill(c, c + MAX, INF);
}

void Dijkstra() {
    d[st] = 0;
    c[st] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = INF;
        for(int j = 0; j < n; j++) {        // Ѱ�Ҿ�������Ľڵ�
            if(visited[j] == false && d[j] < minn) {
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) return;             // û����ͨ�Ľڵ�
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(visited[v] == false && d[u] + table[u][v] < d[v]) {
                d[v] = d[u] + table[u][v];
                pre[v].clear();         // ���pre[v]�ڵ�
                pre[v].push_back(u);    // ��u����v��ǰ���ڵ�
            } else if(visited[v] == false && d[u] + table[u][v] == d[v]) {
                pre[v].push_back(u);    // ��u����v��ǰ���ڵ�
            }
        }
    }
}

void DFS(int now) {
    if(now == st) {         // �ݹ鵽·�����
        tempPath.push_back(now);
        int tempCost = 0;
        for(int i = tempPath.size() - 1; i > 0; i--) {      // ���ŷ���
            int id = tempPath[i], idNext = tempPath[i - 1];
            tempCost += cost[id][idNext];
        }
        if(tempCost < minCost) {        // ��ǰ·���ı�Ȩ�͸�С
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(now);
    for(int i = 0; i < pre[now].size(); i++) {
        DFS(pre[now][i]);
    }
    tempPath.pop_back();
}

int main()
{
    cin>>n>>m>>st>>ed;
    init();
    for(int i = 0; i < m; i++) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        table[a][b] = table[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    Dijkstra();
    DFS(ed);
    for(int i = path.size() - 1; i >= 0; i--) {
        cout<<path[i]<<" ";
    }
    cout<<d[ed]<<" "<<minCost<<endl;
    return 0;
}
