#include<iostream>
using namespace std;

int main()
{
    int a, b;
    while(cin>>a>>b){
        if(b == 0){
           cout<<"0"<<" "<<"0";
           return 0;
        }
        cout<<a * b<< " "<<b - 1;
        break;
    }
    while(cin>>a>>b){
        if(b == 0) break;
        cout<<" "<<a * b<<" "<<b - 1;
    }
    cout<<endl;
    return 0;
}
