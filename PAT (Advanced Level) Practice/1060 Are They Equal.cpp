#include<iostream>
#include<cstring>
using namespace std;
int n;         //��Чλ��

string deal(string str, int& e){
    while(str.size()>0&&str[0]=='0'){
        str.erase(str.begin()+0);
    }
    if(str[0]=='.'){           //С��1
        str.erase(str.begin()+0);
        while(str.size()>0&&str[0]=='0'){
            str.erase(str.begin()+0);
            e--;
        }
    }
    else {
        if(str.find('.')!=string::npos){        //����С��
            e = str.find('.');
            str.erase(str.begin()+e);
        }
        else {            //������С��
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
    int e1 = 0, e2 = 0;           //e1,e2Ϊstr1,str2ָ��
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
