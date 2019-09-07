#include<cstdio>
#include<cmath>
using namespace std;
const int MAX = 100010;

int main()
{
    int n;
    double sum = 0, num[MAX];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {        // 输入
        scanf("%lf", &num[i]);
    }
    for(int i = 0; i < n; i++) {        // 计算
        sum += (num[i] * (n - i) * (i + 1));
    }
    printf("%.2f\n", sum);
    return 0;
}
