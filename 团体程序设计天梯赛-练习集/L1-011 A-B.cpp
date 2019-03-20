#include<iostream>
using namespace std;
const int MAX = 10010;
bool table[MAX];

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    for(int i = 0; i < str2.length(); i++) {
        table[str2[i]] = true;
    }
    for(int i = 0; i < str1.length(); i++) {
        if(!table[str1[i]]) cout<<str1[i];
    }
    return 0;
}
