#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

struct Node{
    int address;
    int key;
    int next;
}node[100010], L1[100010], L2[100010];

int main()
{
    int n, first, ans1 = 0, ans2 = 0;
    map<int, bool> flag;
    cin>>first>>n;
    int address;
    for(int i=0; i<n; i++){
        cin>>address;
        cin>>node[address].key>>node[address].next;
        node[address].address = address;
    }
    while(first!=-1){
        int key = abs(node[first].key);
        if(flag[key]==false){
            L1[ans1].address = node[first].address;
            L1[ans1].key = node[first].key;
            flag[key] = true;
            ans1++;
        }
        else{
            L2[ans2].address = node[first].address;
            L2[ans2].key = node[first].key;
            ans2++;
        }
        first = node[first].next;
    }
    for(int i=0; i<ans1-1; i++){
        printf("%05d %d %05d\n", L1[i].address, L1[i].key, L1[i+1].address);
    }
    printf("%05d %d -1\n", L1[ans1-1].address, L1[ans1-1].key);
    if(ans2==0) return 0;
    for(int i=0; i<ans2-1; i++){
        printf("%05d %d %05d\n", L2[i].address, L2[i].key, L2[i+1].address);
    }
    printf("%05d %d -1", L2[ans2-1].address, L2[ans2-1].key);
    return 0;
}
