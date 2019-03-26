#include<iostream>
#include<map>
using namespace std;
map<string, bool> table;

int main()
{
    string str, str1 = "", str2 = "";
    int ans = 1;
    while(cin>>str) {
        if(str == ".") break;
        if(table[str]) break;
        table[str] = true;
        if(ans == 2) str1 = str;
        else if(ans == 14) str2 = str;
        ans++;
    }
    if(str1 == "" && str2 == "") cout<<"Momo... No one is for you ..."<<endl;
    else if(str1 != "" && str2 == "") cout<<str1<<" is the only one for you..."<<endl;
    else cout<<str1<<" and "<<str2<<" are inviting you to dinner..."<<endl;
    return 0;
}
