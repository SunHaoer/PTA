#include<iostream>
#include<cctype>
using namespace std;

long long fun1(string str, long long radix) {        // 其他进制转10进制
    long long result = 0, ans = 1;
    for(int i = str.size() - 1; i >= 0; i--) {
        if(isdigit(str[i])) {
            result += (str[i] - '0') * ans;
        } else if(islower(str[i])) {
            result += (str[i] - 'a' + 10) * ans;
        }
        ans *= radix;
    }
    return result;
}

int fun2(string str) {          // 找最大值
    int result = -1;
    for(int i = 0; i < str.size(); i++) {
        if(isdigit(str[i])) {
            result = max(result, str[i] - '0');
        } else if(islower(str[i])) {
            result = max(result, str[i] - 'a' + 10);
        }
    }
    return result;
}

long long fun3(string str, long long num, long long left, long long right) {
    bool isfind = false;
    long long temp = 0;
    long long mid = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        temp = fun1(str, mid);
        if(temp < 0 || temp > num) {
            right = mid - 1;
        } else if(temp < num) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main()
{
    string str1, str2;
    long long num, tag, radix, m, result, right;
    cin>>str1>>str2>>tag>>radix;
    if(tag == 1) {
        num = fun1(str1, radix);
        m = fun2(str2);
        result = fun3(str2, num, m + 1, max(num, m + 1));
    } else {
        num = fun1(str2, radix);
        m = fun2(str1);
        result = fun3(str1, num, m + 1, max(num, m + 1));
    }
    if(result != -1) cout<<result<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}


/*
 * 进制可能会超过36
 * 测试点0: 6 110 2 2
 * 测试点7: 容易运行超时, 需要二分法
 * 测试点2, 14, 17, 18, 19: Imposible(7分)
 */
