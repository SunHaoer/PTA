#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
set<int> st[100];
set<int> tempSt;
bool flag[1000];

int main()
{
    int n, m, num;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &num);
            st[i].insert(num);
        }
    }
    scanf("%d", &m);
    int a, b;
    double ans;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ans = 0;
        tempSt.clear();
        for(set<int>::iterator it1 = st[a].begin(), it2 = st[b].begin(); it1 != st[a].end() && it2 != st[b].end(); ) {
            if(*it1 == *it2) {
                ans++;
                it1++;
                it2++;
                tempSt.insert(*it1);
                tempSt.insert(*it2);
            } else if(*it1 < *it2) {
                tempSt.insert(*it1);
                it1++;
            } else {
                tempSt.insert(*it2);
                it2++;
            }
        }
        printf("%.2f%%\n", ans / tempSt.size() * 100);
    }
    return 0;
}

/*
 * 测试点4运行超时
 */
