#include<cstdio>
#include<cmath>
using namespace std;
const int MAX = 100010;
bool table[MAX];

struct Node {
    int address, data, next;
} node[MAX];

int main()
{
    int first, n;
    scanf("%d %d", &first, &n);
    int address, data, next;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    Node linkList1[n], linkList2[n];
    int ans1 = 0, ans2 = 0;
    while(first != -1) {
        if(!table[(int)abs(node[first].data)]) {
            linkList1[ans1++] = node[first];
            table[(int)abs(node[first].data)] = true;
        } else {
            linkList2[ans2++] = node[first];
        }
        first = node[first].next;
    }
    for(int i = 0; i < ans1 - 1; i++) {
        printf("%05d %d %05d\n", linkList1[i].address, linkList1[i].data, linkList1[i + 1].address);
    }
    printf("%05d %d -1\n", linkList1[ans1 - 1].address, linkList1[ans1 - 1].data);
    if(ans2 > 0) {
        for(int i = 0; i < ans2 - 1; i++) {
            printf("%05d %d %05d\n", linkList2[i].address, linkList2[i].data, linkList2[i + 1].address);
        }
        printf("%05d %d -1\n", linkList2[ans2 - 1].address, linkList2[ans2 - 1].data);
    }
    return 0;
}
