#include<iostream>
#include<cmath>
using namespace std;
int num[100010], ans = 0;

void isPrime(int n){                // 计算出0-n的所有素数
    for(int i = 2; i <= n; i++){
        int flag = 0;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j==0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            num[ans++] = i;
        }
    }
}

int main()
{
    int n, temp = 0;
    cin>>n;
    isPrime(n);
    for(int i = 0; i < ans; i++){
        if( (num[i + 1] - num[i] == 2) && (i + 1 < ans) ) temp++;
    }
    cout<<temp;
    return 0;
}
