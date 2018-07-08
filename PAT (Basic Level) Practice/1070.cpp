#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a < b;
}

int main()
{
    int num, n[10001];
    int len = 0;
    cin>>num;
    for(int i = 0; i < num; i++) {
        cin>>n[i];
    }
    sort(n, n + num, cmp);
    len = n[0];
    for(int i = 1; i < num; i++) {
        len = (len + n[i]) / 2;
    }
    cout<<len<<endl;
    return 0;
}


/*
*  从小到大顺序对折
*/
