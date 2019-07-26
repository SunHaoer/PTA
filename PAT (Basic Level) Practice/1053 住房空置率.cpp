#include<cstdio>
using namespace std;

int main()
{
    double n, num, flag;         // 住户n, 阀值num, 制定天数flag
    double a = 0, b = 0;         // 可能为空a, 一定为空b
    scanf("%lf%lf%lf", &n, &num, &flag);
    for(int i = 0; i < n; i++) {
        double day, ans = 0;     // 记录低于阀值天数ans
        scanf("%lf", &day);      // 输入记录天数
        for(int j = 0; j < day; j++) {
            double e;
            scanf("%lf", &e);
            if(e < num) ans++;        // 这天低于阀值
        }
        if(ans > day / 2.0) {
            if(day > flag) b++;       // 一定为空
            else a++;                 // 可能为空
        }
    }
    printf("%.1f%% %.1f%%\n", (a * 100.0) / n, (b * 100.0) / n);
    return 0;
}
