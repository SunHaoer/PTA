#include<cstdio>
using namespace std;

int main()
{
    double sum = 0, num[100010];
    int n;
    scanf("%d", &n);                  // 输入总数
    for(int i = 0; i < n; i++) {          // 输入数列
        scanf("%lf", &num[i]);
    }
    for(int i = 0; i < n; i++) {
        sum = sum + num[i] * (n - i) * (i + 1);
    }
    printf("%.2f", sum);
    return 0;
}

/*
num[4] = {0.1, 0.2, 0.3, 0.4};
n[0] * 4
n[1] * 3 + n[1] * 3
n[2] * 2 + n[2] * 2 + n[2] * 2
n[3] * 1 + n[3] * 1 + n[3] * 1 + n[3] * 1
*/
