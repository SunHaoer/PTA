#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int MAX = 1000010;
int pre[MAX], in[MAX], post[MAX];
int table[MAX];
int n, m;
map<int, bool> mp;

bool isExist[MAX], table2[MAX];
void fun2(int index1, int index2, int a, int b) {
    fill(isExist, isExist + MAX, false);
    for(int i = index1; i <= index2; i++) {
        isExist[in[i]] = true;
    }
    for(int i = 0; i < n; i++) {
        if(pre[i] == a) {
            printf("%d is an ancestor of %d.\n", a, b);
        } else if(pre[i] == b) {
            printf("%d is an ancestor of %d.\n", b, a);
        } else if(isExist[pre[i]]) {
            printf("LCA of %d and %d is %d.\n", a, b, pre[i]);
        } else {
            continue;
        }
        return;
    }
}

int main()
{
    fill(table, table + MAX, -1);
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        table[in[i]] = i;
        mp[in[i]] = true;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(!mp[a] && !mp[b] ) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if(!mp[a]) {
            printf("ERROR: %d is not found.\n", a);
        } else if(!mp[b]) {
            printf("ERROR: %d is not found.\n", b);
        } else {
            int index1 = min(table[a], table[b]);
            int index2 = max(table[a], table[b]);
            fun2(index1, index2, a, b);
        }
    }
    return 0;
}
