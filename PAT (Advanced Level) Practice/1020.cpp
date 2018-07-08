#include<iostream>
#include<queue>
using namespace std;
const int MAX = 50;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};
int pre[MAX], in[MAX], post[MAX];
int n;

Node* Create(int postL, int postR, int inL, int inR) {
    if(postL > postR) return NULL;
    Node* root = new Node;
    root->data = post[postR];           // 把post的最后一个元素作为root
    int k = 0;
    for(k = 0; k < n; k++) {
        if(in[k] == post[postR]) {      // 在in中找出root
            break;
        }
    }
    int leftNum = k - inL;
    root->lchild = Create(postL, postL + leftNum - 1, inL, k - 1);        // 左子树
    root->rchild = Create(postL + leftNum, postR - 1, k + 1, inL);        // 右子树
    return root;
}

void BFS(Node *root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* now = q.front();      // 取出最前面的节点
        q.pop();                    // 弹出
        cout<<(now->data);
        n--;
        if(n > 0) cout<<" ";
        if(now->lchild) q.push(now->lchild);
        if(now->rchild) q.push(now->rchild);
    }
    return;
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>post[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>in[i];
    }
    Node* root = Create(0, n - 1, 0, n - 1);
    BFS(root);
    return 0;
}

