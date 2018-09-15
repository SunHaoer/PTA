#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 110;

bool cmp(int a, int b){
    return a > b;
}

void print(int num[], int n){
    cout<<num[0];
    for(int i=1; i<n; i++){
        cout<<" "<<num[i];
    }
    cout<<endl;
    return;
}

int main()
{
    int n;
    while(cin>>n){
        int num[MAX];
        for(int i=0; i<n; i++){
            cin>>num[i];
        }
        sort(num, num+n, cmp);
        print(num, n);
    }
    return 0;
}
