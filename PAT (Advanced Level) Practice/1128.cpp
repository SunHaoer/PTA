#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 1010;
bool num[MAX], table[MAX][MAX];
int k, n, index, dir;

void DFS(int a, int b, int dir) {       // 深度搜索, 把不满足条件的坐标设置为true
    if(a == 0 || a == n + 1 || b == 0 || b == n + 1) return;
    if(table[a][b]) return;
    table[a][b] = true;
    if(dir == 0 || dir == 1) DFS(a + 1, b + 1, 1);
    if(dir == 0 || dir == 2) DFS(a - 1, b - 1, 2);
    if(dir == 0 || dir == 3) DFS(a - 1, b + 1, 3);
    if(dir == 0 || dir == 4) DFS(a - 1, b + 1, 4);
}

int main()
{

    scanf("%d", &k);
    for(int i = 0; i < k; i++) {        // 输入
        fill(table[0], table[0] + MAX * MAX, false);
        fill(num, num + MAX, false);
        int flag = true;
        scanf("%d", &n);
        for(int j = 1; j <= n; j++) {   // 输入每组数据
            scanf("%d", &index);
            if(num[index]) flag = false;        // 横排不满足条件
            else num[index] = true;
            if(!table[j][index] && flag) DFS(j, index, 0);
            else flag = false;                  // 斜排不满足条件
        }
        if(flag) printf("YES\n");       // 输出
        else printf("NO\n");
    }
    return 0;
}
