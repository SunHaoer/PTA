#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 100010;
vector<int> table[MAX];
int n, temp, root;

struct People {
    int data, level;
    People(int _data, int _level) {
        data = _data;
        level = _level;
    }
};

int maxLevel = -1;
vector<int> vec;
void bfs() {
    queue<People> q;
    q.push(People(root, 1));
    while(!q.empty()) {
        People now = q.front();
        //maxLevel = max(maxLevel, now.level);
        if(now.level > maxLevel) vec.clear();
        vec.push_back(now.data);
        maxLevel = now.level;
        q.pop();
        for(int i = 0; i < table[now.data].size(); i++) {
            q.push(People(table[now.data][i], now.level + 1));
        }
    }
    printf("%d\n", maxLevel);
    for(int i = 0; i < vec.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", vec[i]);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        table[temp].push_back(i);
        if(temp == -1) root = i;
    }
    //printf("%d\n", root);
    bfs();
    return 0;
}
