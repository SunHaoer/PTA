#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100010;
int sch[MAX] = { 0 };               // sch[id] = score

int main()
{
    int n, id, score, maxs = -1, maxid = -1;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>id>>score;
        sch[id] += score;
    }
    for(int i = 1; i <= n; i++) {
        maxs = max(maxs, sch[i]);
        if(maxs == sch[i]) maxid = i;
    }
    cout<<maxid<<' '<<maxs<<endl;
    return 0;
}
