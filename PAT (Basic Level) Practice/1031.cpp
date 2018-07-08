#include<iostream>
using namespace std;
int n[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char zm[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};          // zm[Z] = M

int fun1(string str) {
    int sum = 0;
    for(int i = 0; i < 17; i++) {
        if(str[i] < '0' || str[i] > '9') {
            return -1;                          // 非法
        }
        str[i] = str[i] - '0';
        sum = (sum + str[i] * n[i]) % 11;
    }
    return sum;
}

int main()
{
    int repeat, ans = 0;
    cin>>repeat;
    string id;                                  // 身份证号
    for(int i = 0; i < repeat; i++) {
        int sum = 0;
        cin>>id;
        sum = fun1(id);                         // 求验证码
        if(sum == -1) {
            cout<<id<<endl;
            ans = 1;
            continue;
        }
        if(zm[sum] != id[17] ) {
            cout<<id<<endl;
            ans = 1;
        }
    }
    if(ans == 0) cout<<"All passed"<<endl;
    return 0;
}
