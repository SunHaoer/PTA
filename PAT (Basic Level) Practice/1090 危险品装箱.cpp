#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int, vector<int> > mp;
const int MAX = 100100;
bool table[MAX];


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {    // 输入
        int a, b;
        scanf("%d %d", &a, &b);
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i = 0; i < m; i++) {
        int k;
        bool flag = true;
        scanf("%d", &k);
        fill(table, table + MAX, false);
        for(int j = 0; j < k; j++) {
            int index;
            scanf("%d", &index);
            if(table[index]) {
                flag = false;
            }
            if(!flag) continue;
            for(int t = 0; t < mp[index].size(); t++) {
                table[mp[index][t]] = true;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
