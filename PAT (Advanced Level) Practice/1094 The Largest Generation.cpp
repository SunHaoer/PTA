#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 550;
bool isRoot[MAX];

struct Node {
    int data, address, layer;
    vector<int> child;
} node[MAX];

int cnt[MAX];
void BFS(int root) {        // 广度搜索
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();
        cnt[node[now].layer]++;
        q.pop();
        for(int i = 0; i < node[now].child.size(); i++) {
            node[node[now].child[i]].layer = node[now].layer + 1;
            q.push(node[now].child[i]);
        }
    }
}

int main()
{
    fill(isRoot, isRoot + MAX, true);
    int n, m, root = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {    // 建树
        int address, k;
        scanf("%d %d", &address, &k);
        node[address].address = address;
        for(int j = 0; j < k; j++) {
            int child;
            scanf("%d", &child);
            isRoot[child] = false;
            node[address].child.push_back(child);
            node[child].address = child;
        }
    }
    for(int i = 1; i <= n; i++) {   // 寻找根节点
        if(isRoot[i]) root = i;
    }
    node[root].layer = 1;
    BFS(root);
    int maxLayer = 0, maxCnt = 0;
    for(int i = 1; i < MAX; i++) {  // 寻找最大层数
        if(cnt[i] > maxCnt) {
            maxCnt = cnt[i];
            maxLayer = i;
        }
        if(cnt[i] == 0) break;
    }
    printf("%d %d\n", maxCnt, maxLayer);    // 输出
    return 0;
}
