#include<cstdio>
using namespace std;
const int MAX = 10010;
bool exist[MAX], visited[MAX];
int tree = 0, bird = 0;

int father[MAX];
void init() {                   // 初始化
    for(int i = 0; i < MAX; i++) {
        father[i] = i;
    }
}

int findFather(int x) {         // 寻找父亲节点
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

void Union(int a, int b) {      // 合并集合
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faB] = faA;
    }
}

int main()
{
    init();
    int n, k, b1, b2, q;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {        // 输入
        scanf("%d", &k);
        scanf("%d", &b1);
        exist[b1] = true;
        for(int j = 1; j < k; j++) {
            scanf("%d", &b2);
            Union(b1, b2);
            exist[b2] = true;
        }
    }
    for(int i = 0; i < MAX; i++) {      // 统计
        if(exist[i]) {
            bird++;
            if(!visited[findFather(i)]) {
                tree++;
                visited[findFather(i)] = true;
            }
        }
    }
    printf("%d %d\n", tree, bird);
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {        // 输入查询信息
        scanf("%d %d", &b1, &b2);
        if(findFather(b1) == findFather(b2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
