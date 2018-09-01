#include<iostream>
using namespace std;

int main()
{
    string d, str;
    char ch;
    int n, cnt = 0;
    cin>>d>>n;
    for(int i = 0; i < n - 1; i++) {    // 执行n - 1次
        cnt = 1, str = "", ch = d[0];
        for(int j = 1; j < d.size(); j++) {
            if(d[j] == ch) {      // 和上一个字符相同
                cnt++;
            } else {              // 和上一个字符不同
                str += ch;
                str += (char)(cnt + '0');
                cnt = 1;
                ch = d[j];
            }
        }
        str += ch;
        str += char(cnt + '0');
        d = str;
    }
    cout<<d<<endl;      // 输出
    return 0;
}
