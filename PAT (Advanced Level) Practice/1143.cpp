#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int MAX = 100010;
int pre[MAX];
map<int, bool> isExist;

int main()
{
    int n, m;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) {    // 输入
        scanf("%d", &pre[i]);
        isExist[pre[i]] = true;
    }
    for(int i = 0; i < m; i++) {    // 查询
        int a, b;
        scanf("%d %d", &a, &b);
        if(!isExist[a] && !isExist[b]) {        // 不存在
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if(isExist[a] == false) {
            printf("ERROR: %d is not found.\n", a);
        } else if(isExist[b] == false) {
            printf("ERROR: %d is not found.\n", b);
        } else {
            for(int j = 0; j < n; j++) {        // 找祖先
                if(pre[j] == a) {
                    printf("%d is an ancestor of %d.\n", a, b);
                    break;
                } else if(pre[j] == b) {
                    printf("%d is an ancestor of %d.\n", b, a);
                    break;
                } else if( (pre[j] > a && pre[j] < b) || (pre[j] > b && pre[j] < a) ) {
                    printf("LCA of %d and %d is %d.\n", a, b, pre[j]);
                    break;
                }
            }
        }
    }
    return 0;
}
