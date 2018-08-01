#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100010;
bool visited[MAX];

struct Data {       // ͳ�Ƽ�ͥ������
    int id, fid, mid, num, area;
    int cid[10];
} data[MAX];

struct Node {       // ���ռ�ͥ������
    int id, people;
    double num, area;
    bool flag;
} ans[MAX];

int father[MAX];
void initFather() {
    for(int i = 0; i < MAX; i++) {
        father[i] = i;
    }
}

int findFather(int x) {     // Ѱ������
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


void Union(int a, int b) {      // �ϲ�
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA > faB) {             // ����С�ĺϲ�
        father[faA] = faB;
    } else if(faA < faB) {
        father[faB] = faA;
    }
}

bool cmp(Node a, Node b) {
    if(a.area != b.area) {
        return a.area > b.area;
    } else {
        return a.id < b.id;
    }
}

int main()
{
    initFather();
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {            // ������Ϣ
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        visited[data[i].id] = true;
        if(data[i].fid != -1) {
            visited[data[i].fid] = true;
            Union(data[i].id, data[i].fid);
        }
        if(data[i].mid != -1) {
            visited[data[i].mid] = true;
            Union(data[i].id, data[i].mid);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &data[i].cid[j]);
            visited[data[i].cid[j]] = true;
            Union(data[i].id, data[i].cid[j]);
        }
        scanf("%d %d", &data[i].num, &data[i].area);
    }

    for(int i = 0; i < n; i++) {        // �ϲ���
        int id = findFather(data[i].id);
        ans[id].id = id;
        ans[id].num += data[i].num;
        ans[id].area += data[i].area;
        ans[id].flag = true;
    }

    for(int i = 0; i < MAX; i++) {
        if(visited[i]) {                // ͳ��ÿ����ͥ������
            ans[findFather(i)].people++;
        }
        if(ans[i].flag) {               // ͳ�Ƽ�ͥ��
            cnt++;
        }
    }
    for(int i = 0; i < MAX; i++) {
        if(ans[i].flag) {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);        // �˾�������
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);      // �˾����
        }
    }
    sort(ans, ans + MAX, cmp);
    printf("%d\n", cnt);                    // ���
    for(int i = 0; i < cnt; i++) {
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    }
    return 0;
}

