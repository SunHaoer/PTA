#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    long long tel = 0;
    int maxNum = 0, maxPeo = 0;
    long long maxTel = 0;
    map<long long, int> m;
    cin>>n;
    for(int i = 0; i < n * 2; i++) {
        cin>>tel;
        m[tel]++;
        if(m[tel] > maxNum) {
            maxPeo = 1;
            maxNum = m[tel];
            maxTel = tel;
        } else if(m[tel] == maxNum) {
            maxPeo++;
            if(tel < maxTel) {
                maxNum = m[tel];
                maxTel = tel;
            }
        }
    }
    cout<<maxTel<<" "<<maxNum;
    if(maxPeo != 1) cout<<" "<<maxPeo;
    cout<<endl;
    return 0;
}
