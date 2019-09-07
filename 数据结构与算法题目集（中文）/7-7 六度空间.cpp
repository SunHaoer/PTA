#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int MAX = 10010;
int hashTable[MAX][MAX] = { 0 };
bool visited[MAX] = { false };
int n, m, ans = 0, layer = 0;       // 节点数n, 边数m, 相关节点数ans, 层数layer

void BFS(int x) {       // 广度搜索
    queue<int> q;
    int last = x;       // 上一个节点
    int tail = 0;       // 尾巴
    q.push(x);
    visited[x] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(hashTable[now][i] == 1 && visited[i] == false) {
                ans++;
                tail = i;
                visited[i] = true;
                q.push(i);
            }
        }
        if(now == last) {               // last只可能从前往后, 即for中x的方向
            layer++;
            last = tail;
        }
        if(layer == 6) break;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        hashTable[v1][v2] = 1;
        hashTable[v2][v1] = 1;
    }
    for(int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        ans = 0;
        layer = 0;
        BFS(i);
        printf("%d: %.2f%%\n", i, (ans + 1) * 1.0 / n * 100);
    }
    return 0;
}
