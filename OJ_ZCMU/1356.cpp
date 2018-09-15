#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 10010;
int table[MAX];

void fun1() {
    table[0] = 0;
    table[1] = 1;
    for(int i = 2; i < MAX; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
}

int main()
{
    fun1();
    int repeat;
    scanf("%d", &repeat);
    while(repeat > 0) {
        repeat--;
        int m, n;
        scanf("%d%d", &m, &n);
        if(m > n) swap(m, n);
        bool flag = false;
        for(int i = 0; i < MAX; i++) {
            if(table[i] < m) continue;
            if(table[i] > n) break;
            if(flag == true) printf(" ");
            printf("%d", table[i]);
            flag = true;
        }
        printf("\n");
    }
    return 0;
}
