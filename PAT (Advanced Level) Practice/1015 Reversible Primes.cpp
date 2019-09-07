#include<iostream>
#include<cmath>
using namespace std;
int n, d;

bool isPrime(int n) {        // 判断是否素数
    if(n < 2) return false;         // 1不是素数
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {     // 非素数
            return false;
        }
    }
    return true;
}

int fun1(int n, int d) {       // 进制转换
    string str = "";
    int num = 0;
    while(n != 0) {
        str += (n % d + '0');
        n /= d;
    }
    while(str[0] == '0') {
        str.erase(str.begin() + 0);
    }
    int ans = 1;
    for(int i = str.size() - 1; i >= 0; i--) {
        num += (str[i] - '0') * ans;
        ans *= d;
    }
    return num;
}

int main()
{
    while(cin>>n) {
        if(n < 0) break;
        cin>>d;
        if(isPrime(n) == false) {
            cout<<"No"<<endl;
        } else {            // 求回文数
            n = fun1(n, d);
            if(isPrime(n) == false) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}
