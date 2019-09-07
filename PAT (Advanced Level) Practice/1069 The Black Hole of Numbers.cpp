#include<iostream>
#include<sstream>
#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp1(char a, char b){
    return a > b;
}

bool cmp2(char a, char b){
    return a < b;
}

int fun1(string str){
    int num;
    stringstream stream;
    stream<<str;
    stream>>num;
    return num;
}

string fun2(int num){
    string str;
    stringstream stream;
    stream<<num;
    stream>>str;
    return str;
}

string fun3(string str){
    while(str.size()<4){
        str = '0' + str;
    }
    return str;
}

int main()
{
    string str;
    cin>>str;
    bool flag = false;
    while(str!="6174"||flag==false){
        flag = true;
        str = fun3(str);
        sort(str.begin(), str.end(), cmp1);
        string str1 = str;
        sort(str.begin(), str.end(), cmp2);
        string str2 = str;
        int num1 = fun1(str1);
        int num2 = fun1(str2);
        int num3 = num1 - num2;
        str = fun2(num3);
        printf("%04d - %04d = %04d\n", num1, num2, num3);
        if(num3==0) break;
    }
    return 0;
}
