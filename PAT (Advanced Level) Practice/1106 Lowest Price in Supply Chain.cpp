#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int MAX = 100010;
int isLeaf = 0, minLayer = 0;

struct Node {
    int id, layer;
    vector<int> child;
} node[MAX];

void BFS(Node root) {       // 广度搜索
    root.layer = 0;
    if(root.child.size() == 0) {        // 没有叶子
        isLeaf = 1;
        minLayer = 0;
        return;
    }
    Node now;
    queue<Node> q;
    q.push(root);
    while(!q.empty()) {
        now = q.front();
        q.pop();
        if(now.child.size() == 0) {     // 叶子
            if(isLeaf != 0 && minLayer != now.layer) {
                break;
            } else {
                isLeaf++;
                minLayer = now.layer;
            }
        }
        if(isLeaf == 0) {               // 未发现叶子, 进入下一层
            for(int i = 0; i < now.child.size(); i++) {
                node[now.child[i]].layer = now.layer + 1;
                q.push(node[now.child[i]]);
            }
        }
    }
}

int main()
{
    int n;
    double p, r, price;
    scanf("%d %lf %lf", &n, &p, &r);
    r = 1 + r / 100;
    for(int i = 0; i < n; i++) {        // 输入
        int k, index;
        scanf("%d", &k);
        node[i].id = i;
        for(int j = 0; j < k; j++) {
            scanf("%d", &index);
            node[i].child.push_back(index);
        }
    }
    BFS(node[0]);
    price = p * pow(r, minLayer);
    printf("%.4f %d\n", price, isLeaf);         // 输出
    return 0;
}
