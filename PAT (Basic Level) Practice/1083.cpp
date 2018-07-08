#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 10010;
int num1[MAX], num2[MAX] = { 0 };

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>num1[i];
    }
    for(int i = 1; i <= n; i++) {
        int temp;
        temp = num1[i] - i;
        num2[abs(temp)]++;
    }
    for(int i = n - 1; i >= 0; i--) {
        if(num2[i] > 1) cout<<i<<' '<<num2[i]<<endl;
    }
    return 0;
}
