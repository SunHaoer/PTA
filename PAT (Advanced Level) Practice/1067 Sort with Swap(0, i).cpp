#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100010;
int pos[MAX];       //��Ÿ����ֵ�ǰ�ı��

int main()
{
    int n, ans = 0;
    cin>>n;
    int left = n - 1, num;      //left��ų�0�ⲻ�ڱ�λ�����ĸ���
    for(int i=0; i<n; i++){
        cin>>num;
        pos[num] = i;
        if(num==i&&num!=0){
            left--;
        }
    }
    int k = 1;      //k�ų�0�⵱ǰ���ڱ�λ����С��
    while(left>0){
        if(pos[0]==0){
            while(k<n){
                if(pos[k]!=k){
                    swap(pos[0], pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while(pos[0]!=0){
            swap(pos[0], pos[pos[0]]);
            ans++;
            left--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
