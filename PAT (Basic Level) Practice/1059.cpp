#include<cstdio>
#include<cmath>
using namespace std;
const int MAX = 10010;

struct Student {
    int id, ranked, flag;
    Student() {                 // flag初始化为0
        flag = 0;
    }
} stu[MAX];

bool isPrime(int n) {           // 判断是否素数
    bool flag = true;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int id;
        scanf("%d", &id);
        stu[id].id = id;
        stu[id].ranked = i + 1;
        stu[id].flag = 1;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int id;
        scanf("%d", &id);
        if(stu[id].flag == 0) {         // 未参与
            printf("%04d: Are you kidding?\n", id);
        } else if(stu[id].flag == 1) {
            if(stu[id].ranked == 1) {               // 第一名
                printf("%04d: Mystery Award\n", id);
            } else if(isPrime(stu[id].ranked)) {    // 素数
                printf("%04d: Minion\n", id);
            } else {
                printf("%04d: Chocolate\n", id);    // 其他
            }
            stu[id].flag = 2;
        } else {
            printf("%04d: Checked\n", id);
        }
    }
    return 0;
}
