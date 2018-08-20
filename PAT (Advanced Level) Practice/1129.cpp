#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int MAX = 51000;

int main()
{
    int n, k, ans[MAX], maxN = -1;      // 每个数字出现的次数ans, 出现最多的数字出现次数maxN
    set<int> num[MAX];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);         // 输入
        if(i != 0) {
            printf("%d:", temp);
            int l = 0;
            for(int j = maxN; j >= 0; j--) {        // 输出
                for(set<int>::iterator it = num[j].begin(); it != num[j].end() && l < k; it++) {
                    printf(" %d", *it);
                    l++;
                }
            }
            printf("\n");
        }
        num[ans[temp]].erase(temp);         // 删除当前层的temp
        num[++ans[temp]].insert(temp);      // 在下一层中插入temp
        maxN = max(maxN, ans[temp]);
    }
    return 0;
}


/*
 * set<int> 中num[i]代表该set中的元素出现了i次
 */
