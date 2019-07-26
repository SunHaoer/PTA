#include<iostream>
using namespace std;

int main()
{
    int n[10] = { 0 };
    for(int i = 0; i < 10; i++) {
        cin>>n[i];
    }
    for(int i = 1; i < 10; i++) {           // 第一位数不能为0
        if(n[i] != 0){
            cout<<i;
            n[i]--;
            break;
        }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < n[i]; j ++){
            cout<<i;
        }
    }
    return 0;
}
