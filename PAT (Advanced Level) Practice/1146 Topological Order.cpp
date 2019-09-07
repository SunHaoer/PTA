#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 1000;
bool isSource[MAX];
vector<int> vec[MAX];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    fill(isSource, isSource + MAX, true);
    for(int i = 0; i < m; i++) {    // 输入
        int a, b;
        scanf("%d %d", &a, &b);
        vec[b].push_back(a);        // 把上一个节点存入vec
    }
    int k, temp;
    bool flag = true, isFirst = true, isExist[MAX] = {false};
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {        // 没次查询
        fill(isExist, isExist + MAX, false);
        flag = true;
        for(int j = 0; j < n; j++) {        // 输入每个数
            scanf("%d", &temp);
            isExist[temp] = true;
            if(!isSource[j] || flag) {
                for(int t = 0; t < vec[temp].size(); t++) {     // 遍历前一个节点
                    if(!isExist[vec[temp][t]]) {        // 存在没有出现的前一节点
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(!flag) {         // 输出
            if(!isFirst) printf(" ");
            printf("%d", i);
            isFirst = false;
        }
    }
    return 0;
}
