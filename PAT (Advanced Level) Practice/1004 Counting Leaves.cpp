#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 110;
vector<int> table[MAX];       // 邻接表table
int leaf[MAX];          // 每层叶子节点的个数leaf
int level = 1;          // 树的深度level(数组容量)

void DFS(int index, int h) {    // 当前节点编号index, 深度h
    level = max(level, h);              // level为最大深度, 用作leaf数组容量
    if(table[index].size() == 0) {      // 叶子
        leaf[h]++;
        return;
    }
    for(int i = 0; i < table[index].size(); i++) {
        DFS(table[index][i], h + 1);
    }
}

int main()
{
    int n, m, k, parent , child;       // 总结点数n, 叶子数m, 每个节点子节点数k
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {       // 建图
        scanf("%d%d", &parent, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            table[parent].push_back(child);
        }
    }
    DFS(1, 1);
    printf("%d", leaf[1]);
    for(int i = 2; i <= level; i++) {
        printf(" %d", leaf[i]);
    }
    return 0;
}
