#include<iostream>
using namespace std;
int ans = 0;      //记录人数

struct people{
    string name;    //姓名
    string date;      //年月日
}maxn, minn, peo;

int check(people peo){
    if(peo.date < "1814/09/06" || peo.date > "2014/09/06") {         //不合理的生日
        return 0;
    }
    if(peo.date < maxn.date){                       // 更新最大者
        maxn.name = peo.name;
        maxn.date = peo.date;
    }
    if(peo.date > minn.date){                       // 更新最小者
        minn.name = peo.name;
        minn.date = peo.date;
    }
    ans++;
    return 0;
}

int main()
{
    int N;          // N个人
    cin>>N;
    maxn.date = "20151332";
    minn.date = "00000000";
    for(int i = 0; i < N; i++) {
        cin>>peo.name;       // 输入姓名
        cin>>peo.date;       // 输入日期
        check(peo);
    }
    if(ans == 0) cout<<'0'<<endl;
    else cout<<ans<<' '<<maxn.name<<' '<<minn.name;
    return 0;
}
