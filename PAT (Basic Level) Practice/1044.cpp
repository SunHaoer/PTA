#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
string a[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string b[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
int num = 0;

string to_tret(string str) {             // 地球转火星
    num = 0;
    for(int i = 0; i < str.size(); i++) {
        str[i] = str[i] - '0';
        num = num + str[i] * (pow(10, str.size() - i - 1) + 0.1);
    }
    if(num >= 13) {
        cout<<b[num / 13];
        if(num % 13 == 0) {               // 整高位数
            cout<<endl;
            return str;
        }
        cout<<' ';
    }
    cout<<a[num % 13]<<endl;
    return str;
}

int trans1(string str) {                   // 高位的转换
    num = 0;
    for(int i = 0; i < 13; i++) {
        if(str == b[i]) {
            num = num + i * 13;
        }
    }
    return num;
}

int trans2(string str) {                    // 低位的转换
    for(int i = 0; i < 13; i++) {
        if(str == a[i]) {
            num = num + i;
        }
    }
    return num;
}

string to_earth(string str) {                // 火星转地球
    string str0;
    if(str.size() > 5) {                     // 两个单词的
        for(int i = 0; i < 3; i++) {         // 取前三位
            str0 = str0 + str[i];
        }
        num = trans1(str0);
        str0 = "";
        for(int i = 4; i < 7; i++) {         // 取后三位
            str0 = str0 + str[i];
        }
        num = trans2(str0);
    } else {                                 // 一个单词
        num = trans1(str);
        num = trans2(str);
    }
    cout<<num<<endl;
    return str;
}

string check(string str) {
    if(str[0] >= '0' && str[0] <= '9') {           // 地球数字
        return to_tret(str);
    } else{
        return to_earth(str);
    }
}

int main()
{
    int repeat;
    cin>>repeat;
    getchar();
    for(int i = 0; i < repeat; i++) {
        string str;
        getline(cin, str);
        check(str);
    }
    return 0;
}
