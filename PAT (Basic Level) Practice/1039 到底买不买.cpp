#include<iostream>
#include<map>
using namespace std;

int main()
{
    string str1, str2;                    // 需求str1, 提供str2
    map<char, int> m1, m2;                // m[珠子种类] = 数量
    int ans1 = 0, ans2 = 0;               // 多余ans1, 缺少ans2
    cin>>str1>>str2;
    for(int i = 0; i < str1.size(); i++) {
        m1[str1[i]]++;
    }
    for(int i = 0; i < str2.size(); i++) {
        m2[str2[i]]++;
    }
    for(int i = 0; i < m2.size() || i < m1.size(); i++) {
        if(m1[i] > m2[i]) ans1 += (m1[i] - m2[i]);            // 有余
        if(m1[i] < m2[i]) ans2 += (m2[i] - m1[i]);            // 不足
    }
    if(ans2 != 0) {
        cout<<"No "<<ans2<<endl;
    } else {
        cout<<"Yes "<<ans1<<endl;
    }
    return 0;
}
