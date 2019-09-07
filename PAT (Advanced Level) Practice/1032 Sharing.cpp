#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 100010;

struct node{
    char data;
    int next;
    bool flag;          //�ڵ��Ƿ��ڵ�һ��������
}node[MAX];

int main()
{
    for(int i=0; i<MAX; i++){
        node[i].flag = false;
    }
    int s1, s2, n;
    scanf("%d %d %d", &s1, &s2, &n);           //��������������׵�ַ,�ڵ����n
    int address, next;          //�ڵ��ַ�ͺ�̽ڵ��ַ
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
