#include<iostream>
using namespace std;
const int MAX = 110;
int score[MAX], answ[MAX];      // ��ֵscore, ��answ
int stu[MAX][MAX], mark[MAX] = { 0 };          // ѧ����stu, ѧ���ɼ�mark

int main()
{
    int n, m;
    cin>>n>>m;      // ѧ������n, �ж�����m
    for(int i = 0; i < m; i++) {         // ��ֵ
        cin>>score[i];
    }
    for(int i = 0; i < m; i++) {         // ��
        cin>>answ[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin>>temp;
            if(temp == answ[j]) {        // ��ȷ
                mark[i] += score[j];
            } else {                     // ����
                continue;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<mark[i]<<endl;
    }
    return 0;
}
