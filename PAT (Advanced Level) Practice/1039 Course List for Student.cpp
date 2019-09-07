#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
map<string, vector<int> > table;

int main()
{
    int n, k;
    scanf("%d %d", &k, &n);     // 课程数n, 查询数k
    for(int i = 0; i < n; i++) {    // 输入
        int index, m;
        scanf("%d %d", &index, &m);     // 课程编号index, 选课学生数m
        for(int j = 0; j < m; j++) {
            string str;
            scanf("%s", str.c_str());
            table[str.c_str()].push_back(index);
        }
    }
    for(int i = 0; i < k; i++) {    // 查询
        string str;
        scanf("%s", str.c_str());
        printf("%s %d", str.c_str(), table[str.c_str()].size());
        sort(table[str.c_str()].begin(), table[str.c_str()].end());
        for(int j = 0; j < table[str.c_str()].size(); j++) {
            printf(" %d", table[str.c_str()][j]);
        }
        printf("\n");
    }
    return 0;
}
