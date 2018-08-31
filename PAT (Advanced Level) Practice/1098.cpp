#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 220;
int n;
int arr[3][MAX];        // arr[0]第1组, arr[1]第2组, arr[2]用于比较
bool flag = false;

void print(int num[MAX]) {
    for(int i = 0; i < n; i++) {
        printf("%d", num[i]);
        if(i != n - 1) printf(" ");
        else printf("\n");
    }
}

bool judge(int num[MAX]) {
    for(int i = 0; i < n; i++) {
        if(num[i] != arr[2][i]) {
            return false;
        }
    }
    return true;
}

void fun1(int num[MAX]) {       // Insert
    for(int i = 1; i < n; i++) {
        int temp = num[i], j = i;
        while(j > 0 && temp < num[j - 1]) {
            num[j] = num[j - 1];
            j--;
        }
        num[j] = temp;
        if(flag) {              // 输出
            printf("Insertion Sort\n");
            print(num);
            return;
        }
        if(judge(num)) flag = true;     // 符合条件
    }
}

void downAdjust(int low, int high, int num[MAX]) {
    int i = low, j = i * 2 + 1;     // 欲调节点i, 其左孩子节点j
    while(j <= high) {  // 存在左孩子
        if(j + 1 <= high && num[j + 1] > num[j]) {
            j = j + 1;
        }
        if(num[j] > num[i]) {       // 左孩子比右孩子大
            swap(num[j], num[i]);
            i = j;
            j = i * 2 + 1;
        } else {        // 孩子节点的权值均比父亲节点小
            break;
        }
    }

}

void fun2(int num[MAX]) {
    bool flag = false;
    for(int i = n / 2 - 1; i >= 0; i--) {
        downAdjust(i, n - 1, num);        // 建堆
    }
    for(int i = n - 1; i >= 0; i--) {
        if(i != n - 1 && judge(num)) flag = true;
        swap(num[i], num[0]);
        downAdjust(0, i - 1, num);
        if(flag) {
            printf("Heap Sort\n");
            print(num);
            return;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < 3; i++) {        // 输入
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if(i == 1) {
                arr[0][j] = arr[i][j];
            }
        }
    }
    fun1(arr[0]);     // 判断insert
    if(!flag) fun2(arr[1]);
    return 0;
}
