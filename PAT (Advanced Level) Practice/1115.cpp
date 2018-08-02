#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 10010;
int maxLayer = 0, ans[MAX];

struct Node {
    int data, layer;
    Node *lchild, *rchild;
};

void Insert(Node *&root, int data) {    // 插入元素
    if(root == NULL) {
        root = new Node;
        root->data = data;
        root->lchild = root->rchild = NULL;
        return;
    }
    if(data <= root->data) Insert(root->lchild, data);
    else Insert(root->rchild, data);
}

void layerOrder(Node* root) {       // 层序遍历
    queue<Node*> q;
    root->layer = 1;
    q.push(root);
    while(!q.empty()) {
        Node* now = q.front();
        q.pop();
        ans[now->layer]++;
        maxLayer = (maxLayer, now->layer);
        if(now->lchild != NULL) {
            now->lchild->layer = now->layer + 1;
            q.push(now->lchild);
        }
        if(now->rchild != NULL) {
            now->rchild->layer = now->layer + 1;
            q.push(now->rchild);
        }
    }
}

int main()
{
    int n, data;
    scanf("%d", &n);
    Node* root = NULL;
    for(int i = 0; i < n; i++) {        // 输入
        scanf("%d", &data);
        Insert(root, data);
    }
    layerOrder(root);
    printf("%d + %d = %d\n", ans[maxLayer], ans[maxLayer - 1], ans[maxLayer] + ans[maxLayer - 1]);
    return 0;
}
