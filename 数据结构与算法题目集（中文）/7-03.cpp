#include<cstdio>
using namespace std;
const int MAX = 12;

struct Node {
    char data;
    int lchild;
    int rchild;
} tree1[MAX], tree2[MAX];

int Create(Node tree[]) {          // ���ظ��ڵ��±�
    int n, root = -1;
    bool check[MAX] = { false };    // �˴������ʼ��
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char lc, rc;
        scanf("%*c%c%*c%c%*c%c", &tree[i].data, &lc, &rc);
        if(lc != '-') {             // �������ǿ�
            tree[i].lchild = lc - '0';
            check[tree[i].lchild] = true;
        } else {
            tree[i].lchild = -1;
        }
        if(rc != '-') {             // �������ǿ�
            tree[i].rchild = rc - '0';
            check[tree[i].rchild] = true;
        } else {
            tree[i].rchild = -1;
        }
    }
    for(int i = 0; i < n; i++) {    // Ѱ�Ҹ��ڵ�
        if(check[i] == false) {
            root = i;
            break;
        }
    }
    return root;
}

bool Judge(int root1, int root2) {
    if(root1 == -1 && root2 == -1) return true;       // tree1, tree2��Ϊ��
    if(root1 == -1 || root2 == -1) return false;      // tree1, tree2���ڷǿ�
    if(tree1[root1].data != tree2[root2].data) return false;        // tree1, tree2��ͬ
    if(tree1[tree1[root1].lchild].data == tree2[tree2[root2].lchild].data)                 // ��������ͬ
        return Judge(tree1[root1].lchild, tree2[root2].lchild) && Judge(tree1[root1].rchild, tree2[root2].rchild);
    else                                                                                   // ��������ͬ
        return Judge(tree1[root1].lchild, tree2[root2].rchild) && Judge(tree1[root1].rchild, tree2[root2].lchild);
}

int main()
{
    int root1 = -1, root2 = -1;
    root1 = Create(tree1);
    root2 = Create(tree2);
    if(Judge(root1, root2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
