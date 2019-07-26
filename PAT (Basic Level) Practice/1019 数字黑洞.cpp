#include<iostream>
#include<cstdio>
#include<algorithm>
#include<sstream>
using namespace std;

bool cmp1(char a, char b) {
    return a > b;
}

bool cmp2(char a, char b) {
    return a < b;
}

int fun1(string str, int n) {               // ¸østrÅÅÐò²¢·µ»Øint
    int num = 0;
    if(n == 1) sort(str.begin(), str.end(), cmp1);
    if(n == 2) sort(str.begin(), str.end(), cmp2);
    for(int i = 0; i < str.size(); i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

int main()
{
    string str;
    cin>>str;
    if(str == "6174"){
        printf("7641 - 1467 = 6174\n");
    }
    while(str != "6174"){
        while(str.size() < 4){
            str = '0' + str;
        }
        int a = fun1(str, 1);
        int b = fun1(str, 2);
        int c = a - b;
        printf("%04d - %04d = %04d\n", a, b, c);
        if(c == 0) return 0;
        stringstream stream;
        stream<<c;
        stream>>str;
    }
    return 0;
}
