#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a < b;
}

int main()
{
    long long num, p, n[100001], temp = 0, maxn = 0;
    cin>>num>>p;
    for(int i = 0; i < num; i++) {
        cin>>n[i];
    }
    sort(n, n + num, cmp);                     // 从小到大排序
    for(int i = 0; i < num; i++) {             // 最小值为n[i],最大值为n[j]
        for(int j = i + temp; j < num; j++) {
            if(n[i] * p >= n[j]) {             // 符合
                temp = j - i + 1;
                if(temp > maxn) {              // 更新最大值
                    maxn = temp;
                }
            } else {
                break;
            }
        }
    }
    cout<<maxn<<endl;
    return 0;
}
