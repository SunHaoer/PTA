#include<cstdio>
#include<iostream>
using namespace std;
const int MAX = 1010;
bool table[MAX][MAX], visited[MAX];

void init() {           // 初始化
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(i == j) table[i][j] = true;
            else table[i][j] = false;
        }
    }
}

void fun1(int n) {          // 输入cycle并判断
    bool visited[n + 1];
    for(int i = 1; i < n + 1; i++) {
        visited[i] = true;
    }
    int k, cycle[MAX];
    bool flag = true;
    scanf("%d %d", &k, &cycle[0]);
    if(n + 1!= k) {        // 节点数不对 || 起点不是节点
        flag = false;
    }
    visited[cycle[0]] = false;
    for(int i = 1; i < k - 1; i++) {        // 输入
        scanf("%d", &cycle[i]);
        if(!visited[cycle[i]] || !table[cycle[i - 1]][cycle[i]]) {      // 这个节点因被访问 || 这条路不同
            flag = false;
        }
        visited[cycle[i]] = false;
    }
    scanf("%d", &cycle[k - 1]);
    if(cycle[0] != cycle[k - 1] || (k > 1 && !table[cycle[k - 2]][cycle[k - 1]])) {     // 最后一个节点不是第一个节点 || 最后一条路没有连通
        flag = false;
    }
    if(flag) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main()
{
    init();
    int n, m, k;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {    // 输入路径
        int a, b;
        scanf("%d %d", &a, &b);
        table[a][b] = table[b][a] = true;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {    // 输入cycle
        fun1(n);
    }
    return 0;
}
