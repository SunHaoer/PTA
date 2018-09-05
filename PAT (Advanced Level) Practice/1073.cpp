#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
    string str, str1, str2;
    char op1, op2;
    int num1, num2;
    cin>>str;
    op1 = str[0];
    int i = 0;
    for(i = 1; i < str.size(); i++) {
        if(str[i] == 'E') break;
        if(str[i] == '.') continue;
        str1 += str[i];
    }
    op2 = str[++i];
    for(i = i + 1; i < str.size(); i++) {
        str2 += str[i];
    }
    num2 = atoi(str2.c_str());          // op1 str1 E op2 str2
    if(num2 == 0) {
        cout<<"1"<<endl;
    } else {
        if(op2 == '+') {
            while(str1.size() <= num2) {
                str1 += "0";
            }
            if(str1.size() > num2 + 1) {
                str1.insert(num2 + 1, ".");
            }
        } else {
            for(int i = 0; i < num2 - 1; i++) {
                str1 = "0" + str1;
            }
            str1 = "0." + str1;
        }
        if(op1 == '-') cout<<op1;
        cout<<str1<<endl;
    }
    return 0;
}
