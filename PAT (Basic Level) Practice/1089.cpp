#include<cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; k++) {
                if (v[k] * a[abs(v[k])] < 0) {
                    lie.push_back(k);
                }
            }
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}



/*
 * 不会写, 不会写, 不会写!!!
 */
