#include<iostream>
#include<cctype>
#include<map>
using namespace std;

int main()
{
    string str1, str2;
    bool shift = false;        // �ϵ���
    map<char, bool> m;         // m[����] = true / false
    getline(cin, str1);
    getline(cin, str2);
    for(int i = 0; i < str1.size(); i++) {           // �ѻ������Ϊtrue
        if(str1[i] == '+') {
            shift = true;
        }
        m[str1[i]] = true;
        m[tolower(str1[i])] = true;
    }
    for(int i = 0; i < str2.size(); i++) {
        if(m[str2[i]] == true) continue;              // �˼��ѻ�
        if(shift == true && (str2[i]>='A' && str2[i]<='Z')) continue;           // �ϵ�����
        cout<<str2[i];
    }
    return 0;
}

