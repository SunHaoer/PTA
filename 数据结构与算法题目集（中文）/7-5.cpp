#include<iostream>
using namespace std;
const int MAX = 10001;
const int MIN = -100001;
int heap[MAX], ans = 0;            // 堆heap, 堆大小ans

void Insert(int data) {     // 插入
    ans++;                  // 每插入一个数据, 堆大小加一
    int i;
    for(i = ans; heap[i / 2] > data; i /= 2) {
        heap[i] = heap[i / 2];          // data小于父亲节点, 父亲节点下移
    }
    heap[i] = data;
}

void Create(int n) {     // 建堆
    int data;
    ans = 0, heap[0] = MIN;             // heap[0]为最小值, 岗哨作用
    for(int i = 0; i < n; i++) {
        cin>>data;
        Insert(data);
    }
    return;
}

void Output(int m) {        // 求路径, 并输出
    int index;
    for(int i = 0; i < m; i++) {
        cin>>index;
        cout<<heap[index];
        while(index != 1) {
            index /= 2;
            cout<<" "<<heap[index];
        }
        cout<<endl;
    }
    return;
}

int main()
{
    int n, m;
    cin>>n>>m;
    Create(n);
    Output(m);
    return 0;
}
