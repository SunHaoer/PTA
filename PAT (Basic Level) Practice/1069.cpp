#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string, bool> peo;
    int m, n, s;                // ת����m, ���n, ��ʼ���s
    string name[1010];
    cin>>m>>n>>s;
    for(int i = 1; i <= m; i++) {
        cin>>name[i];
        peo[name[i]] = false;
    }
    if(s > m) {
        cout<<"Keep going..."<<endl;
    }
    while(s <= m){
        if(peo[name[s]] == false) {
            cout<<name[s]<<endl;
            peo[name[s]] = true;
            s += n;
        } else{                  // ���콱
            s++;
        }
    }
    return 0;
}
