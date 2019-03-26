#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 100010;
int n;
double z, r;

struct People {
    int index, leafAns;
    bool isRoot, isLeaf;
    vector<int> child;
    People() {
        leafAns = 0;
        isRoot = true;
    }
} peo[MAX];

double cnt = 0;
void fun1(int now, double ans) {
    if(peo[now].isLeaf) {
        cnt += ans * peo[now].leafAns;
    } else {
        ans *= (1 - r / 100.0);
        for(int i = 0; i < peo[now].child.size(); i++) {
            fun1(peo[now].child[i], ans);
        }
    }
}

int main()
{
    int m;
    scanf("%d %lf %lf", &n, &z, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        peo[i].index = i;
        if(m == 0) {
            peo[i].isLeaf = true;
            scanf("%d", &peo[i].leafAns);
        }
        for(int j = 0; j < m; j++) {
            int node;
            scanf("%d", &node);
            peo[i].child.push_back(node);
            peo[node].isRoot = false;
        }
    }
    int root = -1;
    for(int i = 0; i < n; i++) {
        if(peo[i].isRoot) {
            root = i;
        }
    }
    fun1(root, z);
    printf("%d\n", int(cnt));
    return 0;
}
