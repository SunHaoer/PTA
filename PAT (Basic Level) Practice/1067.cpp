#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    string password, str;
    int repeat;
    cin>>password>>repeat;
    getchar();
    while(true) {
        getline(cin, str);
        repeat--;
        if(repeat < 0) {
            cout<<"Account locked"<<endl;
            break;
        } else if(str == password) {
            cout<<"Welcome in"<<endl;
            break;
        } else{
            if(str == "#") break;
            cout<<"Wrong password: "<<str<<endl;
        }
    }
    return 0;
}
