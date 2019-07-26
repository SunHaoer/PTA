#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100010;
int first, n, k;

struct Node{
    int address, data, next;
}node[MAX], L1[MAX], L2[MAX], L3[MAX];

int main()
{
    int address, ans1 = 0, ans2 = 0, ans3 = 0;
    scanf("%d%d%d", &first, &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    while(first != -1) {
        if(node[first].data < 0) L1[ans1++] = node[first];                  // 负数ans1, L1
        else if(node[first].data >= 0 && node[first].data <= k) L2[ans2++] = node[first];           // 区间内ans2, L2
        else L3[ans3++] = node[first];              // 其余正数ans3, L3
        first = node[first].next;
    }
    if(ans1 != 0) {
        for(int i = 0; i < ans1 - 1; i++) {
            printf("%05d %d %05d\n", L1[i].address, L1[i].data, L1[i + 1].address);
        }
        if(ans2 != 0) {                             // 寻找下一个链表
            printf("%05d %d %05d\n", L1[ans1 - 1].address, L1[ans1 - 1].data, L2[0].address);
        } else if(ans3 != 0){
            printf("%05d %d %05d\n", L1[ans1 - 1].address, L1[ans1 - 1].data, L3[0].address);
        } else {
            printf("%05d %d -1\n", L1[ans1 - 1].address, L1[ans1 - 1].data);
        }
    }
    if(ans2 != 0) {
        for(int i = 0; i < ans2 - 1; i++) {
            printf("%05d %d %05d\n", L2[i].address, L2[i].data, L2[i + 1].address);
        }
        if(ans3 != 0) {                              // 寻找下一个链表
            printf("%05d %d %05d\n", L2[ans2 - 1].address, L2[ans2 - 1].data, L3[0].address);
        } else {
            printf("%05d %d -1\n", L2[ans2 - 1].address, L2[ans2 - 1].data);
        }
    }
    if(ans3 != 0) {
        for(int i = 0; i < ans3 - 1; i++) {
            printf("%05d %d %05d\n", L3[i].address, L3[i].data, L3[i + 1].address);
        }
        printf("%05d %d -1\n", L3[ans3 - 1].address, L3[ans3 - 1].data);
    }
    return 0;
}
