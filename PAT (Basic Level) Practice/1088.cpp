#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
double A, B, C;     // 甲乙丙
int a = -1, b = -1;
double m, x, y;

void fun1() {
    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(abs(i * 10 + j - j * 10 - i) * 1.0 / (x * 1.0) == (j * 10 + i) * 1.0 / (y * 1.0)) {
                a = i;
                b = j;
            }
        }
    }
}

void fun2(double n) {
    if(m < n) printf("Cong");
    else if(m == n) printf("Ping");
    else if(m > n) printf("Gai");
}

int main()
{
    scanf("%lf %lf %lf", &m, &x, &y);
    fun1();
    if(a == -1 && b == -1) {
        printf("No Solution\n");
    } else {
        A = a * 10 + b;
        B = b * 10 + a;
        C = B * 1.0 / (y * 1.0);
        printf("%.f ", A);
        fun2(A);
        printf(" ");
        fun2(B);
        printf(" ");
        fun2(C);
        printf("\n");
    }
    return 0;
}
