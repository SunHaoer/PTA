#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int hashTable[80] = {0};

int fun1(char ch){
    if(ch>='0'&&ch<='9') return ch - '0';
    if(ch>='a'&&ch<='z') return ch - 'a' + 10;
    if(ch>='A'&&ch<='Z') return ch - 'A' + 36;
}

int main()
{
    string str1, str2;
    int ans = 0;
    cin>>str1>>str2;
    for(int i=0; i<str1.size(); i++){
        int index = fun1(str1[i]);
        hashTable[index]++;
    }
    for(int i=0; i<str2.size(); i++){
        int index = fun1(str2[i]);
        hashTable[index]--;
        if(hashTable[index]<0){
            ans++;
        }
    }
    if(ans>0){
        cout<<"No"<<' '<<ans<<endl;
    }
    else{
        cout<<"Yes"<<' '<<str1.size()-str2.size()<<endl;
    }
    return 0;
}
