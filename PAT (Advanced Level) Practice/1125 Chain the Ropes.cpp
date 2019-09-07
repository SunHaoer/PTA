#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 10010;

int main()
{
    int n;
    double nums[MAX], ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {    // 输入
        scanf("%lf", &nums[i]);
    }
    sort(nums, nums + n);
    ans = nums[0];
    for(int i = 1; i < n; i++) {    // 打结
        ans = (ans + nums[i]) / 2;
    }
    printf("%d\n", int(ans));       // 向下取整
    return 0;
}
