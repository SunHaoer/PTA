#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 20010;
int d[MAX], x[MAX];

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) != 0) {
        if(n == 0 && m == 0) return 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &d[i]);
        }
        sort(d, d + n);
        for(int i = 0; i < m; i++) {
            scanf("%d", &x[i]);
        }
        sort(x, x + m);
        bool flag1 = false;
        for(int i = n - 1; i >= 0; i--) {
            bool flag2 = false;
            for(int j = 0; j < m; j++) {
                if(d[i] <= x[j]) {
                    ans += x[j];
                    x[j] = -1;
                    flag2 = true;
                    break;
                }
            }
            if(flag2 == false) {
                flag1 = true;
                break;
            }
        }
        if(flag1 == true) {
            printf("Loowater is doomed!\n");
        } else {
            printf("%d\n", ans);
        }
    }
}
