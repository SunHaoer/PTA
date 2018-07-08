#include<iostream>
#include<cmath>
using namespace std;
int prime[10001], ans = 0;

void isprime(){
    int i = 1;
    while(ans < 10010){
        int flag = 0;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0) prime[ans++] = i;
        i++;
    }
    return;
}

int main()
{
    int m, n;
    cin>>m>>n;
    isprime();             // 计算出所有素数
    for(int i = m; i <= n; i++){
        cout<<prime[i];
        if(i == n) break;
        else if((i + 1 - m) % 10 == 0) cout<<endl;
        else cout<<" ";
    }
    return 0;
}
