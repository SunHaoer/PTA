#include<iostream>
using namespace std;
string str[3][11];

int putin(string *str) {
    string sstr, str0;
    getline(cin, sstr);          // 输入一整行sstr
    int j = 1;                   // str从下标为1开始存入
    for(int i = 0; i < sstr.size(); i++) {
        if(sstr[i] == '[') {                 // 遍历遇到'['开始
            i++;
            while(sstr[i] != ']') {          // 遍历遇到']'结束
                str0 = str0 + sstr[i];       // []内的字符存入str0
                i++;
            }
            str[j++] = str0;                 // 把str0作为子串存入str
            str0 = "";
        }
    }
    return j;
}

int main()
{
    int len[3];
    for(int i = 0; i < 3; i++) {
        len[i] = putin(str[i]);
    }
    int repeat;
    cin>>repeat;
    for(int i = 0; i < repeat; i++) {
        int n[5] = { 0 };              // [左手]([左眼][口][右眼])[右手]
        for(int j = 0; j < 5; j++) {
            cin>>n[j];
        }
        if( (n[0] > 0 && n[0] < len[0]) && (n[1] > 0 && n[1] < len[1]) && (n[2] > 0 && n[2] < len[2]) && (n[3] > 0 && n[3] < len[1]) && (n[4] > 0 && n[4] < len[0]) ){
            cout<<str[0][n[0]]<<'('<<str[1][n[1]]<<str[2][n[2]]<<str[1][n[3]]<<')'<<str[0][n[4]]<<endl;
        } else {
            cout<<"Are you kidding me? @\\/@"<<endl;
        }
    }
    return 0;
}
