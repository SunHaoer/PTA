#include<iostream>
using namespace std;

string fun1(string str) {
    string temp;
    int n = 1;
    if(str.size() == 1) {
        temp = temp + str[0] + '1';
    } else {
        for(int i = 1; i < str.size(); i++) {
            if(str[i] == str[i - 1]) {
                n++;
            } else {
                temp += str[i - 1];
                temp += (n + '0');
                n = 1;
            }
        }
        temp += str[str.size() - 1];
        temp += (n + '0');
    }
    return temp;
}

int main()
{
    int n;
    string str;
    cin>>str>>n;
    for(int i=1; i<n; i++){
        str = fun1(str);
    }
    cout<<str<<endl;
    return 0;
}


/*
*  1
*  11
*  12
*  1121
*  122111
*  112213
*  12221131
*  1123123111
*/
