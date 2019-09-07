#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
const int MAX = 100010;

int main()
{
    int n, num[MAX];
    vector<int> vt;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {    // 输入
        scanf("%d", &num[i]);
    }
    int arr1[MAX], arr2[MAX];
    arr1[0] = num[0];
    for(int i = 1; i < n; i++) {    // 求最大pivot
        if(num[i] > arr1[i - 1]) {
            arr1[i] = num[i];
        } else {
            arr1[i] = arr1[i - 1];
        }
    }
    arr2[n - 1] = num[n - 1];
    for(int i = n - 2; i >= 0; i--) {       // 求最小pivot
        if(num[i] < arr2[i + 1]) {
            arr2[i] = num[i];
        } else {
            arr2[i] = arr2[i + 1];
        }
    }
    for(int i = 0; i < n; i++) {             // 求pivot
        if(arr1[i] == arr2[i]) {
            vt.push_back(arr1[i]);
        }
    }
    printf("%d\n", vt.size());               // 输出
    for(int i = 0; i < vt.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", vt[i]);
    }
    printf("\n");
    return 0;
}
