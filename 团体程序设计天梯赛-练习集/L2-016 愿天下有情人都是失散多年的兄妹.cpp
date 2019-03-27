#include<iostream>
using namespace std;
const int MAX = 100010;
bool visited[MAX];
bool flag = true;

struct Node {
    int index, fid, mid;
    char sex;
} node[MAX];

void fun2(int now, int ans) {
    if(ans == 5) return;
    if(now == 0) return;
    if(visited[now]) {
        flag = false;
        return;
    }
    visited[now] = true;
    if(node[now].fid > 0) fun2(node[now].fid, ans + 1);
    if(node[now].mid > 0) fun2(node[now].mid, ans + 1);
}

void fun1(int a, int b) {
    fill(visited, visited + MAX, false);
    flag = true;
    fun2(a, 0);
    fun2(b, 0);
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int index;
        cin>>index;
        node[index].index = index;
        cin>>node[index].sex>>node[index].fid>>node[index].mid;
        node[node[index].fid].sex = 'M';
        node[node[index].mid].sex = 'F';
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(node[a].sex == node[b].sex) cout<<"Never Mind"<<endl;
        else fun1(a, b);
    }
    return 0;
}

/*
 * 测试点1,3,4与输入的父母性别有关
 */
