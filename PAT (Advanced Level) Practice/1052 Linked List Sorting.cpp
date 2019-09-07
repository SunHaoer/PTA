#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100010;

struct Node{
    int address;
    int data;
    int next;
}node[MAX], L[MAX];

bool cmp(Node a, Node b){
    return a.data<b.data;
}

int main()
{
    int n, first, ans = 0;
    cin>>n>>first;
    int address;
    for(int i=0; i<n; i++){
        cin>>address;
        cin>>node[address].data>>node[address].next;
        node[address].address = address;
    }
    address = first;
    while(address!=-1){
        L[ans].address = address;
        L[ans].data = node[address].data;
        address = node[address].next;
        ans++;
    }
    if(ans==0){
        cout<<"0 -1\n";
        return 0;
    }
    sort(L, L+ans, cmp);
    printf("%d %05d\n", ans, L[0].address);
    for(int i=0; i<ans-1; i++){
        printf("%05d %d %05d\n", L[i].address, L[i].data, L[i+1].address);
    }
    printf("%05d %d -1\n",L[ans-1].address, L[ans-1].data);
    return 0;
}
