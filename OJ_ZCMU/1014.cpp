#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long a, b;
    cin>>a>>b;
    while ((a != 0) && (b != 0)) {
        long temp = 1;
        if (a > b) { // ����ʹ a < b
            swap(a, b);
        }
        for (long i = a; i >= 1; i--) { // �����Լ��
            if ((a % i == 0) && (b % i == 0)) {
                temp = i;
                break;
            }
        }
        cout<<(a * b / temp)<<endl; // ��������ٳ����Լ��
        cin>>a>>b;
    }
}



