#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 10010;
char table[MAX][MAX];

int main()
{
    int n, m;
    string str;
    cin>>n;
    getchar();
    getline(cin, str);
    int len = str.length();
    m = len / n;
    if(len % n != 0) m++;
    int ans = 0;
    for(int i = 0; i <= n; i++) {   // 初始化默认字符为' '
        for(int j = 0; j <= m; j++) {
            table[i][j] = ' ';
        }
    }
    for(int i = m - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(ans >= len) break;
            table[j][i] = str[ans++];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<table[i][j];
        }
        if(m != 0) printf("\n");
    }
    return 0;
}
