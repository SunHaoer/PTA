#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int ans = 0, len = str.length();
    double cnt = 1;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '2') {
            ans++;
        }
    }
    if(str[0] == '-') {
        cnt *= 1.5;
        len--;
    }
    cnt *= (ans * 1.0) / len;
    if((str[str.length() - 1] - '0') % 2 == 0) cnt *= 2;
    printf("%.2f%%\n", cnt * 100);
    return 0;
}
