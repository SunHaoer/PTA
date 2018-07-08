#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100010;

struct Node {
    int address, data, next;
}node[MAX], L[MAX];

bool cmp(Node a, Node b) {
    return a.data > b.data;
}

int main()
{
    int first, n, k, ans = 0;
    scanf("%d%d%d", &first, &n, &k);
    int address;
    for(int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    while(first != -1) {                             // 去掉不在链表上的节点
        L[ans].address = first;
        L[ans].data = node[first].data;
        L[ans].next = node[first].next;
        first = node[first].next;
        ans++;
    }
    for (int i = 0; i < (ans - ans % k); i += k) {              // 反转
        reverse(L + i, L + i + k);
    }
    for(int i = 0; i < ans; i++) {
        if(i + 1 == ans) break;
        printf("%05d %d %05d\n", L[i].address, L[i].data, L[i+1].address);
    }
    printf("%05d %d -1\n", L[ans-1].address, L[ans-1].data);
    return 0;
}
