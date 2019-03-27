#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 550;
bool table[MAX][MAX];
bool losted[MAX], visited[MAX];
int cnt = 0, temp = 0;
int n, m;

void fun2(int now) {
    visited[now] = true;
    for(int i = 0; i < n; i++) {
        if(!losted[i] && !visited[i] && i != now && table[now][i]) fun2(i);
    }
}

void fun1(int now) {
    fill(visited, visited + MAX, false);
    temp = 0;
    for(int i = 0; i < n; i++) {
        if(!losted[i] && !visited[i]) {
            fun2(i);
            temp++;
        }
    }
    if(now != -1) {
        if(temp > cnt) printf("Red Alert: ");
        printf("City %d is lost", now);
        if(temp > cnt) printf("!\n");
        else printf(".\n");
    }
    cnt = temp;
}

int main()
{
    fill(losted, losted + MAX, false);
    fill(table[0], table[0] + MAX * MAX, false);
    scanf("%d %d", &n, &m);
    int a, b;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        table[a][b] = table[b][a] = true;
    }
    fun1(-1);
    int lostNode = -1;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &lostNode);
        losted[lostNode] = true;
        fun1(lostNode);
        if(i == n - 1) {
            printf("Game Over.\n");
            break;
        }
    }
    return 0;
}
