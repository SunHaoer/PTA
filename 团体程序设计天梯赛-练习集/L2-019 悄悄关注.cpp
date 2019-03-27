#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int MAX = 10100;
map<string, bool> table;

struct People {
    string name;
    int cnt;
} peo[MAX];
set<string> st;

bool cmp(People a, People b) {
    return a.name < b.name;
}

int main()
{
    int n, cnt = 0;
    double ave = 0;
    string str;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>str;
        table[str] = true;
    }
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>peo[i].name>>peo[i].cnt;
        ave += peo[i].cnt;
    }
    ave /= n;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(!table[peo[i].name] && peo[i].cnt > ave) {
            st.insert(peo[i].name);
            flag = true;
        }
    }
    if(st.size() == 0) {
        cout<<"Bing Mei You"<<endl;
    } else {
        for(set<string>::iterator it = st.begin(); it != st.end(); it++) {
            cout<<*it<<endl;
        }
    }
    return 0;
}
