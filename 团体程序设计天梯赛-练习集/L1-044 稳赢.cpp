#include<iostream>
using namespace std;

int main()
{
    int n, ans = 0;
    cin>>n;
    while(true) {
        string str;
        cin>>str;
        if(str == "End") {
            break;
        } else if(ans == n) {
            cout<<str<<endl;
            ans = 0;
        } else {
            ans++;
            if(str == "ChuiZi") {
                cout<<"Bu"<<endl;
            } else if(str == "JianDao") {
                cout<<"ChuiZi"<<endl;
            } else {
                cout<<"JianDao"<<endl;
            }
        }

    }
    return 0;
}
