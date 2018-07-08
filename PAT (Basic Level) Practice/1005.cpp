#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    map<int, bool> m;
    int n, ans = 0, num[110], temp[110], arr[110];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>num[i];
        temp[i] = num[i];
        while(num[i] != 1){
            if(num[i] % 2 == 0){          // 偶数
                num[i] /= 2;
            } else{                       // 奇数
                num[i] = (num[i] * 3 + 1 ) / 2;
            }
            m[num[i]] = true;             // 这个数出现了
        }
    }
    for(int i = 0; i < n; i++){
        if(m[temp[i]] == false){
            arr[ans++] = temp[i];
        }
    }
    sort(arr, arr + ans);
    for(int i = ans - 1; i > 0; i--){
        cout<<arr[i]<<' ';
    }
    cout<<arr[0];
    return 0;
}
