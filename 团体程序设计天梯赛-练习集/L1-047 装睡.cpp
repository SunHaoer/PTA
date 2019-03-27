#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        string str;
        int a, b;
        cin>>str>>a>>b;
        if(a < 15 || a > 20 || b < 50 || b > 70) cout<<str<<endl;
    }
    return 0;
}
