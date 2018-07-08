#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 1010;
vector<int> table[MAX];     // �ڽӱ�
int father[MAX];
bool visited[MAX];
int n, m, k;        // �ڵ���n, ����m, ��ѯ��k

void init() {       // ��ʼ��
    for(int i = 1; i <= MAX; i++) {
        father[i] = i;
        visited[i] = false;
    }
}

int findFather(int x) {
    int a = x;
    while(x != father[x]) {     // Ѱ�Ҹ��ڵ�
        x = father[x];
    }
    while(a != father[a]) {     // ѹ��·��
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {      // �ϲ�a, b����
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faA] = faB;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {    // ��ͼ
        int a, b;
        scanf("%d%d", &a, &b);
        table[a].push_back(b);
        table[b].push_back(a);
    }
    int dis;       // ɾ���Ľڵ�
    for(int l = 0; l < k; l++) {
        scanf("%d", &dis);
        init();
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < table[i].size(); j++) {
                int u = i, v = table[i][j];         // �ߵ������˵�u, v
                if(u == dis || v == dis) continue;  // ����ɾ���Ľڵ�
                Union(u, v);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {       // �������нڵ�
            if(i == dis) continue;
            int fa_i = findFather(i);       // ����i�ĸ��ڵ�
            if(visited[fa_i] == false) {
                ans++;
                visited[fa_i] = true;
            }
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
