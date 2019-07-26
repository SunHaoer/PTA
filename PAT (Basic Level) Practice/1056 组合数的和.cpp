#include<iostream>
using namespace std;

int main()
{
    int num1[11];
    int n, sum = 0;
    cin>>n;                // 输入正整数n
    for(int i = 0; i < n; i++) {
        cin>>num1[i];      // 输入num1
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            sum = sum + num1[i] * 10 + num1[j];
        }
    }
    cout<<sum<<endl;
    return 0;
}
