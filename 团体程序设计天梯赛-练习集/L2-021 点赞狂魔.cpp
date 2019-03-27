#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
const int MAX = 110;

struct People {
    string name;
    int cnt;
    People() {
        cnt = 0;
    }
} peo[MAX];

bool cmp(People a, People b) {
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    else return a.name > b.name;
}


int main()
{
    int n, m, k;
    string str;
    set<int> st;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>str>>m;
        st.clear();
        for(int j = 0; j < m; j++) {
            cin>>k;
            st.insert(k);
        }
        peo[i].name = str;
        peo[i].cnt = st.size();
    }
    sort(peo, peo + n, cmp);
    for(int i = 0; i < 3; i++) {
        if(i != 0) cout<<" ";
        if(peo[i].cnt == 0) cout<<"-";
        cout<<peo[i].name;
    }
    return 0;
}
