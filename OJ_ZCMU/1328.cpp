#include<iostream>
using namespace std;
const int MAX = 100010;
string table[MAX];

void fun1() {
    fill(table, table + MAX, "Y");
    table[0] = "N";
    table[1] = "N";
    for(int i = 2; i < 101; i++) {
        for(int j = 2; j < 101; j++) {
            table[i * j] = "N";
        }
    }
}

int main()
{
    fun1();
    int n;
    cin>>n;
    cout<<table[n]<<endl;
    return 0;
}
