#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 10010;
vector<int> table[MAX];
vector<int> tempTable[MAX];
int n, m;

void fun1() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < table[i].size(); j++) {
            tempTable[i].push_back(table[i][j]);
        }
    }
}

void fun2(int node) {
    tempTable[node].clear();
}

void fun4(int node) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < tempTable[i].size(); ) {
            if(tempTable[i][j] == node) tempTable[i].erase(tempTable[i].begin() + j);
            else j++;
        }
    }
}

bool fun3() {
    for(int i = 0; i <= n; i++) {
        if(tempTable[i].size() != 0) return false;
    }
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        table[a].push_back(b);
        table[b].push_back(a);
    }
    int repeat, tempNode, arr[MAX];
    scanf("%d", &repeat);
    for(int i = 0; i < repeat; i++) {
        fun1();
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[j]);
            fun2(arr[j]);
        }
        for(int j = 0; j < m; j++) {
            fun4(arr[j]);
        }
        if(fun3()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

/*
 * 邻接表运行超时
 */
