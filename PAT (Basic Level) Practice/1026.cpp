#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int C1, C2;
    int time;
    scanf("%d%d", &C1, &C2);
    time = round( (C2 - C1) / 100.0 );      // round四舍五入
    int h = 0, m = 0, s = 0;                // 小时, 分钟, 秒
    s = time % 60;
    time /= 60;
    m = time % 60;
    time /= 60;
    h = time;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}

