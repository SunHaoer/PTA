#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, mark;
    cin>>n>>mark;             // ����, �ܷ�
    for(int i = 0; i < n; i++) {
        double tscore, sscore[101], sum = 0;
        int num, ans = 0;
        cin>>tscore;          // ��ʦ����score
        for(int j = 0; j < n - 1; j++) {
            cin>>num;
            if(num >= 0 && num <= mark) {
                sscore[ans++] = num;        // ѧ������
            }
        }
        sort(sscore, sscore + ans);
        for(int j = 1; j < ans - 1; j++) {
            sum += sscore[j];
        }
        double g1 = sum / (ans - 2);
        double g2 = tscore;
        cout<<(int)((g1 + g2) / 2 + 0.5)<<endl;
    }
    return 0;
}
