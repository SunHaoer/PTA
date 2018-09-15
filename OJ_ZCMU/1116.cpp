#include<iostream>
#include<cmath>
#include<vector>
#include<sstream>
using namespace std;
const int MAX = 100000001;
vector<int> v;

void fun3() {
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<endl;
    }
}

bool fun2(int n) {
    string str;
    stringstream stream;
    stream<<n;
    stream>>str;
    for(int i = 0; i <= str.size() / 2; i++) {
        if(str[i] != str[str.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

void fun1(int a, int b) {
    for(int i = a; i <= b; i++) {
//        cout<<i<<endl;
        bool flag = true;
        for(int j = 2; j <= sqrt(i); j++) {
            if(i % j == 0) {                // ·ÇËØÊý
                flag = false;
                break;
            }
        }
        if(flag && fun2(i)) {
            v.push_back(i);
        }
    }
}

int main()
{
    int a, b;
    while(cin>>a>>b) {
        fun1(a, b);
        fun3();
        v.clear();
    }

    return 0;
}
