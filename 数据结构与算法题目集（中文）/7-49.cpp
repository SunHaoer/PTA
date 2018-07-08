#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 26 * 26 * 26 * 10 + 1;
int table1[MAX];           // name->id
vector<int> table2[MAX];         // id->course

int fun1(char name[]) {
    for(int i = 0; i < 4; i++) {
        return ( (name[0] - 'A') * 10 * 26 * 26 + (name[1] - 'A') * 10 * 26 + (name[2] - 'A') * 10 + (name[3] - '0') );
    }
}

int main()
{
    int n, k, id, m, ans = 1;       // 学生数n, 课程数k, 课程编号id, 每门课人数m, 计数器ans
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++) {       // 课程编号从1开始
        scanf("%d %d", &id, &m);
        for(int j = 0; j < m; j++) {
            char name[4];
            scanf("%s", &name);
            int index = fun1(name);
            if(table1[index] == 0) table1[index] = ans++;
            table2[table1[index]].push_back(id);           // 把id存入对应的table
        }
    }
    bool flag[MAX] = { false };
    for(int i = 0; i < n; i++) {
        char name[4];
        scanf("%s", name);
        int index = fun1(name);
        if(!flag[table1[index]]) {                        // 已经排序的不再排序
            sort(table2[table1[index]].begin(), table2[table1[index]].end());
        }
        flag[table1[index]] = true;
        printf("%s %d", name, table2[table1[index]].size());
        for(int j = 0; j < table2[table1[index]].size(); j++) {
            printf(" %d", table2[table1[index]][j]);
        }
        printf("\n");
    }
    return 0;
}


/*
 * 因为测试点5的运行超时, 手写map我也是不容易的。。。
 */

