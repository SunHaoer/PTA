#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n) {
        int maxn = -1, num = 0;
        for(int i = 0; i < n; i++) {
            cin>>num;
            maxn = max(maxn, num);
        }
        cout<<maxn<<endl;
    }
    return 0;
}
