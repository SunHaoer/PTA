#include<cstdio>
using namespace std;
const int MAX = 1010;
bool table[MAX][MAX];

int visitedNum = 0;
bool visited[MAX];
void DFS(int v, int n) {        // 深度搜索, 判断是否连通
    visitedNum++;               // 访问的节点数
    visited[v] = true;
    for(int i = 1; i <= n; i++) {
        if(!visited[i] && table[v][i]) {
            DFS(i, n);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {    // 输入图
        int a, b;
        scanf("%d %d", &a, &b);
        table[a][b] = table[b][a] = true;
    }
    int ans = 0, oddNum = 0;
    for(int i = 1; i <= n; i++) {   // 统计
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(table[i][j]) cnt++;
        }
        printf("%d", cnt);
        if(cnt % 2 != 0) oddNum++;      // 统计奇数个数
        if(i != n) printf(" ");
        else printf("\n");
    }
    DFS(1, n);
    if(visitedNum != n) oddNum = 3;     // 不是连通图
    if(oddNum == 0) printf("Eulerian\n");
    else if(oddNum == 2) printf("Semi-Eulerian\n");
    else printf("Non-Eulerian\n");
    return 0;
}
