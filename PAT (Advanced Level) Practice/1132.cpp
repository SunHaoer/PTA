#include<iostream>
#include<sstream>
using namespace std;

int fun2(string str, int n, int m) {        // 截取出字符串并转为int
    string temp;
    stringstream stream;
    int num;
    for(int i = n; i < m; i++) {
        temp += str[i];
    }
    stream<<temp;
    stream>>num;
    return num;
}

bool fun1(int z) {
    string str, str1, str2;
    int a, b, c;
    stringstream stream1, stream2, stream3;
    stream1<<z;
    stream1>>str;
    a = z;      // 167334
    b = fun2(str, 0, str.size() / 2);       // 167
    c = fun2(str, str.size() / 2, str.size());      // 334
    return b * c != 0 && a % (b * c) == 0;
}

int main()
{
    int z, n, a, b;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>z;
        if(fun1(z)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
