#include<iostream>
#include<cctype>
#include<map>
using namespace std;

int main()
{
    string str1, str2;
    cin>>str1>>str2;
    map<char, bool> m;
    for(int i=0; i<str1.size(); i++){       //��str1, str2ת��Ϊ��д
        str1[i] = toupper(str1[i]);
        str2[i] = toupper(str2[i]);
    }
    for(int i=0; i<str2.size(); i++){       //��str2���ַ����Ϊtrue
        m[str2[i]] = true;
    }
    for(int i=0; i<str1.size(); i++){       //����str1���ַ�
        if(m[str1[i]]==false){
            cout<<str1[i];
            m[str1[i]] = true;
        }
    }
    return 0;
}
