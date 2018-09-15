#include<iostream>
using namespace std;
int num[1000], ans = 1;

void fun1() {
    num[0] = 1;
    for(int i=1; i<=1000; i++){
        int temp = 0;
        for(int j=1; j<i; j++){
            if(i%j==0){
                temp += j;
            }
        }
        if(temp==i){
            num[ans++] = i;
        }
    }
    return;
}

int main()
{
    fun1();
    int repeat;
    cin>>repeat;
    for(int i=0; i<repeat; i++){
        int m, n;
        cin>>m>>n;
        int j=0;
        for(j=0; j<ans; j++) {
            if(num[j]>=m&&num[j]<=n){
                cout<<num[j];
                break;
            }
        }
        for(j=j+1; j<ans; j++) {
            if(num[j]>=m&&num[j]<=n){
                cout<<' '<<num[j];
            }
        }
        cout<<endl;
    }
    return 0;
}
