#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<string, int> mp;

int main()
{
    int n, k, m;
    string id;
    cin>>n>>k;
    for(int i = 0; i < n; i++) {
        int dis;
        id.resize(100);             // 需要预先分配空间
        scanf("%s%d", &id[0], &dis);
        if(dis < k) dis = k;        // dis<k按k计算
        mp[id.c_str()] += dis;      // 用id.c_str()表示id
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%s", &id[0]);
        if(mp[id.c_str()] != 0) printf("%d\n", mp[id.c_str()]);
        else printf("No Info\n");
    }
    return 0;
}


/*
 *  cin运行超时, 用scanf读入string
 */
