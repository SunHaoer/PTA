#include<iostream>
using namespace std;

int main()
{
    int n, m;
    int num[110];
    bool flag = false;      // 用于判断是否第一次输出
    cin>>n>>m;
    m %= n;                 // n大于m
    for(int i = 0; i < n; i++){
        cin>>num[i];
    }
    for(int i = n - m; i < n; i++){
        if(flag == true) cout<<" ";
        cout<<num[i];
        flag = true;
    }
    for(int i = 0; i < n - m; i++) {
        if(flag == true) cout<<" ";
        cout<<num[i];
        flag = true;
    }
    cout<<endl;
    return 0;
}
