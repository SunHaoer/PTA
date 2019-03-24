#include<iostream>
using namespace std;
string str, maxStr = "";
int maxLen = -1, tempLen = -1;

string fun1(int index) {
    string tempStr = "";
    tempStr += str[index];
    int i = 0;
    while(i++ >= 0) {
        if(index - i < 0 || index + i > str.size()) break;
        if(str[index - i] != str[index + i]) break;
        tempStr = str[index - i] + tempStr + str[index + i];
    }
    return tempStr;
}

string fun2(int index) {
    string tempStr = "";
    int i = 0;
    while(true) {
        if(index - i < 0 || index + i + 1 > str.size()) break;
        if(str[index - i] != str[index + i + 1]) break;
        tempStr = str[index - i] + tempStr + str[index + i + 1];
        i++;
    }
    return tempStr;
}

int main()
{
    getline(cin, str);
    for(int i = 0; i < str.size(); i++) {
        tempLen = fun1(i).size();
        if(tempLen > maxLen) {
            maxLen = tempLen;
        }
        tempLen = fun2(i).size();
        if(tempLen > maxLen) {
            maxLen = tempLen;
        }
    }
    cout<<maxLen<<endl;
    return 0;
}
