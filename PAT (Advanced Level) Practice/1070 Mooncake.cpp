#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct MoonCack{
    double store, sell, price;      //���, �ܼ�, ����
}moon[1010];

bool cmp(MoonCack a, MoonCack b){
    return a.price > b.price;
}

int main()
{
    int n, d;
    double ans = 0;
    scanf("%d%d", &n, &d);
    for(int i=0; i<n; i++){     //������
        scanf("%lf", &moon[i].store);
    }
    for(int i=0; i<n; i++){     //�����ܼ�, ���㵥��
        scanf("%lf", &moon[i].sell);
        moon[i].price = moon[i].sell / moon[i].store;
    }
    sort(moon, moon+n, cmp);
    int i = 0;
    while(d>=moon[i].store){
        ans += moon[i].sell;
        d -= moon[i].store;
        i++;
        if(i>n){                //�±�����
            printf("%.2f", ans);
            return 0;
        }
    }
    ans += (d * moon[i].price );
    printf("%.2f", ans);
    return 0;
}
