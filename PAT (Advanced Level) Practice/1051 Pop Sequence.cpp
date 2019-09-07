#include<iostream>
#include<stack>
using namespace std;
const int maxn = 1010;

int main()
{
    int m, n, k;
    cin>>m>>n>>k;
    while(k--){
        stack<int> st;
        while(st.empty()==false){
            st.pop();
        }
        int temp = 1, arr[maxn];
        bool flag = true;
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        for(int i=1; i<=n; i++){
            st.push(i);
            if(st.size()>m){
                flag = false;
                break;
            }
            while(st.empty()==false&&st.top()==arr[temp]){
                st.pop();
                temp++;
            }
        }
        if(st.empty()==true&&flag==true){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
