#include<cstdio>
#include<cmath>
using namespace std;
const int MAX = 10010;
int ans[MAX] = { 0 };

int main()
{
    int n;
    scanf("%d", &n);
    int maxid, maxn = -1, minid, minn = 101;
    for(int i = 0; i < n; i++) {
        int id, a, b;
        double temp;
        scanf("%d%d%d", &id, &a, &b);
        temp = sqrt(a * a + b * b);
        ans[id] = temp;
        if(temp > maxn) {
            maxn = temp;
            maxid = id;
        }
        if(temp < minn) {
            minn = temp;
            minid = id;
        }
    }
    printf("%04d %04d\n", minid, maxid);
    return 0;
}
