#include<iostream>
#include<map>
using namespace std;

const string table[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
    string inputStr;
    cin >> inputStr;
    if(inputStr[0] == '-') {
        cout << "fu ";
        inputStr = inputStr.substr(1, inputStr.length());
    }
    for(int i = 0; i < inputStr.length(); i++) {
        if(i != 0) cout << " ";
        cout << table[inputStr[i] - '0'];
    }
    return 0;
}
