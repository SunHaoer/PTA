#include<iostream>
#include<sstream>
using namespace std;
string change[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
    string str1, str2;
    int num = 0;
    cin>>str1;
    for(int i=0; i<str1.size(); i++){
        num += (str1[i]-'0');
    }
    stringstream stream;
    stream<<num;
    stream>>str2;
    for(int i=0; i<str2.size(); i++){
        if(i!=0) cout<<' ';
        cout<<change[str2[i]-'0'];
    }
    return 0;
}
