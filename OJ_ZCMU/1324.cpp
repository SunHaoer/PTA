#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> table;

int main()
{
    int n, m, num;
    while(scanf("%d%d", &n, &m) != EOF) {
        if(n == 0 && m == 0) break;
        table.clear();
        table.push_back(m);
        for(int i = 0; i < n; i++) {
            scanf("%d", &num);
            table.push_back(num);
        }
        sort(table.begin(), table.end());
        printf("%d", table[0]);
        for(int i = 1; i < table.size(); i++) {
            printf(" %d", table[i]);
        }
        printf("\n");
    }
    return 0;
}
