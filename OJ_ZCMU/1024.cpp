#include<iostream>
using namespace std;
const double PI = 3.1415;

int main()
{
    int repeat;
    cin>>repeat;
    for ( int i=0; i<repeat; i++ ) {
        double a, b, c, d;
        double s1, s2, s3;
        cin>>a>>b>>c>>d;
        s1 = a * a;
        s2 = b * c;
        s3 = PI * d * d;
        if ( s1>s2 && s1>s3 ) {
            cout<<"Square"<<endl;
        }
        else if( s2>s1 && s2>s3 ) {
            cout<<"Rectangle"<<endl;
        }
        else {
            cout<<"Circle"<<endl;
        }
    }
    return 0;
}

