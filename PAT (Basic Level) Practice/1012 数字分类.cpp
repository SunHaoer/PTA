#include<cstdio>
using namespace std;
int A0 = 0, A1 = 0, A2 = 0, A3 = 0, A4 = 0;
int flag = 1, a1 = 0, a3 = 0;

void fun0(int n) {
    if(n % 2 == 0) A0 += n;
    return;
}

void fun1(int n) {
    A1 += (n * flag);
    flag = -flag;
    a1++;
    return;
}

void fun2(int n) {
    A2++;
    return;
}

void fun3(int n) {
    A3 += n;
    a3++;
    return;
}

void fun4(int n) {
    if(n > A4) A4 = n;
    return;
}

int main()
{
    int repeat;
    //cin>>repeat;
    scanf("%d", &repeat);
    for(int i = 0; i < repeat; i++) {
        int num;
        //cin>>num;
        scanf("%d", &num);
        switch(num % 5) {
            case 0: fun0(num); break;
            case 1: fun1(num); break;
            case 2: fun2(num); break;
            case 3: fun3(num); break;
            case 4: fun4(num); break;
        }
    }
    if(A0 != 0) printf("%d ", A0);
    else printf("N ");
    if(a1 != 0) printf("%d ", A1);
    else printf("N ");
    if(A2 != 0) printf("%d ", A2);
    else printf("N ");
    if(A3 != 0) printf("%.1f ",(A3 * 1.0 / a3 * 1.0));
    else printf("N ");
    if(A4 != 0) printf("%d", A4);
    else printf("N");
    return 0;
}
