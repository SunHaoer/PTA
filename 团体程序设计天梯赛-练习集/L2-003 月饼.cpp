#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 1100;

struct Mooncake {
    double store, cnt, price;
} moon[MAX];

bool cmp(Mooncake a, Mooncake b) {
    return a.price > b.price;
}

int main()
{
    int n, d;
    double cnt = 0;
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &moon[i].store);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lf", &moon[i].cnt);
        moon[i].price = moon[i].cnt / moon[i].store;
    }
    sort(moon, moon + n, cmp);
    for(int i = 0; i < n; i++) {
        if(d >= moon[i].store) {
            d -= moon[i].store;
            cnt += moon[i].store * moon[i].price;
        } else {
            cnt += d * moon[i].price;
            break;
        }
    }
    printf("%.2f\n", cnt);
    return 0;
}
