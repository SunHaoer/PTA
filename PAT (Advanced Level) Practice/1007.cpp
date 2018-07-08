#include<cstdio>
using namespace std;
const int MAX = 10010;
int arr1[MAX], arr2[MAX], arr3[MAX];        // 输入数组arr1, 最大值arr2, 起始下标arr3

int main()
{
    int n, maxn = -1, a = 0, b = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {        // 输入
        scanf("%d", &arr1[i]);
    }
    arr2[0] = arr1[0];
    arr3[0] = arr1[0];
    for(int i = 1; i < n; i++) {        // 寻找每个下标的最大值
        if(arr2[i - 1] > 0) {
            arr2[i] = arr2[i - 1] + arr1[i];
            arr3[i] = arr3[i - 1];
        } else {
            arr2[i] = arr1[i];
            arr3[i] = arr1[i];
        }
    }
    for(int i = 0; i < n; i++) {        // 寻找最大值
        if(arr2[i] > maxn && arr2[i] >= 0) {
            maxn = arr2[i];
            a = arr3[i];
            b = arr1[i];
        }
    }
    if(maxn == -1) {        // 最大值小于0特殊处理
        maxn = 0;
        a = arr1[0];
        b = arr1[n - 1];
    }
    printf("%d %d %d\n", maxn, a, b);
    return 0;
}
