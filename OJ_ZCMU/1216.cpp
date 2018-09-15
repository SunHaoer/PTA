#include<iostream>
using namespace std;
const int MAX = 30;
int table[MAX];

int main()
{
    int n, x;
    while(cin>>n>>x) {
        for(int i = 0; i < n; i++) {
            cin>>table[i];
        }
        int flag = -1;
        for(int i = 0; i < n; i++) {
            if(table[i] == x) {
                flag = i;
                break;
            }
        }
        cout<<flag<<endl;
    }
    return 0;
}
