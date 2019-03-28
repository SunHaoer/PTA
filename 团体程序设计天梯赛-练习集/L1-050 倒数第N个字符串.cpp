#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string table = "abcdefghijklmnopqrstuvwxyz";

int fun1(int n) {
    int temp = 1;
    for(int i = 0; i < n; i++) {
        temp *= 26;
    }
    return temp;
}

void fun2(int n, int len) {
    string str = "";
    while(n != 0) {
        str += table[n % 26];
        n /= 26;
    }
    while(str.length() < len) {
        str += 'a';
    }
    reverse(str.begin(), str.end());
    cout<<str<<endl;
}

int main()
{
    int n, m, len;
    cin>>n>>m;
    len = n;
    n = fun1(n) - m;
    fun2(n, len);
    return 0;
}
