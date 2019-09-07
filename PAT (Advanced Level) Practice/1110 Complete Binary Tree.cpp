#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
const int MAX = 25;
bool isRoot[MAX], isCBT = true, isEnd = false;
int root = -1, lastNode = 0;

struct Node {
    int lchild, rchild;
} node[MAX];

void BFS(int root, int n) {        // 广度搜索
    int cnt = 0;
    int now;
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        now = q.front();
        q.pop();
        cnt++;
        if(cnt == n) lastNode = now;
        if(node[now].lchild != -1) {
            if(isEnd) {             // 不是完全二叉树
                isCBT = false;
                break;
            }
            q.push(node[now].lchild);
        } else {                    // 这里子节点不足
            isEnd = true;
        }
        if(node[now].rchild != -1) {
            if(isEnd) {
                isCBT = false;
                break;
            }
            q.push(node[now].rchild);
        } else {
            isEnd = true;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    fill(isRoot, isRoot + MAX, true);
    for(int i = 0; i < n; i++) {    // 输入
        string ch1, ch2;
        cin>>ch1>>ch2;
        if(ch1 != "-") {
            node[i].lchild = atoi(ch1.c_str());
            isRoot[node[i].lchild] = false;
        } else {
            node[i].lchild = -1;
        }
        if(ch2 != "-") {
            node[i].rchild = atoi(ch2.c_str());
            isRoot[node[i].rchild] = false;
        } else {
            node[i].rchild = -1;
        }
    }
    for(int i = 0; i < n; i++) {    // 寻找根节点
        if(isRoot[i]) {
            root = i;
            break;
        }
    }
    BFS(root, n);
    if(isCBT) {                     // 输出
        cout<<"YES"<<" "<<lastNode<<endl;
    } else {
        cout<<"NO"<<" "<<root<<endl;
    }
    return 0;
}
