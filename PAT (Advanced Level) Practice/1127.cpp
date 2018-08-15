#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int MAX = 110;
int preOrder[MAX], inOrder[MAX], postOrder[MAX];

struct Node {
    int data, layer;
    Node *lchild, *rchild;
} node[MAX];

Node *Create(int inL, int inR, int postL, int postR, int layer) {       // 建树
    if(inL > inR || postL > postR) return NULL;
    Node *root = new Node();
    root->data = postOrder[postR];
    root->layer = layer;
    int index = inL;
    for(index = inL; index <= inR; index++) {      // 在inOrder中找root
        if(inOrder[index] == postOrder[postR]) {     // 找到root
            break;
        }
    }
    int numLeft = index - inL;      // in中左子树的节点数
    root->lchild = Create(inL, index - 1, postL, postL + numLeft - 1, layer + 1);
    root->rchild = Create(index + 1, inR, postL + numLeft, postR - 1, layer + 1);
    return root;
}

void ZigZaggingOrder(Node* root) {  // 这个奇怪的遍历！
    queue<Node*> q;
    vector<Node*> vt;
    q.push(root);
    int layer = root->layer;      // 当前深度
    bool flag = false;
    while(!q.empty()) {
        Node *now = q.front();
        q.pop();
        if(now->layer > layer) {
            if(layer % 2 == 0) {    // 偶数层, 正向输出
                for(int i = 0; i < vt.size(); i++) {
                    if(flag) printf(" ");
                    printf("%d", vt[i]->data);
                    flag = true;
                }
            } else {        // 奇数层, 逆向输出
                for(int i = vt.size() - 1; i >= 0; i--) {
                    if(flag) printf(" ");
                    printf("%d", vt[i]->data);
                    flag = true;
                }
            }
            vt.clear();
            layer = now->layer;
        }
        vt.push_back(now);
        if(now->lchild != NULL) q.push(now->lchild);
        if(now->rchild != NULL) q.push(now->rchild);
    }
    if(!vt.empty()) {
        if(layer % 2 == 0) {    // 偶数层, 正向输出
            for(int i = 0; i < vt.size(); i++) {
                if(flag) printf(" ");
                printf("%d", vt[i]->data);
            }
        } else {        // 奇数层, 逆向输出
            for(int i = vt.size() - 1; i >= 0; i--) {
                if(flag) printf(" ");
                printf("%d", vt[i]->data);
                flag = true;
            }
        }
        vt.clear();
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {    // 输入inOrder, 左根右
        scanf("%d", &inOrder[i]);
    }
    for(int i = 0; i < n; i++) {    // 输入postOrder, 左右根
        scanf("%d", &postOrder[i]);
    }
    Node* root = Create(0, n - 1, 0, n - 1, 1);
    ZigZaggingOrder(root);
    return 0;
}
