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
        id.resize(100);             // ��ҪԤ�ȷ���ռ�
        scanf("%s%d", &id[0], &dis);
        if(dis < k) dis = k;        // dis<k��k����
        mp[id.c_str()] += dis;      // ��id.c_str()��ʾid
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
 *  cin���г�ʱ, ��scanf����string
 */
