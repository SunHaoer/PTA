#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 550;
int arr1[MAX], arr2[MAX], arr3[MAX], n;
bool flag = false;

void Print(int arr[MAX]) {      // 输出
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i == n - 1) printf("\n");
        else printf(" ");
    }
}

bool Judge(int arr[MAX]) {      // 判断
    for(int i = 0; i < n; i++) {
        if(arr[i] != arr3[i]) return false;
    }
    return true;
}

void Insert() {     // 插入排序
    for(int i = 2; i <= n; i++) {
        flag = (Judge(arr1) && i != 2);
        sort(arr1, arr1 + i);
        if(flag) return;
    }
    flag = Judge(arr1);
}

void Merge() {      // 归并排序
    for(int step = 2; step / 2 < n; step *= 2) {
        flag = (Judge(arr2) && step != 2);
        for(int i = 0; i < n; i += step) {
            sort(arr2 + i, arr2 + min(i + step, n));
        }
        if(flag) return;
    }
    flag = Judge(arr2);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {    // 输入
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr3[i]);
    }
    Insert();       // 插入排序
    if(flag) {
        printf("Insertion Sort\n");
        Print(arr1);
    }
    if(!flag) {
        Merge();    // 归并排序
        if(flag) {
            printf("Merge Sort\n");
            Print(arr2);
        }
    }
    return 0;
}
