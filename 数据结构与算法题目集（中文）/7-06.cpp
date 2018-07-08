#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAX = 15;
int hashTable[MAX][MAX] = { 0 };
bool visited[MAX] = { false };      // 标记是否已被访问
int result[MAX];
int n, e, ans, k = 0;                // 顶点数n, 边数e, 当前访问的节点ans, 搜索种类k

void DFS (int x) {          // 深度搜索
    result[ans++] = x;
    visited[x] = true;
    for(int i = 0; i < n; i++) {
        if(hashTable[x][i] == 1 && visited[i] == false) {       // 连通且为访问
            DFS(i);
        }
    }
}

void BFS(int x) {           // 广度搜索
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    result[ans++] = x;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 0; i < n; i++) {
            if(hashTable[now][i] == 1 && visited[i] == false) {
                visited[i] = 1;
                result[ans++] = i;
                q.push(i);
            }
        }
    }
}

void Print() {
    cout<<"{ ";
    for(int i = 0; i < ans; i++) {
        cout<<result[i]<<" ";
    }
    cout<<"}"<<endl;
}

void fun1() {           // 遍历
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++) {
        ans = 0;                        // 重新初始化resut[] = { 0 }
        if(visited[i] == false) {       // 未被访问过
            if(k == 0) DFS(i);
            if(k == 1) BFS(i);
            Print();
        }
    }
}

int main()
{
    cin>>n>>e;
    for(int i = 0; i < e; i++) {
        int v1, v2;     // 顶点
        cin>>v1>>v2;
        hashTable[v1][v2] = 1;      // 无向图, 双向
        hashTable[v2][v1] = 1;
    }
    fun1();
    k = 1;
    fun1();
    return 0;
}
