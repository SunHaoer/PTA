#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 100010;

struct Node {
    int data, address, next;
} node[MAX];
vector<Node> node1, node2, node3;

int main()
{
    int first, n, k;
    scanf("%d %d %d", &first, &n, &k);
    for(int i = 0; i < n; i++) {        // 输入
        int address;
        scanf("%d", &address);
        scanf("%d", &node[address].data);
        scanf("%d", &node[address].next);
        node[address].address = address;
    }
    while(first != -1) {        // 创建链表
        if(node[first].data < 0) node1.push_back(node[first]);
        else if(node[first].data <= k) node2.push_back(node[first]);
        else node3.push_back(node[first]);
        first = node[first].next;
    }
    if(node1.size() != 0) {         // 输出
        for(int i = 0; i < node1.size() - 1; i++) {
            printf("%05d %d %05d\n", node1[i].address, node1[i].data, node1[i + 1].address);
        }
        if(node2.size() != 0) {
            printf("%05d %d %05d\n", node1[node1.size() - 1].address, node1[node1.size() - 1].data, node2[0].address);
        } else if(node3.size() != 0) {
            printf("%05d %d %05d\n", node1[node1.size() - 1].address, node1[node1.size() - 1].data, node3[0].address);
        } else {
            printf("%05d %d -1\n", node1[node1.size() - 1].address, node1[node1.size() - 1].data);
        }
    }
    if(node2.size() != 0) {
        for(int i = 0; i < node2.size() - 1; i++) {
            printf("%05d %d %05d\n", node2[i].address, node2[i].data, node2[i + 1].address);
        }
        if(node3.size() != 0) {
            printf("%05d %d %05d\n", node2[node2.size() - 1].address, node2[node2.size() - 1].data, node3[0].address);
        } else {
            printf("%05d %d -1\n", node2[node2.size() - 1].address, node2[node2.size() - 1].data);
        }
    }
    if(node3.size() != 0) {
        for(int i = 0; i < node3.size() - 1; i++) {
            printf("%05d %d %05d\n", node3[i].address, node3[i].data, node3[i + 1].address);
        }
        printf("%05d %d -1\n", node3[node3.size() - 1].address, node3[node3.size() - 1].data);
    }

    return 0;
}
