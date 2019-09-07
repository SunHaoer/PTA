#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *lchild, *rchild;
    Node() {
        lchild = NULL;
        rchild = NULL;
    }
};

vector<int> pre;
void postOrder(Node *root) {
    if(root->lchild != NULL) postOrder(root->lchild);
    if(root->rchild != NULL) postOrder(root->rchild);
    pre.push_back(root->data);
}

int main()
{
    int repeat, n;
    scanf("%d %d", &repeat, &n);
    while(repeat--) {       // 重复repeat次
        int flag = 0;
        queue<Node*> q;
        Node *root = new Node;
        int num;
        scanf("%d", &num);
        root->data = num;
        q.push(root);
        for(int i = 1; i < n; i++) {        // 根据层序遍历建树
            Node *now = q.front();
            if(now->lchild != NULL && now->rchild != NULL) {
                q.pop();
                now = q.front();
            }
            scanf("%d", &num);
            if(flag != 3) {             // 讨论大顶堆或小顶堆
                if(num < now->data) {
                    if(flag == 2) {      // 不是顶堆
                        flag = 3;
                    } else {
                        flag = 1;
                    }
                }
                if(num > now->data) {
                    if(flag == 1) {
                        flag = 3;
                    } else {
                        flag = 2;
                    }
                }
            }
            if(now->lchild == NULL) {       // 往叶子中插入
                now->lchild = new Node;
                now->lchild->data = num;
                q.push(now->lchild);
            } else if(now->rchild == NULL) {
                now->rchild = new Node;
                now->rchild->data = num;
                q.push(now->rchild);
            }
        }
        if(flag == 1) printf("Max Heap\n");     // 输出
        if(flag == 2) printf("Min Heap\n");
        if(flag == 3) printf("Not Heap\n");
        pre.clear();
        postOrder(root);
        for(int i = 0; i < pre.size(); i++) {
            printf("%d", pre[i]);
            if(i != pre.size() - 1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
