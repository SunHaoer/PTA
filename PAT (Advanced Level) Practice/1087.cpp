#include<iostream>
#include<map>
using namespace std;
const int INF = 100000000;              // INF必须足够大
const int MAX = 250;
int table[MAX][MAX];        // 图
int weight[MAX], d[MAX], h[MAX];        // 顶点权重(happies值), 当前节点到起点距离d, 当前快乐值h
bool visited[MAX];
int n, k, st, ed;           // 节点数n, 边数k, 起点st, 终点ed
map<string, int> nameToId;
map<int, string> idToName;
int num[MAX], ans[MAX], pre[MAX];       // 最短路径数num, 此路径上的节点数ans, 前驱节点pre

void init() {       // 初始化
    fill(table[0], table[0] + MAX * MAX, INF);
    fill(d, d + MAX, INF);
    fill(h, h + MAX, 0);
    fill(visited, visited + MAX, false);
    fill(ans, ans + MAX, 0);
    fill(num, num + MAX, 0);
    for(int i = 0; i < MAX; i++) {
        pre[i] = i;
    }
    d[st] = 0;
    h[st] = weight[st];
    num[st] = 1;
}

void Dijkstra(int st) {
    for(int i = 0; i < n; i++) {
        int u = -1, minn = INF;
        for(int j = 0; j < n; j++) {
            if(visited[j] == false && d[j] < minn) {
                minn = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(visited[v] == false) {
                if(d[u] + table[u][v] < d[v]) {
                    d[v] = d[u] + table[u][v];
                    num[v] = num[u];
                    h[v] = h[u] + weight[v];
                    ans[v] = ans[u] + 1;
                    pre[v] = u;
                } else if(d[u] + table[u][v] == d[v]) {
                    num[v] += num[u];
                    if(h[u] + weight[v] > h[v]) {       // 快乐值更大
                        h[v] = h[u] + weight[v];
                        ans[v] = ans[u] + 1;
                        pre[v] = u;
                    } else if(h[u] + weight[v] == h[v] && ans[u] + 1 < ans[v]) {
                        ans[v] = ans[u] + 1;
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int v) {
    if(v == st) {
        cout<<idToName[v];
        return;
    }
    DFS(pre[v]);
    cout<<"->"<<idToName[v];
}

int main()
{
    string str;
    cin>>n>>k>>str;
    nameToId[str] = 0;
    idToName[0] = str;
    st = 0;

    for(int i = 1; i < n; i++) {        // 输入顶点权重
        cin>>str>>weight[i];
        nameToId[str] = i;
        idToName[i] = str;
        if(str == "ROM") ed = i;        // ROM为终点
    }
    init();
    for(int i = 0; i < k; i++) {        // 建图
        string str1, str2;
        int a, b, c;
        cin>>str1>>str2>>c;
        a = nameToId[str1];
        b = nameToId[str2];
        table[a][b] = table[b][a] = c;
    }
    Dijkstra(0);
    cout<<num[ed]<<" "<<d[ed]<<" "<<h[ed]<<" "<<h[ed] / ans[ed]<<endl;
    DFS(ed);
    cout<<endl;
    return 0;
}
