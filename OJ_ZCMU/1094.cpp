#include<iostream>
using namespace std;

int fun(string str){
    int ans = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='2') ans++;
    }
    return ans;
}

int main()
{
    int repeat;
    cin>>repeat;
    for(int i=0; i<repeat; i++){
        string str;
        cin>>str;
        int ans = fun(str);
        cout<<"count="<<ans<<endl;
    }
    return 0;
}
