#include<iostream>
using namespace std;

int main()
{
    int repeat, ans = 0;;
    string str;
    cin>>repeat;
    while(repeat > 0) {
        repeat--;
        cin>>str;
        if(str[0] == '-') str.erase(str.begin() + 0);
        ans = 0;
        for(int i = 0; i < str.size(); i++) {
            int a = str[i] - '0';
            ans += a;
        }
        cout<<"number="<<str.size()<<",sum="<<ans<<"."<<endl;
    }
    return 0;
}
