#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 10010;
vector<int> edge[MAX];
bool visited[MAX];

int main()
{
    int n, m, k;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {    // 输入
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a].push_back(i);
        edge[b].push_back(i);
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {    // 查询
        fill(visited, visited + MAX, false);
        int nv, v;
        scanf("%d", &nv);
        for(int j = 0; j < nv; j++) {
            scanf("%d", &v);
            for(int t = 0; t < edge[v].size(); t++) {
                visited[edge[v][t]] = true;
            }
        }
        bool flag = true;
        for(int j = 0; j < m; j++) {    // 判断是否有未访问边
            if(!visited[j]) {
                flag = false;
                break;
            }
        }
        if(flag) printf("Yes\n");       // 输出
        else printf("No\n");
    }
    return 0;
}
