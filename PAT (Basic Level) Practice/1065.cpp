#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100010;
int cat[MAX], dog[MAX];         // 非dog, 即为cat
bool peo[MAX];                  // 所有出席人员名单

int main()
{
    int n, m, id, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &id);
        scanf("%d", &cat[id]);
        cat[cat[id]] = id;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {     // 把到场的人标记为true
        scanf("%d", &id);
        peo[id] = true;
    }
    for(int i = 0; i < MAX; i++) {
        if(peo[i] == true && peo[cat[i]] == false) {        // 来了, 同伴不在名单上
            dog[ans++] = i;
        }
    }
    sort(dog, dog + ans);
    printf("%d\n", ans);
    if(ans == 0) return 0;
    for(int i = 0; i < ans - 1; i++) {
        printf("%05d ", dog[i]);
    }
    printf("%d", dog[ans-1]);
    return 0;
}
