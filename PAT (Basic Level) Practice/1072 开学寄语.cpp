#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
    int n, m, temp, flag = 0, ans1 = 0, ans2 = 0;
    string name;
    cin>>n>>m;                         // ѧ����n,Υ����Ʒ��m
    map<int, bool> thing;
    for(int i = 0; i < m; i++) {       // Υ����Ʒ���Ϊtrue
        cin>>temp;
        thing[temp] = true;
    }
    for(int i = 0; i < n; i++) {
        cin>>name>>m;
        flag = 0;
        for(int j = 0; j < m; j++) {
            cin>>temp;                  // ��Ʒ���
            if(thing[temp] == true) {             // Υ��Ʒ
                ans2++;                           // Υ��Ʒ����ans2
                if(flag == 0) cout<<name<<":";
                printf(" %04d",temp);
                flag = 1;
            }
        }
        if(flag != 0) {
            ans1++;                     // ����ѧ����ans1
            cout<<endl;
        }
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}
