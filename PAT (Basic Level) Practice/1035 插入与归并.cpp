#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 110;
int n, num1[MAX], num2[MAX], arr[MAX];

void Print(int num[]) {
    for(int i = 0; i < n; i++) {
        cout<<num[i];
        if(i != n - 1) cout<<' ';
    }
    cout<<endl;
}

bool fun1(int A[], int B[]) {               // 判断是否相同
    for(int i = 0; i < n; i++) {
        if(A[i] != B[i]) return false;
    }
    return true;
}

bool fun2() {                               // 插入排序
    bool flag = false;
    for(int i = 1; i < n; i++) {
        if(i != 1 && fun1(num1, arr) == true) {
            flag = true;
        }
        int temp = num1[i], j = i;
        while(j > 0 && temp < num1[j - 1]) {
            num1[j] = num1[j - 1];
            j--;
        }
        num1[j] = temp;
        if(flag == true) {
            return true;
        }
    }
    return false;
}

void fun3() {                               // 归并排序
    bool flag = false;
    for(int step = 2; step / 2 <= n; step *= 2) {
        if(step != 2 && fun1(num2, arr)) {
            flag = true;
        }
        for(int i = 0; i < n; i += step) {
            sort(num2 + i, num2 + min(i + step, n));
        }
        if(flag == true) {
            Print(num2);
            return;
        }
    }
    return;
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>num1[i];
        num2[i] = num1[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    if(fun2() == true) {               // 插入排序
        cout<<"Insertion Sort"<<endl;
        Print(num1);
    } else {                           // 归并排序
        cout<<"Merge Sort"<<endl;
        fun3();
    }
    return 0;
}
