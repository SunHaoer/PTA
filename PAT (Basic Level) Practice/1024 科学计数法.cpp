#include<iostream>
using namespace std;

int main()
{
    string str, str1, str2;         // str = ch str1 E ch2 str2(n)
    char ch1, ch2;
    int n = 0;
    cin>>str;
    ch1 = str[0];                   // +/-
    int i = 0;
    for(i = 1; i < str.size() && str[i] != 'E'; i++) {
        if(str[i] == '.') continue;            // 去掉'.'
        str1 += str[i];
    }
    ch2 = str[i + 1];
    for(i = i + 2; i < str.size(); i++) {
        str2 += str[i];
        n = n * 10 + (str[i] - '0');
    }
    if(n == 0) {
        str1 = "1";
    } else if(ch2 == '+') {                    // 大于1
        if(str1.size() - 1 > n) {                   // 插入小数点
            str1.insert(n + 1, ".");
        }
        while(str1.size() < n + 1) {           // 末尾加0
            str1 = str1 + '0';
        }
    } else if(ch2 == '-') {                    // 小于1
        for(int i = 0; i < n - 1; i++) {
            str1 = '0' + str1;
        }
        str1 = "0." + str1;
    }
    if(ch1 == '-' && str1 != "0") cout<<ch1;
    cout<<str1<<endl;
    return 0;
}
