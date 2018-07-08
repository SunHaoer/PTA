#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100010;
int num[10100][1010] = {0};
int temp[MAX];
int N, n, m;

bool cmp(int a, int b) {
    return a > b;
}

void print() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n - 1; j++) {
            printf("%d ", num[i][j]);
        }
        printf("%d\n", num[i][n - 1]);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &temp[i]);
    }
    sort(temp, temp + N, cmp);

    for(int i = N; i > 0; i--) {        // 计算符合意义的m, n
        for(int j = 1; j <= i; j++) {
            if(i * j == N) {
                m = i;
                n = j;
                break;
            }
        }
    }
    int ans = 0, k = 0;         // 第ans次循环
    while(true) {               // m行, n列的矩阵
        for(int i = ans; i < n - ans; i++) {            // 左->右
            num[ans][i] = temp[k++];
        }
        if(k == N) break;
        for(int i = ans + 1; i < m - ans; i++) {        // 上->下
            num[i][n - ans - 1] = temp[k++];
        }
        if(k == N) break;
        for(int i = n - ans - 2; i >= ans; i--) {       // 右->左
            num[m - ans - 1][i] = temp[k++];
        }
        if(k == N) break;
        for(int i = m - ans - 2; i > ans; i--) {        // 下->上
            num[i][ans] = temp[k++];
        }
        if(k == N) break;
        ans++;
    }
    print();
    return 0;
}
