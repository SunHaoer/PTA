#include<cstdio>
#include<algorithm>
using namespace std;

int check(int n, int k) {                    // �ж��Ƿ��й�Լ��
    for(int i = 2; i <= n; i++) {
        if(k % i == 0 && n % i == 0) {       // ������
            return 0;
        }
    }
    return 1;
}

int main()
{
    double n1, m1, n2, m2, flag = 0;
    double num1, num2;         // n1/m1, n2/m2
    int k;
    scanf("%lf/%lf", &n1, &m1);
    scanf("%lf/%lf", &n2, &m2);
    scanf("%d", &k);
    num1 = n1 / m1 * k;
    num2 = n2 / m2 * k;
    if(num1 > num2) {          // ��num1<num2
        swap(num1, num2);
    }
    for(int i = (int)(num1 - 0.001) - 2; i <= (int)(num2 + 0.001) + 2; i++) {
        if(i <= num1 + 0.000000001 || i >= num2 - 0.00000001) {          // ̫���̫С
            continue;
        }
        if(check(i,k) == 1 && i != 0) {
            if(flag == 0) {            // �����һ����
                printf("%d/%d", i, k);
                flag = 1;
            } else{                    // ���
                printf(" %d/%d", i, k);
            }
        }
    }
    return 0;
}
