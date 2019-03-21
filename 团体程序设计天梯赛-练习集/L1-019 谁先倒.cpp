#include<cstdio>
using namespace std;

int main()
{
    int cntA, cntB, n, ansA = 0, ansB = 0;   // ¼×ÒÒ¾ÆÁ¿
    scanf("%d %d %d", &cntA, &cntB, &n);
    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(b == d) continue;
        if(a + c == b) ansA++;
        if(a + c == d) ansB++;
        if(ansA > cntA) {
            printf("A\n%d\n", ansB);
            break;
        }
        if(ansB > cntB) {
            printf("B\n%d\n", ansA);
            break;
        }
    }

    return 0;
}
