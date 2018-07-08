#include<iostream>
using namespace std;

string fun1(string str) {        // 反转
    string temp;
    for(int i = str.size() - 1; i >= 0; i--) {
        temp += str[i];
    }
    return temp;
}

bool fun2(string str) {          // 判断是否回文
    for(int i = 0; i <= str.size() / 2; i++) {
        if(str[i] != str[str.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

string fun3(string str1, string str2) {         // 相加
    string str3 = "";
    int carry = 0;
    while(str1.size() != str2.size()) {
        if(str1.size() < str2.size()) str1 = '0' + str1;
        if(str2.size() < str1.size()) str2 = '0' + str2;
    }
    for(int i = 0; i < str1.size(); i++) {
        int a = str1[i] - '0';
        int b = str2[i] - '0';
        char ch;
        if(a + b + carry >= 10) {                // 进位
            ch = (a + b + carry - 10) + '0';
            carry = 1;
        } else {
            ch = (a + b + carry ) + '0';
            carry = 0;
        }
        str3 = str3 + ch;
    }
    if(carry != 0) {
        str3 = str3 + '1';
    }
    str3 = fun1(str3);
    return str3;
}

int main()
{
    string str1, str2, str3;
    int ans = 0;
    cin>>str3;
    while(fun2(str3) != true && ans < 10) {
        str1 = str3;
        str2 = fun1(str1);
        str3 = fun3(str1, str2);
        cout<<str1<<" + "<<str2<<" = "<<str3<<endl;
        ans++;
    }
    if(ans != 10) {
        cout<<str3<<" is a palindromic number."<<endl;
    } else{
        cout<<"Not found in 10 iterations."<<endl;
    }
    return 0;
}
