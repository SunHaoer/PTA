#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int E, n, days[N];
    cin>>n;
    for(int i = 1; i < n + 1; i++) {
        cin>>days[i];
    }
    sort(days + 1, days + n + 1, cmp);
    for(int i = 1; i < n + 1; i++) {
        if(i < days[i]) {
            E = i;
        }
    }
    cout<<E<<endl;
    return 0;
}

/*
ÕâÌâ25·Ö£¿£¿
*/
