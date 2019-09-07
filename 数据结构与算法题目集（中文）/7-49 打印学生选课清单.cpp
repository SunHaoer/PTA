#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 26 * 26 * 26 * 10 + 1;
int table1[MAX];           // name->id
vector<int> table2[MAX];         // id->course

int fun1(char name[]) {
    for(int i = 0; i < 4; i++) {
        return ( (name[0] - 'A') * 10 * 26 * 26 + (name[1] - 'A') * 10 * 26 + (name[2] - 'A') * 10 + (name[3] - '0') );
    }
}

int main()
{
    int n, k, id, m, ans = 1;       // ѧ����n, �γ���k, �γ̱��id, ÿ�ſ�����m, ������ans
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++) {       // �γ̱�Ŵ�1��ʼ
        scanf("%d %d", &id, &m);
        for(int j = 0; j < m; j++) {
            char name[4];
            scanf("%s", &name);
            int index = fun1(name);
            if(table1[index] == 0) table1[index] = ans++;
            table2[table1[index]].push_back(id);           // ��id�����Ӧ��table
        }
    }
    bool flag[MAX] = { false };
    for(int i = 0; i < n; i++) {
        char name[4];
        scanf("%s", name);
        int index = fun1(name);
        if(!flag[table1[index]]) {                        // �Ѿ�����Ĳ�������
            sort(table2[table1[index]].begin(), table2[table1[index]].end());
        }
        flag[table1[index]] = true;
        printf("%s %d", name, table2[table1[index]].size());
        for(int j = 0; j < table2[table1[index]].size(); j++) {
            printf(" %d", table2[table1[index]][j]);
        }
        printf("\n");
    }
    return 0;
}


/*
 * ��Ϊ���Ե�5�����г�ʱ, ��дmap��Ҳ�ǲ����׵ġ�����
 */

