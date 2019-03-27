#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    char ch;
    double m;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>ch>>m;
        if(ch == 'M') printf("%.2f\n", m / 1.09);
        if(ch == 'F') printf("%.2f\n", m * 1.09);
    }
    return 0;
}
