#include<iostream>
#include<cctype>
#include<map>
using namespace std;

int main()
{
    string str1, str2;
    map<char,bool> word;
    cin>>str1>>str2;         // ����ԭ��str1,������str2
    for(int i = 0; i < str1.size(); i++) {        // ��ԭ�ĵ��ַ����Ϊtrue
        str1[i] = toupper(str1[i]);
        word[str1[i]] = true;
    }
    for(int i = 0; i < str2.size(); i++) {        // �Ѵ�����ַ����Ϊfalse
        str2[i] = toupper(str2[i]);
        word[str2[i]] = false;
    }
    for(int i = 0; i < str1.size(); i++) {
        if(word[str1[i]] == true) {               // ԭ���г��� && û�б���ӡ
            cout<<str1[i];
            word[str1[i]] = false;
        }
    }
    return 0;
}
