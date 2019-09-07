#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100010;
int n, p , num[MAX];

int binarySearch(int i, long long x){
    if(num[n-1]<=x) return n;
    int l = i + 1, r = n - 1, mid;
    while(l<r){
        mid = (l + r) / 2;
        if(num[mid]<=x){
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    return l;
}

int main()
{
    cin>>n>>p;
    for(int i=0; i<n; i++){
        cin>>num[i];
    }
    sort(num, num+n);
    int ans = 1;
    for(int i=0; i<n; i++){
        int j = binarySearch(i, (long long)num[i]*p);
        ans = max(ans, j-i);
    }
    cout<<ans<<endl;
    return 0;
}
