#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX = 10010;
int table[MAX][MAX], num[MAX];

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int cnt;      // 总人数n
    scanf("%d", &cnt);
    for(int i = 0; i < cnt; i++) {
        scanf("%d", &num[i]);
    }
    if(cnt == 1) {
        printf("%d", num[0]);
    } else {
        sort(num, num + cnt, cmp);
        int m = (int)ceil(sqrt(cnt * 1.0));
        while(cnt % m != 0) {     // m尽可能大
            m++;
        }
        int n = cnt / m, i = 1, j = 1, now = 0;
        int u = 1, d = m, l = 1, r = n;     // 4个边界
        while(now < cnt) {
            while(now < cnt && j < r) {
                table[i][j] = num[now++];
                j++;
            }
            while(now < cnt && i < d) {

                table[i][j] = num[now++];
                i++;
            }
            while(now < cnt && j > l) {
                table[i][j] = num[now++];
                j--;
            }
            while(now < cnt && i > u) {
                table[i][j] = num[now++];
                i--;
            }
            u++, d--, l++, r--;     // 缩小边界
            i++, j++;           // 位移至内层左上角
            if(now == cnt - 1) {
                table[i][j] = num[now++];
            }
        }
        for(int i = 1; i <= m; i++) {       // 输出
            for(int j = 1; j <= n; j++) {
                printf("%d", table[i][j]);
                if(j < n) printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}
