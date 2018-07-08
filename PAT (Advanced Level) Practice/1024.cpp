#include<iostream>
#include<algorithm>
using namespace std;

string fun1(string str1, string str2) {
    string str;
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < str1.size(); i++) {
        a = (str1[i] - '0');
        b = (str2[i] - '0');
        if(a + b + c < 10) {
            str += ((a + b + c) + '0');
            c = 0;
        } else {
            str += ((a + b + c - 10) + '0');
            c = 1;
        }
    }
    if(c != 0) {
        str += (c + '0');
    }
    reverse(str.begin(), str.end());
    //cout<<str<<endl;
    return str;
}

bool fun2(string str) {                 // 判断是否回文
    for(int i = 0; i <= str.size() / 2; i++) {
        if(str[i] != str[str.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1, str2;     // 数字str
    int n;          // 次数n
    cin>>str1>>n;           // 1234
    if(fun2(str1) == true) {
        cout<<str1<<endl<<"0"<<endl;
    } else {
        bool flag = false;
        for(int i = 1; i <= n; i++) {
            str2 = str1;
            reverse(str1.begin(), str1.end());      // str1 = 4321, str2 = 1234
            str1 = fun1(str1, str2);
            if(fun2(str1) == true) {
                cout<<str1<<endl<<i<<endl;
                flag = true;
                break;
            }
        }
        if(flag == false) {
            cout<<str1<<endl<<n<<endl;
        }
    }
    return 0;
}
