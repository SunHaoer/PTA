#include<iostream>
using namespace std;
const int MAX = 10001;
const int MIN = -100001;
int heap[MAX], ans = 0;            // ��heap, �Ѵ�Сans

void Insert(int data) {     // ����
    ans++;                  // ÿ����һ������, �Ѵ�С��һ
    int i;
    for(i = ans; heap[i / 2] > data; i /= 2) {
        heap[i] = heap[i / 2];          // dataС�ڸ��׽ڵ�, ���׽ڵ�����
    }
    heap[i] = data;
}

void Create(int n) {     // ����
    int data;
    ans = 0, heap[0] = MIN;             // heap[0]Ϊ��Сֵ, ��������
    for(int i = 0; i < n; i++) {
        cin>>data;
        Insert(data);
    }
    return;
}

void Output(int m) {        // ��·��, �����
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
