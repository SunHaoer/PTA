#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 1000000;

struct Node {
    int data, address, next;
} node[MAX], linkList[MAX];

int main()
{
    int first, n, k;
    scanf("%d %d %d", &first, &n, &k);
    for(int i = 0; i < n; i++) {        // 输入
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        node[a].address = a;
        node[a].data = b;
        node[a].next = c;
    }
    int ans = 0;
    while(first != -1) {        // 组成链表
        linkList[ans++] = node[first];
        first = node[first].next;
    }
    for(int i = 0; i + k <= ans; i += k) {    // 反转
        reverse(linkList + i, linkList + i + k);
    }
    for(int i = 0; i < ans - 1; i++) {      // 输出
        printf("%05d %d %05d\n", linkList[i].address, linkList[i].data, linkList[i + 1].address);
    }
    printf("%05d %d -1\n", linkList[ans - 1].address, linkList[ans - 1].data);
    return 0;
}
