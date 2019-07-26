#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<char, bool> mp;
    string str;
    for(int i = 0; i < 2; i++) {
        getline(cin, str);
        for(int j = 0; j < str.length(); j++) {
            if(!mp[str[j]]) {
                cout<<str[j];
                mp[str[j]] = true;
            }
        }
    }
    return 0;
}
