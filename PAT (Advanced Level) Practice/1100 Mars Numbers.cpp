#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
using namespace std;
string strs1[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string strs2[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

void earthToMars(int n) {            // int->str
    string results[2];
    results[0] = strs1[n / 13];
    if(n / 13 != 0 && n % 13 != 0) results[0] += " ";
    results[1] = strs2[n % 13];
    if(n / 13 != 0 && n % 13 == 0) results[1] = "";
    cout<<results[0]<<results[1]<<endl;
}

void marsToEarth(string str) {            // str->int
    int num = 0;
    string temp[2];
    int i = 0;
    for(i = 0; i < str.size(); i++) {
        if(str[i] == ' ') break;
        temp[0] += str[i];
    }
    for(int j = 0; j < 13; j++) {
        if(temp[0] == strs1[j]) {
            num = j * 13;
            break;
        }
        if(temp[0] == strs2[j]) {
            num += j;
            break;
        }
    }
    for(i = i; i < str.size(); i++) {
        if(str[i] == ' ') continue;
        temp[1] += str[i];
    }
    for(int j = 0; j < 13; j++) {
        if(temp[1] == strs2[j]) {
            num += j;
            break;
        }
    }
    cout<<num<<endl;
}

int main()
{
    int n;
    cin>>n;
    getchar();
    for(int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        if(isdigit(str[0])) {   // int->str
            int num;
            stringstream stream;
            stream<<str;
            stream>>num;
            earthToMars(num);
        } else {                // str->int
            marsToEarth(str);
        }
    }
    return 0;
}
