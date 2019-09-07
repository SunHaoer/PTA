#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 500;
string strs[MAX];


int main()
{
    int n;
    bool flag = true;
    string str = "";
    cin>>n;
    getchar();
    for(int i = 0; i < n; i++){     // 输入
        getline(cin, strs[i]);
    }
    for(int i = 0; i < MAX; i++) {    // 求最长后缀
        if(i == strs[0].size()) break;
        char ch1 = strs[0][strs[0].size() - 1 - i];
        for(int j = 1; j < n; j++) {    // 长度到了
            if(i == strs[j].size()) {
                flag = false;
                break;
            }
            char ch2 = strs[j][strs[j].size() - 1 - i];
            if(ch1 != ch2) {            // 不一样
                flag = false;
                break;
            }
        }
        if(flag) str += ch1;          // 符合
        else break;            // 跳出循环
    }
    reverse(str.begin(), str.begin() + str.size());     // 反转
    if(str != "") cout<<str<<endl;
    else cout<<"nai"<<endl;
    return 0;
}
