#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 110;
string input[MAX];
char ch;
int n;

bool fun2(string str1, string str2) {
    for(int i = 0; i < str1.length(); i++) {
        if(str1[i] != str2[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool fun1() {
    for(int i = 0; i < n; i++) {
        if(!fun2(input[i], input[n - 1 - i])) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin>>ch>>n;
    getchar();
    for(int i = 0; i < n; i++) {
        getline(cin, input[i]);
    }
    if(fun1()) cout<<"bu yong dao le"<<endl;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = input[i].size() - 1; j >= 0; j--) {
            if(input[i][j] != ' ') cout<<ch;
            else cout<<input[i][j];
        }
        cout<<endl;
    }
    return 0;
}
