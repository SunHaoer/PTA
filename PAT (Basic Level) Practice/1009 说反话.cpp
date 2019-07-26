#include<iostream>
using namespace std;
const int MAX = 80;

int main()
{
    string str[MAX];
    int ans = 0;
    while(cin>>str[ans]) {
        ans++;
    }
    for(int i = ans - 1; i >= 0; i--) {
        cout<<str[i];
        if(i != 0) cout<<" ";
    }
    cout<<endl;
    return 0;
}
