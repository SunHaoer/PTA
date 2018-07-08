#include<iostream>
#include<cstdio>
using namespace std;

bool fun1(string str) {                     // Ì«¶Ì
    if(str.size() < 6) return false;
    else return true;
}

bool fun2(string str) {                     // Ì«ÂÒ
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || (ch == '.') ) {
            continue;
        }
        else return false;
    }
    return true;
}

int fun3(string str) {
    bool flag1 = false, flag2 = false;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ) {
            flag1 = true;
        }
        if( (ch >= '0' && ch <= '9') ) {
            flag2 = true;
        }
    }
    if(flag1 == false) {        // ²»´æÔÚ×ÖÄ¸
        return 2;
    }
    if(flag2 == false) {        // ²»´æÔÚÊý×Ö
        return 1;
    }
    return 3;
}

int main()
{
    int n;
    cin>>n;
    getchar();                  // ³Ô»Ø³µ!!!!
    for(int i = 0; i < n; i++) {
        string str;
        getline(cin, str);      // ÃÜÂë
        if(!fun1(str)) {
            cout<<"Your password is tai duan le."<<endl;
        } else if(!fun2(str)) {
            cout<<"Your password is tai luan le."<<endl;
        } else if(fun3(str) == 2) {
            cout<<"Your password needs zi mu."<<endl;
        } else if(fun3(str) == 1) {
            cout<<"Your password needs shu zi."<<endl;
        } else {
            cout<<"Your password is wan mei."<<endl;
        }
    }
    return 0;
}
