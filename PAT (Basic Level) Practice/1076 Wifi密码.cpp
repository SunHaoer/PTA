#include<cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            char a, b;
            scanf("%*c%c%*c%c", &a, &b);        // %*c用于吃无用字符
            if(b == 'T') {
                printf("%d", a - 'A' + 1);
            }
        }
    }
    printf("\n");
    return 0;
}
