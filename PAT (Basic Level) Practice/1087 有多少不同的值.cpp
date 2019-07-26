#include<cstdio>
using namespace std;
const int MAX = 100010;
bool arr[MAX];

int cul(int n) {
    return (n / 2) + (n / 3) + (n / 5);
}

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        arr[cul(i)] = true;
    }
    for(int i = 0; i < MAX; i++) {
        cnt += (arr[i]);
    }
    printf("%d\n", cnt);
    return 0;
}
