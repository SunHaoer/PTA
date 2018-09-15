#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int repeat;
    cin>>repeat;
    for ( int i=0; i<repeat; i++ ) {
        int n = 0, ans = 0;
        cin>>n;
        for( int j=0; j<n; j++ ) {
            double temp, m, price;
            cin>>temp>>m;
            price = temp * m * 10;
            ans += (int)(round(price));
        }
        cout<<ans/10<<'.'<<ans%10<<endl;
    }
    return 0;
}
