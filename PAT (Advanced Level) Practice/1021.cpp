#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 10010;
vector<int> table[MAX];         // 邻接表
int father[MAX];        // 用于并查集的父亲的节点
bool isRoot[MAX];       // 根节点
int maxH = 0;   // 最大高度
vector<int> temp, ans;      // 临时存放最远点temp， 答案ans
int n;          // 节点数

void init() {           // 初始化
    for(int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int findFather(int x) {            // 寻找父亲节点
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != father[a]) {         // 压缩路径
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {          // 并查集
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faA] = faB;
    }
}

int calBlock() {               // 计算连通块
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        isRoot[findFather(i)] = true;
    }
    for(int i = 1; i <= n; i++) {
        ans += isRoot[i];
    }
    return ans;
}

void DFS(int u, int height, int pre) {
    if(height > maxH) {         // 更新最大高度
        temp.clear();
        temp.push_back(u);
        maxH = height;
    } else if(height == maxH) {     // 添加符合的节点
        temp.push_back(u);
    }
    for(int i = 0; i < table[u].size(); i++) {
        if(table[u][i] == pre) continue;
        DFS(table[u][i], height + 1, u);
    }
}

int main()
{
    scanf("%d", &n);
    init();
    for(int i = 0; i < n - 1; i++) {        // 建图
        int a, b;
        scanf("%d%d", &a, &b);
        table[a].push_back(b);
        table[b].push_back(a);
        Union(a, b);
    }
    int num = calBlock();          // 计算连通块数
    if(num != 1) {      // 非连通块
        printf("Error: %d components\n", num);
    } else {            // 连通块, 求根节点
        DFS(1, 1, -1);
        ans = temp;
        DFS(ans[0], 1, -1);
        for(int i = 0; i < temp.size(); i++) {      // 所求根节点为两个集合的并集
            ans.push_back(temp[i]);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] != ans[i - 1]) {
                printf("%d\n", ans[i]);
            }
        }
    }
    return 0;
}
