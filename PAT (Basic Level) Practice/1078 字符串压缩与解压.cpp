#include<iostream>
#include<cstdio>
using namespace std;

void fun1(string str){           // ѹ��
    for(int i = 0; i < str.size() - 1; i++) {
        int ans = 1;
        while(str[i] == str[i + 1]) {       // ��⵽�ظ�
            ans++;
            i++;
        }
        if(ans != 1) {
            cout<<ans;
        }
        cout<<str[i];
    }
    if(str[str.size() - 1] != str[str.size() - 2]) {
        cout<<str[str.size() - 1];
    }
    return;
}

void fun2(string str) {          // ��ѹ
    int repeat = 0;
    for(int i = 0; i < str.size(); i++) {
        while(str[i] >= '0' && str[i] <= '9') {       // Ϊ����
            repeat = repeat * 10 + (str[i] - '0' );
            i++;
        }
        for(int j = 0; j < repeat - 1; j++) {
            cout<<str[i];
        }
        cout<<str[i];
        repeat = 0;
    }
    return;
}

int main()
{
    string key, str;
    cin>>key;
    getchar();
    getline(cin, str);
    if(key == "C") {       // ѹ��
        fun1(str);
    } else {               // ��ѹ
        fun2(str);
    }
    return 0;
}
