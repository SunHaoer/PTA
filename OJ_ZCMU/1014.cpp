#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long a, b;
    cin>>a>>b;
    while ((a != 0) && (b != 0)) {
        long temp = 1;
        if (a > b) { // 交换使 a < b
            swap(a, b);
        }
        for (long i = a; i >= 1; i--) { // 找最大公约数
            if ((a % i == 0) && (b % i == 0)) {
                temp = i;
                break;
            }
        }
        cout<<(a * b / temp)<<endl; // 两数相乘再除最大公约数
        cin>>a>>b;
    }
}



