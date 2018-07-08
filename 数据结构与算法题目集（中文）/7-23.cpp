#include<iostream>
#include<queue>
using namespace std;
const int MAX = 55;
char pre[MAX], in[MAX];      // 先序遍历pre[], 中序遍历in[]

struct Node {
    char data;
    int layer;
    Node* lchild;
    Node* rchild;
};

Node* create(int preL, int preR, int inL, int inR) {        // 建树
    if(preL > preR) return NULL;
    Node* root = new Node;
    root->data = pre[preL];
    int k = 0;
    for(k = inL; k <= inR; k++) {
        if(in[k] == pre[preL]) break;
    }
    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

void layerOrder(Node* root) {           // 层序遍历
    queue<Node*> q;
    int level = 1;
    root->layer = 1;
    q.push(root);
    while(!q.empty()) {
        Node* now = q.front();
        //cout<<(now->data)<<endl;
        level = max(level, now->layer);
        q.pop();
        if(now->lchild != NULL) {
            q.push(now->lchild);
            now->lchild->layer = now->layer + 1;
        }
        if(now->rchild != NULL) {
            q.push(now->rchild);
            now->rchild->layer = now->layer + 1;
        }
    }
    cout<<level<<endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {        // 输入先序遍历
        cin>>pre[i];
    }
    for(int i = 0; i < n; i++) {        // 输入中序遍历
        cin>>in[i];
    }
    Node* root = create(0, n - 1, 0, n - 1);
    layerOrder(root);
    return 0;
}
