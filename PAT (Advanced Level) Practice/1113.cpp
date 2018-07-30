#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> vt;
    int n, ans1 = 0, ans2 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {        // 输入
        int temp;
        scanf("%d", &temp);
        vt.push_back(temp);
    }
    sort(vt.begin(), vt.end());
    for(int i = 0; i < n / 2; i++) {        // 小的集合
        ans1 += vt[i];
    }
    for(int i = n - 1; i >= n / 2; i--) {   // 大的集合
        ans2 += vt[i];
    }
    if(n % 2 == 0) {        // 输出
        printf("0 %d\n", ans2 - ans1);
    } else {
        printf("1 %d\n", ans2 - ans1);
    }
    return 0;
}
