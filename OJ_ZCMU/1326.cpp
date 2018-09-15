#include<cstdio>
using namespace std;
const int MAX = 35;
int table[MAX][MAX];

void fun1() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < i; j++) {
            if(i == 0 || j == 0) {
                table[i][j] = 1;
            } else {
                table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
            }
        }
    }
}

int main()
{
    fun1();
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                printf("%d ", table[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
