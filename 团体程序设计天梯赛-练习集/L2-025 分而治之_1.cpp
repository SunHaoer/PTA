#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 10010;
bool table[MAX][MAX];
bool losted[MAX];
int arr[MAX];
int n, m;

bool fun1() {
    for(int i = 1; i <= n; i++) {
        if(losted[i]) break;
        for(int j = 1; j <= n; j++) {
            if(!losted[j] && table[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    fill(table[0], table[0] + MAX * MAX, false);
    scanf("%d %d", &n, &m);
    int a, b;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        table[a][b] = table[b][a] = true;
    }
    int repeat, tempNode;
    scanf("%d", &repeat);
    for(int i = 0; i < repeat; i++) {
        scanf("%d", &m);
        fill(losted, losted + MAX, false);
        for(int j = 0; j < m; j++) {
            scanf("%d", &tempNode);
            losted[tempNode] = true;
        }
        if(fun1()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

/*
 * 邻接矩阵内存超限
 */




