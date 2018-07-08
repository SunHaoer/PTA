#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, m, ans;
    char ch;
    cin>>n>>ch;
    m = sqrt(( n + 1 ) / 2);              // 数学公式计算出上半三角形的行数
    ans = n - (2 * m * m - 1);            // 剩下的符号数
    for(int i = 0; i < m; i++) {          // 输出上半三角形
        for(int j = 0; j < i; j++) {
            cout<<" ";
        }
        for(int j = 0; j < 2 * ( m - i) - 1; j++ ) {
            cout<<ch;
        }
        cout<<endl;
    }
    for(int i = 2; i <= m; i++) {         // 输出下半三角形
        for(int j = 0; j < m - i; j++) {
            cout<<" ";
        }
        for(int j = 0; j < 2 * i - 1; j++) {
            cout<<ch;
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
