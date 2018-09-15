#include<iostream>
using namespace std;

void fun(string str){
    int ans = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i]>='0'&&str[i]<='9'){
            cout<<str[i];
            if(i==str.size()-1) cout<<endl;
            else cout<<' ';
        }
    }
    return;
}

int main()
{
    int repeat;
    cin>>repeat;
    while(repeat--){
        string str;
        cin>>str;
        fun(str);
    }
    return 0;
}
