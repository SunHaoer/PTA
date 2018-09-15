#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n){
        if(n==0) break;
        int s = 0, a = 0;
        for(int i=0; i<n; i++){
            cin>>a;
            s += ( a * a );
        }
        cout<<s<<endl;
    }
    return 0;
}
