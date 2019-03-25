#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int MAX = 1010;
int v, e, k;
bool table[MAX][MAX];

int main()
{
    fill(table[0], table[0] + MAX * MAX, false);
    scanf("%d %d %d", &v, &e, &k);
    for(int i = 0; i < e; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        table[a][b] = table[b][a] = true;
    }
    int repeat, color[MAX];
    scanf("%d", &repeat);
    for(int i = 0; i < repeat; i++) {
        set<int> st;
        for(int j = 1; j <= v; j++) {
            scanf("%d", &color[j]);
            st.insert(color[j]);
        }
        if(st.size() != k) {
            printf("No\n");
        } else {
            bool flag = true;
            for(int a = 1; a <= v; a++) {
                for(int b = a + 1; b <= v; b++) {
                    if(table[a][b] && color[a] == color[b]) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
