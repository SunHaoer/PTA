#include<iostream>
using namespace std;
const int MOD = 1000000007;

int main()
{
    string str;
    cin>>str;
    int ans = 0, leftP = 0, rightT = 0;         // 总PAT数ans, A左边的P数leftP, A右边的T数rightT
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'T') rightT++;
    }
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'P') leftP++;
        if(str[i] == 'T') rightT--;
        if(str[i] == 'A') {
            ans = (ans + leftP * rightT % MOD) % MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}


/*
PAT数为每个A对应左边的P数量乘右边的T数量
*/
