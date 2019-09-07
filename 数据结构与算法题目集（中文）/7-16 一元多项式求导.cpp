#include<iostream>
using namespace std;

int main()
{
    int a, b;
    bool flag = false;
    while(cin>>a>>b) {
        if(b == 0 && flag == false) cout<<"0 0"<<endl;
        if(b == 0) break;
        if(flag) cout<<" ";
        else flag = true;
        cout<<(a * b)<<" "<<(b - 1);
    }
    return 0;
}
