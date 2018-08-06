#include<iostream>
using namespace std;

int main()
{
    string str, temp = "", maxStr = "";
    getline(cin, str);
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == str[i + 1]) {      // ABBA
            temp += str[i];
            temp += str[i + 1];
            int j = 1;
            while(i - j >= 0 && i + 1 + j < str.size() && str[i - j] == str[i + 1 + j]) {
                temp = str[i - 1] + temp + str[i + 1 + j];
                j++;
            }
        } else {                        // ABCBA
            temp = str[i];
            int j = 1;
            while(i - j >= 0 && i + j < str.size() && str[i - j] == str[i + j]) {
                temp = str[i - j] + temp + str[i + j];
                j++;
            }
        }
        if(temp.size() > maxStr.size()) {
            maxStr = temp;
        }
        temp = "";
    }
    cout<<maxStr.size()<<endl;
    return 0;
}
