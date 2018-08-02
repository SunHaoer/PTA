#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 10010;
bool exist[MAX];
int father[MAX];
int cnt = 0;

struct Data {       // 录入的数据
    int id, fid, mid, k;
    int cid[6];
    double num, area;
} data[MAX];

struct Family {
    int id, k;
    double num, area;
    double avgNum, avgArea;
    bool visited;
} family[MAX];

void init() {
    for(int i = 0; i < MAX; i++) {
        father[i] = i;
    }
}

int findFather(int x) {
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

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA < faB) {
        father[faB] = faA;
    }
    if(faB < faA) {
        father[faA] = faB;
    }
}

bool cmp1(Family a, Family b) {
    if(a.area != b.area) {
        return a.area > b.area;
    } else {
        return a.id < b.id;
    }
}

bool cmp2(Family a, Family b) {
    if(a.avgArea != b.avgArea) {
        return a.avgArea > b.avgArea;
    } else {
        return a.id < b.id;
    }
}

int main()
{
    init();
    int n;       // 总家庭数n, 家庭孩子数k
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {        // 输入数据, 合并集合
        scanf("%d %d %d %d", &data[i].id, &data[i].fid , &data[i].mid, &data[i].k);
        exist[data[i].id] = true;
        if(data[i].fid != -1) {
            Union(data[i].id, data[i].fid);
            exist[data[i].fid] = true;
        }
        if(data[i].mid != -1) {
            Union(data[i].id, data[i].mid);
            exist[data[i].mid] = true;
        }
        for(int j = 0; j < data[i].k; j++) {
            scanf("%d", &data[i].cid[j]);
            Union(data[i].id, data[i].cid[j]);
            exist[data[i].cid[j]] = true;
        }
        scanf("%lf %lf", &data[i].num, &data[i].area);
    }
    for(int i = 0; i < n; i++) {        // 统计
        int id = findFather(data[i].id);
        family[id].id = id;
        family[id].num += data[i].num;
        family[id].area += data[i].area;
        if(!family[id].visited) {
            cnt++;
        }
        family[id].visited = true;
    }
    for(int i = 0; i < MAX; i++) {      // 统计每个家庭人数
        if(exist[i]) {
            family[findFather(i)].k++;
        }
    }
    sort(family, family + MAX, cmp1);
    for(int i = 0; i < cnt; i++) {          // 计算
        family[i].avgNum = double(family[i].num / family[i].k);
        family[i].avgArea = double(family[i].area / family[i].k);
    }
    sort(family, family + cnt, cmp2);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {          // 输出
        printf("%04d %d %.3lf %.3lf\n", family[i].id, family[i].k, family[i].avgNum, family[i].avgArea);
    }
    return 0;
}
