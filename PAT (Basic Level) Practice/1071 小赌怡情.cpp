#include<iostream>
using namespace std;

int main()
{
    int tol, k;         // 筹码数tol, 玩的次数k
    cin>>tol>>k;
    int n1, b, t, n2;
    for(int i = 0; i < k; i++) {
        cin>>n1>>b>>t>>n2;
        if(tol >= t) {
            if( (n1 > n2 && b == 0) || (n1 < n2 && b == 1) ) {               // 赢
                tol = tol + t;
                cout<<"Win "<<t<<"!  Total = "<<tol<<"."<<endl;
            } else if( (n1 > n2 && b == 1) || (n1 < n2 && b == 0) ) {        // 输
                tol = tol - t;
                cout<<"Lose "<<t<<".  Total = "<<tol<<"."<<endl;
            }
            if(tol <= 0) {
                cout<<"Game Over."<<endl;
                break;
            }
        } else {
            cout<<"Not enough tokens.  Total = "<<tol<<"."<<endl;
        }
    }
    return 0;
}
