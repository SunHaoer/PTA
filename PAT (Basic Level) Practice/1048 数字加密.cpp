#include<iostream>
using namespace std;
char change[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K' };

int main()
{
    string str1, str2, str = "";
    cin>>str1>>str2;
    int i = 0, flag = 1;           // flag为1时,奇数位
    while(str2.size() < str1.size()) {        // 若B长度小于A,B前补0
        str2 = '0' + str2;
    }
    int len1 = str1.size(), len2 = str2.size();
    for(i = 0; i < str1.size() && i < str2.size(); i++) {          // 小于任意字符串
        int n = 0;                 // 相加相减之和
        int n1 = str1[len1 - 1 - i] - '0';        // 取最后一位
        int n2 = str2[len2 - 1 - i] - '0';
        char ch;
        if(flag == 1) {            // 奇数
            n = (n1 + n2) % 13;
            ch = change[n];
        }
        if(flag == -1) {           // 偶数
            n = n2 - n1;
            if(n < 0) n = n + 10;
            ch = change[n];
        }
        str = str + ch;
        flag = -flag;
    }
    for(i = i; i < str2.size(); i++) {           // A比B长
        str = str + str2[len2 - 1 - i];
    }
    for(i = str.size() - 1; i >= 0; i--) {       // 逆序输出
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}
