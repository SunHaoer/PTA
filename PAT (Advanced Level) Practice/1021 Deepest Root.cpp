#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 10010;
vector<int> table[MAX];         // �ڽӱ�
int father[MAX];        // ���ڲ��鼯�ĸ��׵Ľڵ�
bool isRoot[MAX];       // ���ڵ�
int maxH = 0;   // ���߶�
vector<int> temp, ans;      // ��ʱ�����Զ��temp�� ��ans
int n;          // �ڵ���

void init() {           // ��ʼ��
    for(int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int findFather(int x) {            // Ѱ�Ҹ��׽ڵ�
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != father[a]) {         // ѹ��·��
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {          // ���鼯
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faA] = faB;
    }
}

int calBlock() {               // ������ͨ��
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        isRoot[findFather(i)] = true;
    }
    for(int i = 1; i <= n; i++) {
        ans += isRoot[i];
    }
    return ans;
}

void DFS(int u, int height, int pre) {
    if(height > maxH) {         // �������߶�
        temp.clear();
        temp.push_back(u);
        maxH = height;
    } else if(height == maxH) {     // ��ӷ��ϵĽڵ�
        temp.push_back(u);
    }
    for(int i = 0; i < table[u].size(); i++) {
        if(table[u][i] == pre) continue;
        DFS(table[u][i], height + 1, u);
    }
}

int main()
{
    scanf("%d", &n);
    init();
    for(int i = 0; i < n - 1; i++) {        // ��ͼ
        int a, b;
        scanf("%d%d", &a, &b);
        table[a].push_back(b);
        table[b].push_back(a);
        Union(a, b);
    }
    int num = calBlock();          // ������ͨ����
    if(num != 1) {      // ����ͨ��
        printf("Error: %d components\n", num);
    } else {            // ��ͨ��, ����ڵ�
        DFS(1, 1, -1);
        ans = temp;
        DFS(ans[0], 1, -1);
        for(int i = 0; i < temp.size(); i++) {      // ������ڵ�Ϊ�������ϵĲ���
            ans.push_back(temp[i]);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] != ans[i - 1]) {
                printf("%d\n", ans[i]);
            }
        }
    }
    return 0;
}
