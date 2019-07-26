#include<iostream>
#include<cctype>
#include<map>
using namespace std;

int main()
{
    string str1, str2;
    bool shift = false;        // 上档键
    map<char, bool> m;         // m[按键] = true / false
    getline(cin, str1);
    getline(cin, str2);
    for(int i = 0; i < str1.size(); i++) {           // 把坏键标记为true
        if(str1[i] == '+') {
            shift = true;
        }
        m[str1[i]] = true;
        m[tolower(str1[i])] = true;
    }
    for(int i = 0; i < str2.size(); i++) {
        if(m[str2[i]] == true) continue;              // 此键已坏
        if(shift == true && (str2[i]>='A' && str2[i]<='Z')) continue;           // 上档键坏
        cout<<str2[i];
    }
    return 0;
}

