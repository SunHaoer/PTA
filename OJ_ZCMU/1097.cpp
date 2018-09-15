#include<iostream>
using namespace std;

int main()
{
    string n;
    int k;
    while(cin>>n>>k){
        int num = 0, temp = 0;
        for(int i=0; i<=n.size()-1; i++) {
            num = ( n[i] - '0' ) + temp * 10;
            temp = num % k;
        }
        cout<<temp<<endl;
    }
    return 0;
}

