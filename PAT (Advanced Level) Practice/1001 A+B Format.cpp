#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    int a, b, c;
    string str;
    cin>>a>>b;
    c = a + b;
    stringstream stream;
    stream<<c;
    stream>>str;
    int len = str.size();
    for(int i=0; i<str.size(); i++){
        cout<<str[i];
        if(str[i]=='-') continue;
        if((i+1)%3==(len%3)&&i!=len-1){
            cout<<',';
        }
    }
    return 0;
}
