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
    sort(n, n + num, cmp);                     // ��С��������
    for(int i = 0; i < num; i++) {             // ��СֵΪn[i],���ֵΪn[j]
        for(int j = i + temp; j < num; j++) {
            if(n[i] * p >= n[j]) {             // ����
                temp = j - i + 1;
                if(temp > maxn) {              // �������ֵ
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
