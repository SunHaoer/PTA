#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 1000010;
int arr1[MAX], arr2[MAX];
int n, m, ans = 0;

void fun1(int arr[], int &n) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
}

int main()
{
    fun1(arr1, n);
    fun1(arr2, m);
    for(int i = n - 1, j = m - 1; i >= 0, j >= 0; i--, j--) {
        if(arr1[i] > 0 && arr2[j] > 0) {
            ans += arr1[i] * arr2[j];
        }
    }
    for(int i = 0, j = 0; i < n, j < m; i++, j++) {
        if(arr1[i] < 0 && arr2[i] < 0) {
            ans += arr1[i] * arr2[j];
        }
    }
    printf("%d\n", ans);
    return 0;
}
