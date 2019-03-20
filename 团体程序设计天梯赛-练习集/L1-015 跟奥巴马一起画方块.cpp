#include<cstdio>
using namespace std;

int main()
{
    int n, ch;
    scanf("%d %c", &n, &ch);
    for(int i = 0; i < (n + 1) / 2; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
