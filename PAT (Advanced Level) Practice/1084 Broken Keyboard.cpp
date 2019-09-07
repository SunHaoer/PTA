#include<iostream>
#include<cctype>
#include<map>
using namespace std;

int main()
{
    string str1, str2;
    cin>>str1>>str2;
    map<char, bool> m;
    for(int i=0; i<str1.size(); i++){       //把str1, str2转换为大写
        str1[i] = toupper(str1[i]);
        str2[i] = toupper(str2[i]);
    }
    for(int i=0; i<str2.size(); i++){       //把str2的字符标记为true
        m[str2[i]] = true;
    }
    for(int i=0; i<str1.size(); i++){       //遍历str1的字符
        if(m[str1[i]]==false){
            cout<<str1[i];
            m[str1[i]] = true;
        }
    }
    return 0;
}
