#include<iostream>
using namespace std;
char change[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K' };

int main()
{
    string str1, str2, str = "";
    cin>>str1>>str2;
    int i = 0, flag = 1;           // flagΪ1ʱ,����λ
    while(str2.size() < str1.size()) {        // ��B����С��A,Bǰ��0
        str2 = '0' + str2;
    }
    int len1 = str1.size(), len2 = str2.size();
    for(i = 0; i < str1.size() && i < str2.size(); i++) {          // С�������ַ���
        int n = 0;                 // ������֮��
        int n1 = str1[len1 - 1 - i] - '0';        // ȡ���һλ
        int n2 = str2[len2 - 1 - i] - '0';
        char ch;
        if(flag == 1) {            // ����
            n = (n1 + n2) % 13;
            ch = change[n];
        }
        if(flag == -1) {           // ż��
            n = n2 - n1;
            if(n < 0) n = n + 10;
            ch = change[n];
        }
        str = str + ch;
        flag = -flag;
    }
    for(i = i; i < str2.size(); i++) {           // A��B��
        str = str + str2[len2 - 1 - i];
    }
    for(i = str.size() - 1; i >= 0; i--) {       // �������
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}
