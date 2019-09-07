#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 1010;
vector<int> table[MAX];     // 邻接表
int father[MAX];
bool visited[MAX];
int n, m, k;        // 节点数n, 边数m, 查询数k

void init() {       // 初始化
    for(int i = 1; i <= MAX; i++) {
        father[i] = i;
        visited[i] = false;
    }
}

int findFather(int x) {
    int a = x;
    while(x != father[x]) {     // 寻找根节点
        x = father[x];
    }
    while(a != father[a]) {     // 压缩路径
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {      // 合并a, b集合
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faA] = faB;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {    // 建图
        int a, b;
        scanf("%d%d", &a, &b);
        table[a].push_back(b);
        table[b].push_back(a);
    }
    int dis;       // 删除的节点
    for(int l = 0; l < k; l++) {
        scanf("%d", &dis);
        init();
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < table[i].size(); j++) {
                int u = i, v = table[i][j];         // 边的两个端点u, v
                if(u == dis || v == dis) continue;  // 跳过删除的节点
                Union(u, v);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {       // 遍历所有节点
            if(i == dis) continue;
            int fa_i = findFather(i);       // 顶点i的根节点
            if(visited[fa_i] == false) {
                ans++;
                visited[fa_i] = true;
            }
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
