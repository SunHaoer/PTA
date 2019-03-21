#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 100010;
bool table[MAX];

int main()
{
    int n, m, temp, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &temp);
            if(m == 1) continue;
            table[temp] = true;
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &temp);
        if(!table[temp]) {
            if(cnt != 0) printf(" ");
            printf("%05d", temp);
            table[temp] = true;
            cnt++;
        }
    }
    if(cnt == 0) {
        printf("No one is handsome\n");
    }
    return 0;
}
