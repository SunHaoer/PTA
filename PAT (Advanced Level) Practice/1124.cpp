#include<iostream>
#include<map>
using namespace std;
const int MAX = 1010;

int main()
{
    int m, n, s;
    string names[MAX];
    map<string, bool> mp;
    cin>>m>>n>>s;
    for(int i = 1; i <= m; i++) {    // 输入
        cin>>names[i];
    }
    if(s > m) {             // 人数不足
        cout<<"Keep going..."<<endl;
    } else {
        while(s <= m) {     // 有人中奖
            if(!mp[names[s]]) {      // 中奖
                cout<<names[s]<<endl;
                mp[names[s]] = true;
                s += n;
            } else {                 // 已经中奖
                s++;
            }
        }
    }
    return 0;
}
