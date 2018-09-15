#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int ans[26] = { 0 };

void fun1(char words){
        if(words>='A'&&words<='Z'){
            ans[words-'A']++;
        }
    return;
}

void fun2(){
    int maxn = -1;
    for(int i=0; i<26; i++){
        if(ans[i]>maxn){
            maxn = ans[i];
        }
    }
    for(int i=1; i<=maxn; i++){       //µÚiÐÐ
        for(int j=0; j<25; j++){
            if(maxn-ans[j]>=i){
                cout<<"  ";
            }
            else {
                cout<<"* ";
            }
        }
        if(maxn-ans[25]>=i){
            cout<<" ";
        }
        else {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
    return;
}

int main()
{
    char temp[73];
    while(scanf("%s", &temp)!=EOF){
        char words[73];
        for(int i=0; i<strlen(temp); i++){
            words[i] = toupper(temp[i]);
            fun1(words[i]);
        }
    }
    fun2();
    return 0;
}
