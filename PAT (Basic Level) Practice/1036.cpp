#include<iostream>
#include<cmath>
using namespace std;

void fun1(char ch, int n) {
    for(int i = 0; i < n; i++) {
        cout<<ch;
    }
    cout<<endl;
    return;
}

void fun2(char ch, int n) {
    for(int i = 0; i < n; i++) {
        if(i == 0 || i == n - 1) cout<<ch;
        else cout<<' ';
    }
    cout<<endl;
    return;
}

int main()
{
    char ch;
    int n;
    cin>>n>>ch;
    fun1(ch, n);
    for(int i = 1; i < round(n / 2.0) - 1; i++) {
        fun2(ch, n);
    }
    fun1(ch, n);
    return 0;
}
