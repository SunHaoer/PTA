#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 35;
int num[3][MAX], arr[MAX];

void fun1(string str, int num[]) {           //把str存入num
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.size(); i++) {
        num[i] = str[i] - '0';
    }
    return;
}

int main()
{
    string str[3];
    cin>>str[0]>>str[1]>>str[2];
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        fun1(str[i], num[i]);
    }
    int carry = 0;
    while(num[1][ans] + num[2][ans] + carry != 0) {
        if(num[0][ans] == 0) num[0][ans] = 10;
        arr[ans] = (num[1][ans] + num[2][ans] + carry) % num[0][ans];
        carry = (num[1][ans] + num[2][ans] + carry) / num[0][ans];
        ans++;
    }
    if(ans == 0) {
        cout<<0<<endl;
    } else{
        for(int i = ans - 1; i >= 0; i--) {
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
