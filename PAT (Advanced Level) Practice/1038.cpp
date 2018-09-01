#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 11000;

bool cmp(string str1, string str2) {
    for(int i = 0; i < str1.size() || i < str2.size(); i++) {
        int a = i % str1.size(), b = i % str2.size();
        if(str1[a] != str2[b]) return str1[a] < str2[b];
    }
    return true;
}

int main()
{
    int n;
    string strs[MAX], result = "";
    cin>>n;
    for(int i = 0; i < n; i++) {    // 输入
        cin>>strs[i];
    }
    sort(strs, strs + n, cmp);
    for(int i = 0; i < n; i++) {
        result += strs[i];
    }
    while(result[0] == '0') {       // 去掉首位的'0'
        result.erase(result.begin() + 0);
    }
    if(result != "") {          // 输出
        cout<<result<<endl;
    } else {
        cout<<"0"<<endl;
    }
    return 0;
}
