#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX = 101;
int table[MAX][MAX];        // table[n][m]

int main()
{
    string str;
    int m, n, c = 101;
    for(int i = 0; i < MAX; i++) {              // ' 'Òª³õÊ¼»¯
        for(int j = 0; j < MAX; j++) {
            table[i][j] = ' ';
        }
    }
    cin>>str;
    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j < str.size(); j++) {
            if(2 * i + j - 2 == str.size() && abs(i - j) < c && j >= i) {
                n = i;
                m = j;
                c = abs(m - n);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        table[i][0] = str[ans++];
    }
    for(int j = 1; j < m; j++) {
        table[n - 1][j] = str[ans++];
    }
    for(int i = n - 2; i >= 0; i--) {
        table[i][m - 1] = str[ans++];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<char(table[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
