#include<cstdio>
using namespace std;
const int MAX = 501;

int main()
{
    int page[MAX][MAX];         // 画布
    int a, b, m, n, c;
    scanf("%d%d", &m, &n);      // page[m][n]
    scanf("%d%d", &a, &b);      // 需填充的颜色
    scanf("%d", &c);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &page[i][j]);
            if(page[i][j] >= a && page[i][j] <= b) {        // 要被过滤
                page[i][j] = c;
            }
        }
    }
    for(int i = 0; i < m; i++) {                // 输出
        for(int j = 0; j < n; j++) {
            if(j != 0) printf(" ");
            printf("%03d",page[i][j]);
        }
        printf("\n");
    }
    return 0;
}
