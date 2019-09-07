#include<iostream>
using namespace std;
const int MAX = 10010;

int main()
{
    int n, num[MAX] = { 0 };
    cin>>n;
    for(int i = 0; i < n; i++) {
        int age;
        cin>>age;
        num[age]++;
    }
    for(int i = 0; i < MAX; i++) {
        if(num[i] != 0) cout<<i<<":"<<num[i]<<endl;
    }
    return 0;
}
