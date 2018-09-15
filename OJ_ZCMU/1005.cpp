#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, m, k;
    while(cin>>n>>m>>k){
        int a = n / k;
        if(n%k!=0) a++;
        int b = m / k;
        if(m%k!=0) b++;
        //cout<<a<<' '<<b<<endl;
        cout<<a*b<<endl;
    }
    return 0;
}
