#include<cstdio>
#include<queue>
using namespace std;
const int MAX = 50;
int pre[MAX], in[MAX], post[MAX];
int n;

struct Node {
    int data;
    Node *lchild, *rchild;
};

Node* create(int inL, int inR, int preL, int preR) {
    if(inL > inR) return NULL;
    Node *root = new Node();
    root->data = pre[preL];
    //printf("%d\n", root->data);
    int index = -1;
    for(index = inL; index <= inR; index++) {
        if(in[index] == root->data) break;
    }
    int numLeft = index - inL;
    root->lchild = create(inL, inL + numLeft - 1, preL + 1, preL + numLeft);
    root->rchild = create(inL + numLeft + 1, inR, preL + numLeft + 1, preR);
    return root;
}

void level(Node *root) {
    queue<Node*> q;
    q.push(root);
    int ans = 0;
    while(!q.empty()) {
        Node* now = q.front();

        ans++;
        printf("%d", now->data);
        if(ans == n) printf("\n");
        else printf(" ");
        q.pop();
        if(now->rchild != NULL) q.push(now->rchild);
        if(now->lchild != NULL) q.push(now->lchild);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    Node *root = create(0, n - 1, 0, n - 1);
    //postOrder(root);
    level(root);
    //BFS(root);
    return 0;
}
