#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 110;

struct Node {
    int data;
    Node *lchild, *rchild;
} node[MAX];

int getHeight(Node *root) {         // 获取该节点高度
    if(root == NULL) return 0;
    int l = getHeight(root->lchild);
    int r = getHeight(root->rchild);
    return max(l, r) + 1;
}
void leftRotate(Node *&root) {       // 左旋
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    root = temp;
}

void rightRotate(Node *&root) {      // 右旋
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    root = temp;
}

void leftRightRotate(Node *&root) {     // 先左旋再右旋
    leftRotate(root->lchild);
    rightRotate(root);
}

void rightLeftRotate(Node *&root) {     // 先右旋再左旋
    rightRotate(root->rchild);
    leftRotate(root);
}

void Insert(Node *&root, int data) {     // 往二叉树里插入
    if(root == NULL) {
        root = new Node();
        root->data = data;
        root->lchild = root->rchild = NULL;
    } else {
        if(data < root->data) {          // 插往左子树
            Insert(root->lchild, data);
            int l = getHeight(root->lchild);
            int r = getHeight(root->rchild);
            if(l - r > 1) {
                if(data < root->lchild->data) {     // 插往左子树的左子树, LL结构
                    rightRotate(root);
                } else {      // 插往左子树的右子树, LR
                    leftRightRotate(root);
                }
            }
        } else {                         // 插往右子树
            Insert(root->rchild, data);
            int l = getHeight(root->lchild);
            int r = getHeight(root->rchild);
            if(r - l > 1) {
                if(data > root->rchild->data) {     // 插往右子树的右子树, RR
                    leftRotate(root);
                } else {
                    rightLeftRotate(root);
                }
            }
        }
    }
}

bool isNull = false, isComplete = true;
void levelOrder(Node *root) {                   // 层序遍历
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* now = q.front();
        q.pop();
        if(now->lchild != NULL) {       // 不是空节点
            q.push(now->lchild);        // 前面有空节点
            if(isNull) isComplete = false;
        } else {               // 遇到空节点
            isNull = true;
        }
        if(now->rchild != NULL) {
            q.push(now->rchild);
            if(isNull) isComplete = false;
        } else {
            isNull = true;
        }
        printf("%d", now->data);
        if(!q.empty()) printf(" ");
        else printf("\n");
    }
    if(isComplete) printf("YES\n");
    else printf("NO\n");
}

int main()
{
    int n, data[MAX];
    scanf("%d", &n);
    Node *root = NULL;
    for(int i = 0; i < n; i++) {    // 输入
        scanf("%d", &data[i]);
        Insert(root, data[i]);
    }
    levelOrder(root);
    return 0;
}
