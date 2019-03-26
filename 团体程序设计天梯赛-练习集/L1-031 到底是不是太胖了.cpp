#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        float a, b, c;
        scanf("%f %f", &a, &b);
        c = (a - 100) * 0.9 * 2;
        //cout<<c<<endl;
        if(abs(b - c) < c * 0.1 - 0.0001) {
            printf("You are wan mei!\n");
            //cout<<abs(b - c) - c * 0.1<<endl;
        } else if(b > c) {
            //cout<<b<<">"<<c<<endl;
            cout<<"You are tai pang le!"<<endl;
        } else {
            cout<<"You are tai shou le!"<<endl;
        }
    }
    return 0;
}
