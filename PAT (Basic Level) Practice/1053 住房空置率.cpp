#include<cstdio>
using namespace std;

int main()
{
    double n, num, flag;         // ס��n, ��ֵnum, �ƶ�����flag
    double a = 0, b = 0;         // ����Ϊ��a, һ��Ϊ��b
    scanf("%lf%lf%lf", &n, &num, &flag);
    for(int i = 0; i < n; i++) {
        double day, ans = 0;     // ��¼���ڷ�ֵ����ans
        scanf("%lf", &day);      // �����¼����
        for(int j = 0; j < day; j++) {
            double e;
            scanf("%lf", &e);
            if(e < num) ans++;        // ������ڷ�ֵ
        }
        if(ans > day / 2.0) {
            if(day > flag) b++;       // һ��Ϊ��
            else a++;                 // ����Ϊ��
        }
    }
    printf("%.1f%% %.1f%%\n", (a * 100.0) / n, (b * 100.0) / n);
    return 0;
}
