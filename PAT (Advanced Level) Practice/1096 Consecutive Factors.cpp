#include<cstdio>
#include<cmath>
#include<climits>
using namespace std;
const int MAX = INT_MAX;

int main()
{
    int num, len = 0, first = 0, maxn = 1;
    scanf("%d", &num);          // 输入
    for(int i = 2; i <= sqrt(num); i++) {
        int j = i, temp = 1;
        for(j = i; j <= num; j++) {
            temp *= j;
            if(num % temp != 0) break;
        }
        if(j - i > len) {       // 更新
            len = j - i;
            first = i;
        }
    }
    if(len != 0) {              // 输出
        printf("%d\n", len);
        for(int i = 0; i < len; i++) {
            printf("%d", first + i);
            if(i != len - 1) printf("*");
            else printf("\n");
        }
    } else {
        printf("1\n%d\n", num);
    }
    return 0;
}
