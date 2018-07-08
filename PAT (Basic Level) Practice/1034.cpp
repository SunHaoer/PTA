#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long gcd(long long a,long long b) {        // �����Լ������
    if(b == 0) return a;
    else return gcd(b, a % b);
}

struct Fraction {                       // ����
    long long up, down;
} num[2];

Fraction Print(Fraction result) {       // �������
    if(result.down == 0) {              // ��ĸΪ0
        cout<<"Inf";
        return result;
    }
    long long d = gcd(abs(result.up), abs(result.down));       // dΪ���ӷ�ĸ�����Լ��,�������
    result.up = result.up / d;
    result.down = result.down / d;
    long long n = abs(result.up) / abs(result.down);           // ��������������
    long long m = (long long)(abs(result.up)) % (long long)(result.down);
    if(m == 0){                          // ��ĸ���Ա���������ʱ
        if( (result.up > 0 && result.down > 0) || (result.up < 0 && result.down < 0) || (result.up == 0)) {
            cout<<n;
        } else{
            cout<<'('<<'-'<<abs(n)<<')';
        }
    } else if( (result.up > 0 && result.down > 0) || (result.up < 0 && result.down < 0) || (result.up == 0)) {
        if(n > 0) {
            cout<<n<<' ';
            cout<<m<<'/'<<abs(result.down);
        } else {
            cout<<abs(result.up)<<'/'<<abs(result.down);
        }
    } else {
        cout<<'('<<'-';
        if(n>0){
            cout<<n<<' ';
            cout<<m<<'/'<<abs(result.down)<<')';
        } else{
            cout<<abs(result.up)<<'/'<<abs(result.down)<<')';
        }
    }
    return result;
}

Fraction add(Fraction a,Fraction b){               // �ӷ�����
    Fraction result;
    result.up = num[0].up * num[1].down + num[1].up * num[0].down;
    result.down = num[0].down * num[1].down;
    return Print(result);
}

Fraction sub(Fraction a,Fraction b){               // ��������
    Fraction result;
    result.up = num[0].up * num[1].down - num[1].up * num[0].down;
    result.down = num[0].down * num[1].down;
    return Print(result);
}

Fraction mul(Fraction a,Fraction b){               // �˷�����
    Fraction result;
    result.up = num[0].up * num[1].up;
    result.down = num[0].down * num[1].down;
    return Print(result);
}

Fraction div(Fraction a,Fraction b){                // ����
    Fraction result;
    result.up = num[0].up * num[1].down;
    result.down = num[0].down * num[1].up;
    return Print(result);
}

int main()
{
    scanf("%lld/%lld", &num[0].up, &num[0].down);           // ��scanf����longlong
    scanf("%lld/%lld", &num[1].up, &num[1].down);
    Print(num[0]);             // �ӷ�
    cout<<" + ";
    Print(num[1]);
    cout<<" = ";
    add(num[0], num[1]);
    cout<<endl;
    Print(num[0]);             // ����
    cout<<" - ";
    Print(num[1]);
    cout<<" = ";
    sub(num[0], num[1]);
    cout<<endl;
    Print(num[0]);             // �˷�
    cout<<" * ";
    Print(num[1]);
    cout<<" = ";
    mul(num[0], num[1]);
    cout<<endl;
    Print(num[0]);             // ����
    cout<<" / ";
    Print(num[1]);
    cout<<" = ";
    div(num[0], num[1]);
    cout<<endl;

    return 0;
}
