#include<iostream>
#include<cstring>
using namespace std;
int n;         //有效位数

string deal(string str, int& e){
    while(str.size()>0&&str[0]=='0'){
        str.erase(str.begin()+0);
    }
    if(str[0]=='.'){           //小于1
        str.erase(str.begin()+0);
        while(str.size()>0&&str[0]=='0'){
            str.erase(str.begin()+0);
            e--;
        }
    }
    else {
        if(str.find('.')!=string::npos){        //存在小数
            e = str.find('.');
            str.erase(str.begin()+e);
        }
        else {            //不存在小数
            e = str.size();
        }
    }
    if(str.size()==0){
        e = 0;
    }
    while(str.size()<n){
        str = str + '0';
    }
    str = str.substr(0, n);
    return str;
}

int main()
{
    string str1, str2, str3, str4;
    cin>>n>>str1>>str2;
    int e1 = 0, e2 = 0;           //e1,e2为str1,str2指数
    str3 = deal(str1, e1);
    str4 = deal(str2, e2);
    if(str3==str4&&e1==e2){
        cout<<"YES 0."<<str3<<"*10^"<<e1<<endl;
    }
    else {
        cout<<"NO 0."<<str3<<"*10^"<<e1<<" 0."<<str4<<"*10^"<<e2<<endl;
    }
    return 0;
}
