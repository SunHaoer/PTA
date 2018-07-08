#include<iostream>
#include<map>
using namespace std;

int main()
{
    string str1, str2;
    map<char, bool> m;
    getline(cin, str1);
    getline(cin, str2);
    for(int i=0; i<str2.size(); i++){
        m[str2[i]] = true;
    }
    for(int i=0; i<str1.size(); i++){
        if(m[str1[i]]==false) cout<<str1[i];
    }
    return 0;
}
