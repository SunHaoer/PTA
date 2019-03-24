#include<cstdio>
#include<vector>
using namespace std;
int n, ans = 0;
vector<int> arr;
vector<int> pre1, pre2, post1, post2;

struct Node {
    int data;
    Node *lchild, *rchild;
};

void create(Node *&root, int data) {
    if(root == NULL) {
        root = new Node;
        root->data = data;
        root->lchild = root->rchild = NULL;
    } else {
        if(data < root->data) create(root->lchild, data);
        else create(root->rchild, data);
    }
}

void preOrder(Node *root) {
    if(root == NULL) return;
    pre1.push_back(root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void preOrderMirror(Node *root) {
    if(root == NULL) return;
    pre2.push_back(root->data);
    preOrderMirror(root->rchild);
    preOrderMirror(root->lchild);
}

void postOrder(Node *root) {
    if(root == NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    post1.push_back(root->data);
}

void postOrderMirror(Node *root) {
    if(root == NULL) return;
    postOrderMirror(root->rchild);
    postOrderMirror(root->lchild);
    post2.push_back(root->data);
}

void print(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(i != 0) printf(" ");
        else printf("YES\n");
        printf("%d", vec[i]);
    }
}

int main()
{
    scanf("%d", &n);
    Node *root = NULL;
    int data;
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        create(root, data);
        arr.push_back(data);
    }
    preOrder(root);
    preOrderMirror(root);
    if(pre1 == arr) {
        postOrder(root);
        print(post1);
    } else if(pre2 == arr) {
        postOrderMirror(root);
        print(post2);
    } else {
        printf("NO\n");
    }
    return 0;
}
