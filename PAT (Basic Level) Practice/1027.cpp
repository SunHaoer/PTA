#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, m, ans;
    char ch;
    cin>>n>>ch;
    m = sqrt(( n + 1 ) / 2);              // ��ѧ��ʽ������ϰ������ε�����
    ans = n - (2 * m * m - 1);            // ʣ�µķ�����
    for(int i = 0; i < m; i++) {          // ����ϰ�������
        for(int j = 0; j < i; j++) {
            cout<<" ";
        }
        for(int j = 0; j < 2 * ( m - i) - 1; j++ ) {
            cout<<ch;
        }
        cout<<endl;
    }
    for(int i = 2; i <= m; i++) {         // ����°�������
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
