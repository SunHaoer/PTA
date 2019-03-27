#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100010;

struct Node {
    int address, data, next;
} node[MAX];

int main()
{
    int n, first, address;
    scanf("%d %d", &first, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &address);
        node[address].address = address;
        scanf("%d %d", &node[address].data, &node[address].next);
    }
    Node linkList[MAX];
    int ans = 0;
    while(first != -1) {
        linkList[ans++] = node[first];
        first = node[first].next;
    }
    bool flag[MAX];
    for(int i = 0; i < ans; i++) {      // 此处使用ans, 防止输入时有多余的节点
        printf("%05d %d ", linkList[ans - 1 - i].address, linkList[ans - 1 - i].data);
        flag[linkList[ans - 1 - i].address] = true;
        if(flag[linkList[i].address]) {
            printf("-1\n");
            break;
        } else {
            printf("%05d\n", linkList[i].address);
        }
        printf("%05d %d ", linkList[i].address, linkList[i].data);
        flag[linkList[i].address] = true;
        if(flag[linkList[ans - 1 - i - 1].address]) {
            printf("-1\n");
            break;
        } else {
            printf("%05d\n", linkList[ans - 1 - i - 1].address);
        }
    }

    return 0;
}
