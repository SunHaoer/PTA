#include<iostream>
#include<cstdio>
#include<sstream>
#include<cctype>
using namespace std;

bool check(string str) {        // 校验
    int cnt = 0;
    if(str.size() > 8) return false;        // 太长
    for(int i = 0; i < str.size(); i++) {
        if(!isdigit(str[i])) {
            if(str[i] == '-' && i == 0) {   // 1-2
                continue;
            }
            if(str[i] == '.' && str.size() - 1 - i <= 2 && cnt == 0) {      // 1.123, 1.1.2
                cnt++;
                continue;
            }
            return false;
        }
    }
    return true;
}

int main()
{
    int n, cnt = 0;
    double sum = 0;
    cin>>n;
    for(int i = 0; i < n; i++) {
        string str;
        cin>>str;
        if(!check(str)) {
            cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
        } else {
            double num;
            stringstream stream;
            stream<<str;
            stream>>num;
            if(num < -1000 || num > 1000) {     // 太大或太小
                cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
                continue;
            } else {
                sum += num;
                cnt++;
            }
        }
    }
    if(cnt == 1) printf("The average of %d number is %.2f\n", cnt, sum / cnt);
    else if(cnt != 0) printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    else printf("The average of 0 numbers is Undefined\n");
    return 0;
}
