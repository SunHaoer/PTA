#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 225;

struct Country {
    int id;            // 编号
    double gold;       // 金牌
    double medal;      // 奖牌
    double peo;        // 人数
    double gold_peo;   // 人均金牌
    double medal_peo;  // 人均奖牌
    int ranked[5];     // 排名
    int rankId;        // 最高排名编号
} cou[MAX], result[MAX];

bool cmp1(Country cou1, Country cou2) {
    return cou1.gold > cou2.gold;
}

bool cmp2(Country cou1, Country cou2) {
    return cou1.medal > cou2.medal;
}

bool cmp3(Country cou1, Country cou2) {
    return cou1.gold_peo > cou2.gold_peo;
}

bool cmp4(Country cou1, Country cou2) {
    return cou1.medal_peo > cou2.medal_peo;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf%lf", &cou[i].gold, &cou[i].medal, &cou[i].peo);
        cou[i].gold_peo = cou[i].gold / cou[i].peo;
        cou[i].medal_peo = cou[i].medal / cou[i].peo;
        cou[i].ranked[0] = MAX;
        cou[i].id = i;
        result[i] = cou[i];
    }
    sort(cou, cou + n, cmp1);
    cou[0].ranked[1] = 1;
    for(int i = 1; i < n; i++) {
        if(cou[i].gold == cou[i - 1].gold) {
            cou[i].ranked[1] = cou[i - 1].ranked[1];
        } else {
            cou[i].ranked[1] = i + 1;
        }
    }
    sort(cou, cou + n, cmp2);
    cou[0].ranked[2] = 1;
    for(int i = 1; i < n; i++) {
        if(cou[i].medal == cou[i - 1].medal) {
            cou[i].ranked[2] = cou[i - 1].ranked[2];
        } else {
            cou[i].ranked[2] = i + 1;
        }
    }
    sort(cou, cou + n, cmp3);
    cou[0].ranked[3] = 1;
    for(int i = 1; i < n; i++) {
        if(cou[i].gold_peo == cou[i - 1].gold_peo) {
            cou[i].ranked[3] = cou[i - 1].ranked[3];
        } else {
            cou[i].ranked[3] = i + 1;
        }
    }
    sort(cou, cou + n, cmp4);
    cou[0].ranked[4] = 1;
    for(int i = 1; i < n; i++) {
        if(cou[i].medal_peo == cou[i - 1].medal_peo) {
            cou[i].ranked[4] = cou[i - 1].ranked[4];
        } else {
            cou[i].ranked[4] = i + 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < 5; j++) {
            cou[i].ranked[0] = min(cou[i].ranked[0], cou[i].ranked[j]);
        }
        for(int j = 1; j < 5; j++) {
            if(cou[i].ranked[j] == cou[i].ranked[0]) {
                cou[i].rankId = j;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        result[cou[i].id] = cou[i];
    }
    for(int i = 0; i < m; i++) {
        int index;
        scanf("%d", &index);
        printf("%d:%d", result[index].ranked[0], result[index].rankId);
        if(i != m - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}
