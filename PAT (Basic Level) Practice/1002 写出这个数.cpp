#include<iostream>
#include<cstdlib>
#include<sstream>
using namespace std;
string n[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int change(string str) {
    int num = 0;                    // ������
    for(int i = 0; i < str.size(); i++){
        num += (str[i] - '0');
    }
    return num;
}

string int_string(int num) {         // intתstring
    string str;
    stringstream stream;
    stream<<num;
    stream>>str;
    return str;
}

void print(int num) {                // �������
    string str = int_string(num);
    for(int i = 0; i < 1; i++){
        cout<<n[str[i] - '0'];
    }
    for(int i = 1; i < str.size(); i++){
        cout<<' '<<n[str[i] - '0'];
    }
}

int main()
{
    string str;                      // �⴮����
    cin>>str;
    int num = change(str);           // �õ��������
    print(num);                      // ���
    return 0;
}
