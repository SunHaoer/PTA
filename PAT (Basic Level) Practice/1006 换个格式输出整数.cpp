#include<iostream>
using namespace std;

int main()
{
    string change[4] = {"G", "S", "B", "Q"};
    string str;
    cin>>str;
    for(int i = 0; i < str.size(); i++){
        int n = str[i] - '0';
        if(str.size() - 1 - i != 0){
            for(int j = 0; j < n; j++){
                cout<<change[str.size() - 1 - i];
            }
        } else {
            for(int j = 1; j <= n; j++){
                cout<<j;
            }
        }
    }
    return 0;
}
