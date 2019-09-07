#include<cstdio>
using namespace std;
const int MAX = 11000;
int table[MAX];

bool isPrime(int n) {
    if(n == 0 || n == 1) return false;
    for(int i = 2; i < n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    while(!isPrime(m)) m++;     // tsize
    for(int i = 0; i < n; i++) {    // 输入
        int num;
        scanf("%d", &num);
        bool flag = false;
        for(int j = 0; j <= i; j++) {
            int index = (num + j * j) % m;      // 平方探测的下标
            if(table[index] == 0) {
                table[index] = num;
                printf("%d", index);
                flag = true;
                break;
            }
        }
        if(!flag) printf("-");
        if(i != n - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}
