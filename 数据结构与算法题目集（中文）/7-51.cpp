#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vt;

void fun1() {
    int data;
    while(cin>>data) {
        if(data == -1) break;
        vt.push_back(data);
    }
}

int main() {
    fun1();
    fun1();
    sort(vt.begin(), vt.end());
    if(vt.size() == 0) {
        cout<<"NULL";
    } else {
        cout<<vt[0];
        for(int i = 1; i < vt.size(); i++) {
            cout<<" "<<vt[i];
        }
    }
    cout<<endl;
    return 0;
}
