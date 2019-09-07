#include<iostream>
using namespace std;
const int MAX = 15;
int tree1[MAX], tree2[MAX];
bool flag = true;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

void Insert(Node* &root, int data) {                // ����ڵ�
    if(root == NULL) {              // �սڵ�, ����
        root = new Node;
        root->data = data;
        root->lchild = root->rchild = NULL;
        return;
    }
    if(data < root->data) Insert(root->lchild, data);       // С, ����������
    else Insert(root->rchild, data);                        // ��, ����������
    return;
}

void Create(Node* &root, int n) {               // ����
    int data;
    root = NULL;
    for(int i = 0; i < n; i++) {
        cin>>data;
        Insert(root, data);
    }
}

void preOrder(Node* root1, Node* root2) {       // �������
    if(root1 == NULL && root2 == NULL) {
        return;
    }
    if(root1 == NULL || root2 == NULL || root1->data != root2->data) {
        flag = false;
        return;
    }
    preOrder(root1->lchild, root2->lchild);
    preOrder(root1->rchild, root2->rchild);
    return;
}

int main()
{
    int n, l;
    Node *root1, *root2;        // ԭ������root1, ��������root2
    while(cin>>n) {
        if(n == 0) break;
        cin>>l;
        Create(root1, n);
        for(int i = 0; i < l; i++) {
            Create(root2, n);
            flag = true;
            preOrder(root1, root2);
            if(flag == true) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
