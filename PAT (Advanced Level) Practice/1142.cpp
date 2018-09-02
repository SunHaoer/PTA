#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 550;
bool table[MAX][MAX];
int n;

int fun1(int m) {
    int v[MAX];
    bool isVisited[MAX];
    fill(isVisited, isVisited + MAX, false);
    for(int i = 0; i < m; i++) {        // 输入
        scanf("%d", &v[i]);
        isVisited[v[i]] = true;
    }
    for(int i = 0; i < m; i++) {        // Not a Clique
        for(int j = 0; j < i; j++) {
            if(!table[v[i]][v[j]]) {
                return 1;
            }
        }
    }
    for(int i = 0; i < m; i++) {        // Not Maximal
        for(int j = 1; j <= n; j++) {
            if(table[v[i]][j] && !isVisited[j]) {    // 查询数组中的一个顶点v[i], 在图中但不在查询数组中的顶点j
                bool flag = true;
                for(int k = 0; k < m; k++) {
                    if(!table[j][v[k]]) {       // 查询数组中的顶点v[k]
                        flag = false;           // j能和v[i]连通, 但不能喝v[k]连通
                        break;
                    }
                }
                if(flag) return 2;
            }
        }

    }
    return 3;       // Yes
}

int main()
{
    int m, k;    // n个顶点, m条边
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {    // 建图
        int a, b;
        scanf("%d %d", &a, &b);
        table[a][b] = table[b][a] = true;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &m);
        int flag = fun1(m);
        if(flag == 1) printf("Not a Clique\n");
        else if(flag == 2) printf("Not Maximal\n");
        else printf("Yes\n");
    }
    return 0;
}
