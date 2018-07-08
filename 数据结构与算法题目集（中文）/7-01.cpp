#include<iostream>
using namespace std;
const int MAX = 100010;

int main()
{
    int n, num[MAX], ans[MAX], maxn = -1;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>num[i];
    }
    ans[0] = num[0];
    for(int i = 1; i < n; i++) {
        ans[i] = max(num[i], ans[i - 1] + num[i]);
    }
    for(int i = 0; i < n; i++) {
        maxn = max(maxn, ans[i]);
    }
    cout<<maxn<<endl;
    return 0;
}
