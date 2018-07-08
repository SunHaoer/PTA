#include<iostream>
#include<map>
using namespace std;

int main()
{
    int repeat;
    cin>>repeat;
    for(int i = 0; i < repeat; i++) {
        string str;
        cin>>str;
        int p = 0, t = 0;       // p前的字母数p, t前的字母数t
        map<char, int> m;
        for(int j = 0; j < str.size(); j++) {
            m[str[j]]++;
            if(str[j] == 'P') p = j;
            if(str[j] == 'T') t = j;
        }
        if(m['P'] == 1 && m['T'] == 1 && m['A'] != 0 && m.size() == 3 && (p * (t - p - 1) == str.size() - 1 - t) ) {
            // P, T有且只有一个 && A的数量不为0 && 只有三种字母
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}


/*
根据百度, 易知: 只能有一个P一个T, 中间末尾和开头可以随便插入A。但是必须满足开头的A的个数 * 中间的A的个数 = 结尾的A的个数
*/
