#include<iostream>
using namespace std;

int main()
{
    int n, ans = 0;
    cin>>n;
    while(n != 1){
        if(n % 2 == 0){     //ż��
            n /= 2;
        } else if(n % 2 == 1){     //����
            n = ( 3 * n + 1) / 2;
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

