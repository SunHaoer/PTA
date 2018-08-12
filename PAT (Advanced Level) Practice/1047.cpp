#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 2510;
vector<string> table[MAX];

int main()
{
    int n, k, m;        // 总人数n, 总课程数k, 担任选课数m
    string name;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        name.resize(4);
        scanf("%s%d", &name[0], &m);
        for(int j = 0; j < m; j++) {
            int id;
            scanf("%d", &id);
            table[id].push_back(name);
        }
    }
    for(int i = 1; i <= k; i++) {
        sort(table[i].begin(), table[i].end());
        printf("%d %d\n", i, table[i].size());
        for(int j = 0; j < table[i].size(); j++) {
            printf("%s\n", table[i][j].c_str());
        }
    }
    return 0;
}
