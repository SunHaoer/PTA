#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX = 10010;
bool primeTable[MAX];
int table[MAX];

bool isPrime(int num) {
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main()
{
    fill(table, table + MAX, -1);
    int n, m, k;
    double ans = 0, cnt = 0;
    scanf("%d %d %d", &n, &m, &k);
    while(!isPrime(n)) n++;  // n 为素数
    for(int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        int flag = false;
        for(int j = 0; j < n; j++) {    // 平方探测法
            int pos = (num + j * j) % n;
            if(table[pos] == -1) {
                flag = true;
                table[pos] = num;
                break;
            }
        }
        if(!flag) printf("%d cannot be inserted.\n", num);
    }
    for(int i = 0; i < k; i++) {    // 查询
        int num;
        scanf("%d", &num);
        for(int j = 0; j <= n; j++) {
            ans++;
            int pos = (num + j * j) % n;
            if(table[pos] == num || table[pos] == -1) {
                break;
            }
        }
    }
    printf("%.1f\n", (ans * 1.0) / k);
    return 0;
}



