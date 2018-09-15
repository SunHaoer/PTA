#include<iostream>
#include<algorithm>
using namespace std;
string table[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

string fun1(int n) {
    string str = "";
    while(n != 0) {
        str += (table[n % 16]);
        n /= 16;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    int repeat, n;
    cin>>repeat;
    while(repeat > 0) {
        repeat--;
        cin>>n;
        cout<<fun1(n)<<endl;
    }
    return 0;
}
