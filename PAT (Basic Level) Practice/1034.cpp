#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long gcd(long long a,long long b) {        // 求最大公约数函数
    if(b == 0) return a;
    else return gcd(b, a % b);
}

struct Fraction {                       // 分数
    long long up, down;
} num[2];

Fraction Print(Fraction result) {       // 输出函数
    if(result.down == 0) {              // 分母为0
        cout<<"Inf";
        return result;
    }
    long long d = gcd(abs(result.up), abs(result.down));       // d为分子分母的最大公约数,化简分数
    result.up = result.up / d;
    result.down = result.down / d;
    long long n = abs(result.up) / abs(result.down);           // 分数的整数部分
    long long m = (long long)(abs(result.up)) % (long long)(result.down);
    if(m == 0){                          // 分母可以被分子整除时
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

Fraction add(Fraction a,Fraction b){               // 加法函数
    Fraction result;
    result.up = num[0].up * num[1].down + num[1].up * num[0].down;
    result.down = num[0].down * num[1].down;
    return Print(result);
}

Fraction sub(Fraction a,Fraction b){               // 减法函数
    Fraction result;
    result.up = num[0].up * num[1].down - num[1].up * num[0].down;
    result.down = num[0].down * num[1].down;
    return Print(result);
}

Fraction mul(Fraction a,Fraction b){               // 乘法函数
    Fraction result;
    result.up = num[0].up * num[1].up;
    result.down = num[0].down * num[1].down;
    return Print(result);
}

Fraction div(Fraction a,Fraction b){                // 除法
    Fraction result;
    result.up = num[0].up * num[1].down;
    result.down = num[0].down * num[1].up;
    return Print(result);
}

int main()
{
    scanf("%lld/%lld", &num[0].up, &num[0].down);           // 用scanf输入longlong
    scanf("%lld/%lld", &num[1].up, &num[1].down);
    Print(num[0]);             // 加法
    cout<<" + ";
    Print(num[1]);
    cout<<" = ";
    add(num[0], num[1]);
    cout<<endl;
    Print(num[0]);             // 减法
    cout<<" - ";
    Print(num[1]);
    cout<<" = ";
    sub(num[0], num[1]);
    cout<<endl;
    Print(num[0]);             // 乘法
    cout<<" * ";
    Print(num[1]);
    cout<<" = ";
    mul(num[0], num[1]);
    cout<<endl;
    Print(num[0]);             // 除法
    cout<<" / ";
    Print(num[1]);
    cout<<" = ";
    div(num[0], num[1]);
    cout<<endl;

    return 0;
}
