#include<iostream>
#include<cstdio>
using namespace std;

int fun(string str){
    int ans = 1;
    bool flag = false;
    if(str.size()=='0'){          //空字符串
        ans = 0;
    }
    else{
        for(int i=1; i<str.size(); i++){
            if( ((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))&&str[i-1]==' '){           //字母+' '
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    int repeat;
    cin>>repeat;
    while(repeat--){
        string str;
        cin>>str;
        getline(cin, str);
        int ans = fun(str);
        cout<<ans<<endl;
    }
    return 0;
}
