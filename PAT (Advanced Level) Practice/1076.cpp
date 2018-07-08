#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 1010;
vector<int> table[MAX];
bool visited[MAX];
int n, level, numQuery;       // �ڵ���n, ���Ʋ���level, ��ѯ����numQuery

int BFS(int x) {
    int ans = 0;
    queue<int> q;
    int last = x;       // ��һ���ڵ�
    int tail = 0;       // β�ͽڵ�
    int layer = 0;      // ����
    q.push(x);
    visited[x] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 0; i < table[now].size(); i++) {
            if(visited[table[now][i]] == false) {        // δ������, ���ڹ涨��Χ��
                ans++;
                tail = table[now][i];
                q.push(table[now][i]);
                visited[table[now][i]] = true;
            }
        }
        if(now == last) {
            layer++;
            last = tail;
        }
        if(layer == level) break;
    }
    return ans;
}


int main()
{
    scanf("%d%d", &n, &level);
    for(int i = 1; i <= n; i++) {
        int m, id;      // ��ע����m, ��ע��Id
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &id);
            table[id].push_back(i);
        }
    }
    scanf("%d", &numQuery);
    for(int i = 0; i < numQuery; i++) {
        fill(visited, visited + MAX, false);
        int id;
        scanf("%d", &id);
        int ans = BFS(id);
        printf("%d\n", ans);
    }
    return 0;
}
