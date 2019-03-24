#include<cstdio>
#include<queue>
using namespace std;
const int MAX = 35;
int pre[MAX], in[MAX], post[MAX];
int n;

struct Node {
    int data;
    Node *lchild, *rchild;
};

Node* create(int postL, int postR, int inL, int inR) {
    if(postL > postR) return NULL;
    Node *root = new Node;
    root->data = post[postR];
    int index = -1;
    for(index = inL; index <= inR; index++) {
        if(in[index] == root->data) break;
    }
    int numLeft = index - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, index - 1);
    root->rchild = create(postL + numLeft, postR - 1, index + 1, inR);
    return root;
}

void BFS(Node *root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *now = q.front();
        printf("%d", now->data);
        if(--n > 0) printf(" ");
        else printf("\n");
        q.pop();
        if(now->lchild != NULL) q.push(now->lchild);
        if(now->rchild != NULL) q.push(now->rchild);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    Node *root = create(0, n - 1, 0, n - 1);
    BFS(root);
    return 0;
}
