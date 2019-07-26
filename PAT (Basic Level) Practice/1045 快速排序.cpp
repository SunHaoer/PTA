#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100010;
const int INF = 0x3fffffff;
int num[MAX], leftMax[MAX], rightMin[MAX], arr[MAX];

int main()
{
    int n, ans = 0;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>num[i];
    }
    leftMax[0] = 0;             // num[0]左边无数
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i-1], num[i-1]);
    }
    rightMin[n-1] = INF;        //num[n-1]右边无数
    for(int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i+1], num[i+1]);
    }
    for(int i = 0; i < n; i++) {
        if(num[i] > leftMax[i] && num[i] < rightMin[i]) {      // num[i]大于左边最大值, 小于右边最小值
            arr[ans++] = num[i];
        }
    }
    cout<<ans<<endl;
    for(int i = 0; i < ans; i++) {
        cout<<arr[i];
        if(i != ans - 1) cout<<' ';
    }
    cout<<endl;
    return 0;
}
