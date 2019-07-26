#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
    int n, m, temp, flag = 0, ans1 = 0, ans2 = 0;
    string name;
    cin>>n>>m;                         // 学生数n,违禁物品数m
    map<int, bool> thing;
    for(int i = 0; i < m; i++) {       // 违禁物品标记为true
        cin>>temp;
        thing[temp] = true;
    }
    for(int i = 0; i < n; i++) {
        cin>>name>>m;
        flag = 0;
        for(int j = 0; j < m; j++) {
            cin>>temp;                  // 物品编号
            if(thing[temp] == true) {             // 违禁品
                ans2++;                           // 违禁品总数ans2
                if(flag == 0) cout<<name<<":";
                printf(" %04d",temp);
                flag = 1;
            }
        }
        if(flag != 0) {
            ans1++;                     // 犯法学生数ans1
            cout<<endl;
        }
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}
