#include<cstdio>
using namespace std;
int ans[101] = { 0 };

int main()
{
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score);
        ans[score]++;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int score;
        scanf("%d", &score);
        printf("%d", ans[score]);
        if(i != k - 1) printf(" ");
    }
    return 0;
}
