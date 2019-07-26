#include<iostream>
#include<cstdio>
#include<sstream>
#include<cctype>
using namespace std;

int main()
{
    int N, ans = 0;
    double n, avg;
    cin>>N;
    for(int i = 0; i < N; i++) {
        string str;
        cin>>str;
        int flag1 = 0, flag2 = 0;
        for(int j = 0; j < str.size(); j++) {
            if(isdigit(str[j]) == false && str[j] != '.' && str[j] != '-') {     // 存在不合法字符
                cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
                flag2 = 1;
                break;
            } else if(str[j] == '.') {
                flag1++;
                if(flag1 > 1 || j == 0 || str.size() - j > 3) {                   // '.'不合法
                    cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
                    flag2 = 1;
                    break;
                }
            } else if(str[j] == '-' && j != 0) {            // '-'不合法
                cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
                flag2 = 1;
                break;
            }
        }
        if(flag2 == 0) {
            stringstream stream;
            stream<<str;
            stream>>n;
            if(n > 1000 || n < -1000) {                     // 太大或太小
                cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
                continue;
            }
            avg += n;
            ans++;
        }
    }
    if(ans == 0) {
        printf("The average of 0 numbers is Undefined");
    } else if(ans == 1) {                                   // 复数numbers, 单数不加s!!??
        printf("The average of %d number is %.2f\n", ans, avg / (ans * 1.0));
    } else {
        printf("The average of %d numbers is %.2f\n", ans, avg / (ans * 1.0));
    }
    return 0;
}
