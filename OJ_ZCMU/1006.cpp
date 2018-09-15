#include<iostream>
using namespace std;

int main()
{
    int repeat, n;
    cin>>repeat;
    for(int i=0; i<repeat; i++){
        cin>>n;
        if(n%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
