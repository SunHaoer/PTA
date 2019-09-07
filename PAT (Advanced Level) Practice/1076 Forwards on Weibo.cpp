#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 1010;
vector<int> table[MAX];
bool visited[MAX];
int n, level, numQuery;       // 节点数n, 限制层数level, 查询个数numQuery

int BFS(int x) {
    int ans = 0;
    queue<int> q;
    int last = x;       // 上一个节点
    int tail = 0;       // 尾巴节点
    int layer = 0;      // 层数
    q.push(x);
    visited[x] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 0; i < table[now].size(); i++) {
            if(visited[table[now][i]] == false) {        // 未被访问, 且在规定范围内
                ans++;
                tail = table[now][i];
                q.push(table[now][i]);
                visited[table[now][i]] = true;
            }
        }
        if(now == last) {
            layer++;
            last = tail;
        }
        if(layer == level) break;
    }
    return ans;
}


int main()
{
    scanf("%d%d", &n, &level);
    for(int i = 1; i <= n; i++) {
        int m, id;      // 关注人数m, 关注人Id
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &id);
            table[id].push_back(i);
        }
    }
    scanf("%d", &numQuery);
    for(int i = 0; i < numQuery; i++) {
        fill(visited, visited + MAX, false);
        int id;
        scanf("%d", &id);
        int ans = BFS(id);
        printf("%d\n", ans);
    }
    return 0;
}
