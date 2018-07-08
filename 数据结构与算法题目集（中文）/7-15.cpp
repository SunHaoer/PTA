#include<iostream>
#include<map>
using namespace std;
map<long long, bool> m1;
map<long long, string> m2;

void fun1(long long userName, string passWord) {
    if(m1[userName] == true) {
        cout<<"ERROR: Exist"<<endl;
    } else {
        m1[userName] = true;
        m2[userName] = passWord;
        cout<<"New: OK"<<endl;
    }
}

void fun2(long long userName, string passWord) {
    if(m1[userName] == false) {
        cout<<"ERROR: Not Exist"<<endl;
    } else if(passWord != m2[userName]) {
        cout<<"ERROR: Wrong PW"<<endl;
    } else if(passWord == m2[userName]) {
        cout<<"Login: OK"<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        char ch;
        long long userName;
        string passWord;
        cin>>ch>>userName>>passWord;
        switch (ch) {
            case 'N': fun1(userName, passWord); break;
            case 'L': fun2(userName, passWord); break;
        }
    }
}
