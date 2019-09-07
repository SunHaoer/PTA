#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int MAX = 110;

struct Node{
    int lchild, rchild;
} node[MAX];

int n, num = 0;     // 节点个数n, 已输出节点数num
bool notRoot[MAX] = { false };

void print(int id) {
    printf("%d", id);
    num++;
    if(num<n) printf(" ");
    else printf("\n");
    return;
}

int strToNum(char c) {
    if(c=='-') return -1;
    else {
        notRoot[c-'0'] = true;
        return c - '0';
    }
    return 0;
}

int findRoot(){
    for(int i=0; i<n; i++) {
        if(notRoot[i]==false) return i;
    }
    return 0;
}

void postOrder(int root) {
    if(root==-1) return;
    postOrder(node[root].lchild);
    postOrder(node[root].rchild);
    swap(node[root].lchild, node[root].rchild);
    return;
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        print(now);
        if(node[now].lchild!=-1) q.push(node[now].lchild);
        if(node[now].rchild!=-1) q.push(node[now].rchild);
    }
    return;
}

void inOrder(int root) {
    if(root==-1) return;
    inOrder(node[root].lchild);
    print(root);
    inOrder(node[root].rchild);
    return;
}

int main()
{
    char lchild, rchild;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%*c%c %c", &lchild, &rchild);
        node[i].lchild = strToNum(lchild);
        node[i].rchild = strToNum(rchild);
    }
    int root = findRoot();
    postOrder(root);        // 后序遍历, 反转二叉树
    BFS(root);              // 层序遍历
    num = 0;
    inOrder(root);         // 中序遍历
    return 0;
}
