#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 110;
vector<int> table[MAX];       // �ڽӱ�table
int leaf[MAX];          // ÿ��Ҷ�ӽڵ�ĸ���leaf
int level = 1;          // �������level(��������)

void DFS(int index, int h) {    // ��ǰ�ڵ���index, ���h
    level = max(level, h);              // levelΪ������, ����leaf��������
    if(table[index].size() == 0) {      // Ҷ��
        leaf[h]++;
        return;
    }
    for(int i = 0; i < table[index].size(); i++) {
        DFS(table[index][i], h + 1);
    }
}

int main()
{
    int n, m, k, parent , child;       // �ܽ����n, Ҷ����m, ÿ���ڵ��ӽڵ���k
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {       // ��ͼ
        scanf("%d%d", &parent, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            table[parent].push_back(child);
        }
    }
    DFS(1, 1);
    printf("%d", leaf[1]);
    for(int i = 2; i <= level; i++) {
        printf(" %d", leaf[i]);
    }
    return 0;
}
