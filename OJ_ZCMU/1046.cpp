#include<iostream>
using namespace std;

int main()
{
    int a, b;
    while( cin>>a>>b ) {
        int ans = 0;
        for( int i=0; i<6; i++ ) {
            if ( a!=0 && b!=0 ) {
                ans += ( ( a - 1 ) * 20 + b );
            }
            if ( i!=5 ) {
                cin>>a>>b;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
