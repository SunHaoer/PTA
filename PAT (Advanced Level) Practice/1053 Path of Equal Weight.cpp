#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 110;

struct Node{
    int weight;
    vector<int> child;
} node[MAX];
int n, m, s;        // 节点数, 非叶子节点数, 给定的和
int path[MAX];      // 记录路径

bool cmp(int a, int b) {
    return node[a].weight > node[b].weight;
}

void DFS(int index, int numNode, int sum) {
    if(sum > s) return;             // 超过指定的值
    if(sum == s) {
        if(node[index].child.size() != 0) return;       // 非叶子节点， 剪枝
        for(int i = 0; i < numNode; i++) {      // 符合, 输出
            printf("%d", node[path[i]].weight);     // 输出路径权值
            if(i < numNode - 1) printf(" ");
            else printf("\n");
        }
        return;
    }
    for(int i = 0; i < node[index].child.size(); i++) {     // 枚举所有子节点
        int child = node[index].child[i];
        path[numNode] = child;                      // 将child加入path路径
        DFS(child, numNode + 1, sum + node[child].weight);
    }
    return;
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < n; i++) {
        scanf("%d", &node[i].weight);       // 输入每个节点的权值
    }
    int id, k, child;
    for(int i = 0; i < m; i++) {            // 输入非叶子节点的孩子
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            node[id].child.push_back(child);        // 添加孩子节点
        }
        sort(node[id].child.begin(), node[id].child.end(), cmp);
    }
    path[0] = 0;
    DFS(0, 1, node[0].weight);
    return 0;
}
