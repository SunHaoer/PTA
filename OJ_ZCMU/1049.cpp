#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 110;

struct Fish{
    int weight;
    int rankn;
}fish[MAX];

bool cmp(Fish a, Fish b){
    return a.weight > b.weight;
}

int main()
{
    int n;
    while(cin>>n){
        int ans = 0;
        for(int i=0; i<n; i++){
            cin>>fish[i].weight;
        }
        sort(fish, fish+n, cmp);
        fish[0].rankn = 1;
        for(int i=1; i<n; i++){
            if(fish[i].weight==fish[i-1].weight) fish[i].rankn = fish[i-1].rankn;
            else fish[i].rankn = fish[i-1].rankn + 1;
            if(fish[i].rankn==5) ans++;
            if(fish[i].rankn>=6) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
