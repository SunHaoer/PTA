#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    char ch;
    string str;
    cin>>n>>ch;
    getchar();
    getline(cin, str);
    int len = str.length();
    if(n == len) {
        cout<<str<<endl;
    } else if(n < len) {
        cout<<str.substr(len - n, len)<<endl;
    } else {
        for(int i = 0; i < n - len; i++) {
            cout<<ch;
        }
        cout<<str<<endl;
    }
    return 0;
}
