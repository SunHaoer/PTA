#include<iostream>
#include<algorithm>
using namespace std;

bool judge(string str) {        // 判断是否回文
    for(int i = 0; i < str.size() / 2; i++) {
        if(str[i] != str[str.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

string add(string str1, string str2) {      // 字符串相加
    string str = "";
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < str1. size(); i++) {
        a = str1[i] - '0';
        b = str2[i] - '0';
        int temp = (a + b + c) % 10;
        str += char(temp + '0');
        if(a + b + c >= 10) c = 1;
        else c = 0;
    }
    if(c != 0) str += char(c + '0');
    reverse(str.begin(), str.end());
    return str;
}

void fun1(string str1, string str2) {       // 短的字符串前面加0
    while(str1.size() < str2.size()) {
        str1 = '0' + str1;
    }
}

int main()
{
    string str, str1, str2;
    cin>>str;      // 输入字符串
    str1 = str2 = str;
    reverse(str2.begin(), str2.end());
    int repeat = 0;
    bool notFound = false;
    while(!judge(str)) {        // 循环相加
        repeat++;
        str = add(str1, str2);
        cout<<str1<<" + "<<str2<<" = "<<str<<endl;
        if(repeat == 10) {      // 不存在回文
            notFound = true;
            break;
        }
        fun1(str1, str2);
        fun1(str2, str1);
        str1 = str2 = str;
        reverse(str2.begin(), str2.end());
    }
    if(notFound) cout<<"Not found in 10 iterations."<<endl;
    else cout<<str1<<" is a palindromic number."<<endl;
    return 0;
}
