#include<iostream>
#include<set>
#include<vector>
using namespace std;

int fun1(string str) {      // 求和
    int n = 0;
    for(int i = 0; i < str.size(); i++) {
        n += (str[i] - '0');
    }
    return n;
}

int main()
{
    set<int> st;
    vector<int> vt;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {        // 输入
        string str;
        cin>>str;
        int num = fun1(str);
        st.insert(num);
    }
    for(set<int>::iterator it = st.begin(); it != st.end(); it++) {     // set->vector
        vt.push_back(*it);
    }
    cout<<vt.size()<<endl;
    for(int i = 0; i < vt.size(); i++) {            // 输出
        if(i != 0) cout<<" ";
        cout<<vt[i];
    }
    cout<<endl;
    return 0;
}
