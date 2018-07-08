#include<iostream>
#include<sstream>
using namespace std;

int fun1(string str, char ch) {
    string temp = "";
    int num = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ch) temp += ch;
    }
    stringstream stream;        // stringתint
    stream<<temp;
    stream>>num;
    return num;
}

int main()
{
    string str1, str2;
    char ch1, ch2;
    cin>>str1>>ch1>>str2>>ch2;
    int a = fun1(str1, ch1);
    int b = fun1(str2, ch2);
    cout<<a + b<<endl;
    return 0;
}
