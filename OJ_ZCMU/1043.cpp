#include<iostream>
using namespace std;

int main()
{
    string str;
    int n;
    while(cin>>str>>n) {
        int temp = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '.') {
                temp = i;
                break;
            }
        }
        if(temp + n < str.size()) {
            cout<<str[temp + n]<<endl;
        } else {
            cout<<"0"<<endl;
        }
    }
}
