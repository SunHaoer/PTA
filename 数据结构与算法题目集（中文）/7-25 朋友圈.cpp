#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 30000;
int father[MAX];
int friendSize[MAX];

void init(int n) {                  // 初始化
    for(int i = 0; i <= n; i++) {
        father[i] = i;
        friendSize[i] = 0;
    }
}

int findFather(int x) {             // 寻找父亲节点
    int a = x;
    while(father[x] != x) {
        x = father[x];
    }
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void union(int a, int b) {          // 合并
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) father[faA] = faB;
}

int main()
{
    int n, m, maxn = 0;
    scanf("%d%d", &n, &m);
    init(n);
    for(int i = 0; i < m; i++) {
        int k, temp[MAX];
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &temp[j]);
        }
        for(int j = 1; j < k; j++) {
            union(temp[j - 1], temp[j]);
        }
    }
    for(int i = 1; i <= n; i++) {       // 找出根节点
        friendSize[findFather(i)]++;
    }
    for(int i = 1; i <= n; i++) {
        maxn = max(maxn, friendSize[i]);
    }
    printf("%d\n", maxn);
    return 0;
}
