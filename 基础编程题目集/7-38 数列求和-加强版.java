#include<cstdio>
using namespace std;

int main()
{
    int a, n, num[1000000];
    int ans = 1, temp = 0;
    scanf("%d%d", &a, &n);
    for(int i = 0; i < n; i++) {
        temp = a * (n - i);				// 垂直相加
        ans = 0;
        while(temp > 0) {               // 把temp放入num
            num[i + ans] += (temp % 10);        // num中的进位
            if(num[i + ans] >= 10 ) {			// 进位后的进位
                num[i + ans] %= 10;
                num[i + ans + 1]++;
            }
            ans++;
            temp /= 10;
        }
    }
    bool flag = false;
    for(int i = n + 10; i >= 0; i--) {
        if(flag == false && num[i] == 0) {
            continue;
        }
        printf("%d", num[i]);
        flag = true;
    }
    if(flag == false) {
        printf("0");
    }
    return 0;
}
