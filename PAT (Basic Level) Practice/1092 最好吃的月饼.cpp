#include<cstdio>
#include<set>
#include<vector>
using namespace std;
const int MAX = 1010;
int table[MAX][MAX];

int main()
{
    int n, m, num, ans[MAX];
    fill(ans, ans + MAX, 0);
    int maxn = -1;
    set<int> maxId;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {    // 遍历城市
        for(int j = 0; j < n; j++) {    // 遍历种类
            scanf("%d", &num);
            ans[j + 1] += num;
            if(ans[j + 1] > maxn) {
                maxn = ans[j + 1];
                maxId.clear();
                maxId.insert(j + 1);
            } else if(ans[j + 1] == maxn) {
                maxId.insert(j + 1);
            }
        }
    }
    vector<int> vec;
    printf("%d\n", maxn);
    for(set<int>::iterator it = maxId.begin(); it != maxId.end(); it++) {
        vec.push_back(*it);
    }
    for(int i = 0; i < vec.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", vec[i]);
    }
    return 0;
}
