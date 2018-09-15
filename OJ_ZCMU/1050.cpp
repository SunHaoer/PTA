#include<iostream>
#include<algorithm>
using namespace std;

int fun1(string str) {          // ÇóºÍ
    int sum = 0;
    for(int i = 0; i < str.size(); i++) {
        sum += str[i];
    }
    return sum;
}

string fun2(int num) {
    string str = "";
    while(num > 0) {
        str += (num % 2 + '0');
        num /= 2;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    int repeat;
    cin>>repeat;
    for(int i = 0; i < repeat; i++) {
        string str;
        cin>>str;
        int sum = fun1(str);
//        cout<<sum<<endl;
        cout<<fun2(sum)<<endl;
    }
    return 0;
}
