#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 550;
bool isRoot[MAX];
int data[MAX];

struct Node {
    int data;
    int address, lchild, rchild;
} node[MAX];

int index = 0;
void inOrder(int root) {        // 中序遍历
    if(root == -1) return;
    if(node[root].lchild != -1) inOrder(node[root].lchild);
    node[root].data = data[index++];        // 中序遍历的顺序由小到大复制
    if(node[root].rchild != -1) inOrder(node[root].rchild);
}

void levelOrder(int root) {     // 中序遍历
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        printf("%d", node[now].data);
        if(node[now].lchild != -1) {
            q.push(node[now].lchild);
        }
        if(node[now].rchild != -1) {
            q.push(node[now].rchild);
        }
        if(!q.empty()) printf(" ");
        else printf("\n");
    }
}

int main()
{
    int n, root = -1;
    scanf("%d", &n);
    fill(isRoot, isRoot + MAX, true);
    for(int i = 0; i < n; i++) {    // 输入
        int a, b;
        scanf("%d %d", &a, &b);
        node[i].address = i;
        node[i].lchild = a;
        node[i].rchild = b;
        isRoot[a] = isRoot[b] = false;
    }
    for(int i = 0; i < n; i++) {    // 寻找root
        if(isRoot[i]) {
            root = i;
            break;
        }
    }
    for(int i = 0; i < n; i++) {    // 输入data
        scanf("%d", &data[i]);
    }
    sort(data, data + n);
    inOrder(root);
    levelOrder(root);
    return 0;
}
