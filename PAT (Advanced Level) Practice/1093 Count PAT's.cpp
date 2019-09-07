#include<iostream>
using namespace std;
const int MAX = 100010;

int main()
{
    string str;
    int leftNumP[MAX] = { 0 }, rightNumT[MAX] = { 0 };
    int ans = 0;
    cin>>str;
    for(int i=0; i<str.size(); i++){
        if(i>0){
            leftNumP[i] = leftNumP[i-1];
        }
        if(str[i]=='P'){
            leftNumP[i]++;
        }
    }
    for(int i=str.size()-1; i>=0; i--){
        if(i<str.size()-1){
            rightNumT[i] = rightNumT[i+1];
        }
        if(str[i]=='T'){
            rightNumT[i]++;
        }
    }
    for(int i=0; i<str.size(); i++){
        if(str[i]=='A'){
            ans = ( ans + leftNumP[i] * rightNumT[i] ) % 1000000007;
        }
    }
    cout<<ans<<endl;
    return 0;
}
