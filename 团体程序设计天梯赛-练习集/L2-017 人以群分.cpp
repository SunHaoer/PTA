#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100010;
int arr[MAX];

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n, cmp);
    int cnt1 = 0, cnt2 = 0;
    int len1 = n % 2 == 0 ? n / 2 : n / 2 + 1;
    int len2 = n - len1;
    for(int i = 0; i < n; i++) {
        if(i < len1) cnt1 += arr[i];
        else cnt2 += arr[i];
    }
    printf("Outgoing #: %d\n", len1);
    printf("Introverted #: %d\n", len2);
    printf("Diff = %d\n", cnt1 - cnt2);
    return 0;
}
