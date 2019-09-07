#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 100010;

struct node{
    char data;
    int next;
    bool flag;          //节点是否在第一条链表上
}node[MAX];

int main()
{
    for(int i=0; i<MAX; i++){
        node[i].flag = false;
    }
    int s1, s2, n;
    scanf("%d %d %d", &s1, &s2, &n);           //输入两条链表的首地址,节点个数n
    int address, next;          //节点地址和后继节点地址
    char data;
    for(int i=0; i<n; i++){
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }
    int p;
    for(p=s1; p!=-1; p=node[p].next){
        node[p].flag = true;
    }
    for(p=s2; p!=-1; p=node[p].next){
        if(node[p].flag==true) break;
    }
    if(p!=-1){
        printf("%05d\n", p);
    }
    else{
        printf("-1\n");
    }
    return 0;
}
