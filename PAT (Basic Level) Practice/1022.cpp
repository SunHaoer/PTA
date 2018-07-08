#include<iostream>
using namespace std;

int main()
{
    int a, b, c, d, ans = 0;
    int num[31];
    cin>>a>>b>>d;
    c = a + b;
    do{
        num[ans++] = c % d;
        c = c / d;
    } while(c!=0);
    for(int i = ans - 1; i >= 0; i--) {
        cout<<num[i];
    }
    return 0;
}
