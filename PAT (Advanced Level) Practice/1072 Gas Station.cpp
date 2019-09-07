#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 1015;
const int MAX = 1015;       // n<=1000, m<=10  ��  MAX>1010
int table[MAX][MAX];        // ͼ
int d[MAX];         // ����
bool visited[MAX];
int n, m, k, ds;    // ������n, ����վ��m, ����k, ����Χds
int ansSum = -1, ansId = -1, ansDist = -1;      // ��Ҫ����ľ����ansSum, ���Žڵ�ansId, �����̾���ansDist

int fun1(char str[]) {     // ��ýڵ���
    int ans = 0;
    for(int i = 0; i < strlen(str); i++) {
       if(str[i] != 'G') {
            ans = ans * 10 + (str[i] - '0');
        }
    }
    if(str[0] == 'G') ans += n;
    return ans;
}

void Dijkstra(int s) {
    fill(visited, visited + MAX, false);
    fill(d, d + MAX, INF);
    d[s] = 0;
    for(int i = 0; i < n + m; i++) {
        int u = -1, minn = INF;
        for(int j = 1; j <= n + m; j++) {
            if(visited[j] == false && d[j] < minn) {
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int v = 1; v <= n + m; v++) {
            if(visited[v] == false && d[u] + table[u][v] < d[v]) {
                d[v] = d[u] + table[u][v];
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    fill(table[0], table[0] + MAX * MAX, INF);
    for(int i = 0; i < k; i++) {        // ��ͼ
        char str1[5], str2[5];
        int a, b, c;
        scanf("%s%s%d", str1, str2, &c);
        a = fun1(str1);
        b = fun1(str2);
        table[a][b] = table[b][a] = c;
    }
    for(int i = n + 1; i <= n + m; i++) {       // ����ÿ������վ
        int minDist = INF, tempSum = 0;          // ���񷿵���̾���minDist, �����ܺ�tempSum
        Dijkstra(i);
        for(int j = 1; j <= n; j++) {       // ����ÿ����
            if(d[j] > ds) {         // ��������Χ
                minDist = -1;
                break;
            }
            minDist = min(minDist ,d[j]);
            tempSum += d[j];
        }
        if(minDist == -1) continue;     // ������, ����
        if(minDist > ansDist) {         // ��������������
            ansId = i;
            ansDist = minDist;
            ansSum = tempSum;
        } else if(minDist == ansDist && tempSum < ansSum) {
            ansId = i;
            ansSum = tempSum;
        }
    }
    if(ansId == -1) {
        printf("No Solution\n");
    } else {
        printf("G%d\n", ansId - n);
        printf("%.1f %.1f\n", ansDist * 1.0, ansSum * 1.0 / n);
    }
    return 0;
}
