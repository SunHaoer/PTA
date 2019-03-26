#include<cstdio>
using namespace std;
const int MAX = 10010;
int father[MAX];
bool isRoot[MAX], visited[MAX];

void init() {
    for(int i = 0; i < MAX; i++) {
        father[i] = i;
        isRoot[i] = false;
        visited[i] = false;
    }
}

int findFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void unionEle(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA < faB) {
        father[faB] = faA;
    } else {
        father[faA] = faB;
    }
}

int main()
{
    init();
    int n, m, t1, t2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &m, &t1);
        visited[t1] = true;
        for(int j = 1; j < m; j++) {
            scanf("%d", &t2);
            unionEle(t1, t2);
            visited[t2] = true;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= MAX; i++) {
        if(!visited[i]) {
            break;
        }
        isRoot[findFather(i)] = true;
        cnt++;
    }
    int ans = 0;
    for(int i = 1; i <= MAX; i++) {
        if(!visited[i]) break;
        if(isRoot[i]) ans++;
    }
    printf("%d %d\n", cnt, ans);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(father[a] == father[b]) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
