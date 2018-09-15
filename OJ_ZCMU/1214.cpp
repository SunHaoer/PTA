#include<iostream>
using namespace std;
const int MAX = 110;
int table[MAX];

int main()
{
    int n;
    table[0] = 1;
    table[1] = 1;
    for(int i = 2; i < MAX; i++) {
        table[i] = table[i - 2] + table[i - 1];
    }
    while(cin>>n) {
        cout<<table[n]<<endl;
    }
    return 0;
}
