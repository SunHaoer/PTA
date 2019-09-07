#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100010;

int main()
{
    int n, m, ans = 0;
    int N[MAX], M[MAX];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>N[i];
    }
    sort(N, N+n);
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>M[i];
    }
    sort(M, M+m);
    int i = 0, j = 0;
    while(i<n&&i<m&&N[i]<0&&M[i]<0){
        ans += ( N[i] * M[i]);
        i++;
    }
    i = n - 1;
    j = m - 1;
    while(i>=0&&j>=0&&N[i]>0&&M[j]>0){
        ans += ( N[i--] * M[j--]);
    }
    cout<<ans<<endl;
    return 0;
}
