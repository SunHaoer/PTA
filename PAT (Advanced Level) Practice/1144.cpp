#include<iostream>
#include<map>
#include<climits>
using namespace std;
const int MAX = 100010;
map<int, bool> table;

int main()
{
    int n, num;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>num;
        if(num <= 0) continue;
        else table[num] = true;
    }
    for(int i = 1; i < INT_MAX; i++) {
        if(table[i] == false) {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
