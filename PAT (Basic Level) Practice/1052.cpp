#include<iostream>
using namespace std;
string str[3][11];

int putin(string *str) {
    string sstr, str0;
    getline(cin, sstr);          // ����һ����sstr
    int j = 1;                   // str���±�Ϊ1��ʼ����
    for(int i = 0; i < sstr.size(); i++) {
        if(sstr[i] == '[') {                 // ��������'['��ʼ
            i++;
            while(sstr[i] != ']') {          // ��������']'����
                str0 = str0 + sstr[i];       // []�ڵ��ַ�����str0
                i++;
            }
            str[j++] = str0;                 // ��str0��Ϊ�Ӵ�����str
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
        int n[5] = { 0 };              // [����]([����][��][����])[����]
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
