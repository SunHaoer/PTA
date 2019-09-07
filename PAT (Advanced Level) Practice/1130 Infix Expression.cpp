#include<iostream>
using namespace std;
const int MAX = 110;
string result = "";
int root = -1;

struct Node {
    string data;
    int lchild, rchild;
} node[MAX];

string inOrder(int index) {         // 把每个非叶子非根节点的表达式放入()中
    if(node[index].lchild != -1) node[index].data = inOrder(node[index].lchild) + node[index].data;     // 左子树非空
    if(node[index].rchild != -1) node[index].data = node[index].data + inOrder(node[index].rchild);     // 右子树非空
    if(index != root && (node[index].lchild != -1 || node[index].rchild != -1) ) node[index].data = "(" + node[index].data + ")";              // 非根, 非叶子节点
    return node[index].data;
}

int main()
{
    int n;
    bool isRoot[MAX];
    fill(isRoot, isRoot + MAX, true);
    cin>>n;
    for(int i = 1; i <= n; i++) {    // 输入
        cin>>node[i].data>>node[i].lchild>>node[i].rchild;
        isRoot[node[i].lchild] = isRoot[node[i].rchild] = false;
    }
    for(int i = 1; i <= n; i++) {    // 寻找根节点
        if(isRoot[i]) {
            root = i;
            break;
        }
    }
    cout<<inOrder(root)<<endl;       // 计算并输出
    return 0;
}
