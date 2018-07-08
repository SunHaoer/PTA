#include<iostream>
#include<cctype>
#include<map>
using namespace std;

int main()
{
    string str1, str2;
    map<char,bool> word;
    cin>>str1>>str2;         // 输入原文str1,打字文str2
    for(int i = 0; i < str1.size(); i++) {        // 把原文的字符标记为true
        str1[i] = toupper(str1[i]);
        word[str1[i]] = true;
    }
    for(int i = 0; i < str2.size(); i++) {        // 把打出的字符标记为false
        str2[i] = toupper(str2[i]);
        word[str2[i]] = false;
    }
    for(int i = 0; i < str1.size(); i++) {
        if(word[str1[i]] == true) {               // 原文中出现 && 没有被打印
            cout<<str1[i];
            word[str1[i]] = false;
        }
    }
    return 0;
}
