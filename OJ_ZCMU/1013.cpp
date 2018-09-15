#include<iostream>
using namespace std;

int main()
{
    int a, b;
    while(cin>>a>>b){
        if(a==0&&b==0) break;
        int temp = 1;
        if(a>b) swap(a, b);
        for(int i=a; i>=1; i--){
            if(a%i==0&&b%i==0){
                temp = i;
                break;
            }
        }
        cout<<temp<<endl;
    }
    return 0;
}
