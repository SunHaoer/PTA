#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int MAX = 10010;
int hashTable[MAX][MAX] = { 0 };
bool visited[MAX] = { false };
int n, m, ans = 0, layer = 0;       // �ڵ���n, ����m, ��ؽڵ���ans, ����layer

void BFS(int x) {       // �������
    queue<int> q;
    int last = x;       // ��һ���ڵ�
    int tail = 0;       // β��
    q.push(x);
    visited[x] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(hashTable[now][i] == 1 && visited[i] == false) {
                ans++;
                tail = i;
                visited[i] = true;
                q.push(i);
            }
        }
        if(now == last) {               // lastֻ���ܴ�ǰ����, ��for��x�ķ���
            layer++;
            last = tail;
        }
        if(layer == 6) break;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        hashTable[v1][v2] = 1;
        hashTable[v2][v1] = 1;
    }
    for(int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        ans = 0;
        layer = 0;
        BFS(i);
        printf("%d: %.2f%%\n", i, (ans + 1) * 1.0 / n * 100);
    }
    return 0;
}
