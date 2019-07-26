#include<iostream>
using namespace std;
const int MAX = 110;
int score[MAX], answ[MAX];      // 分值score, 答案answ
int stu[MAX][MAX], mark[MAX] = { 0 };          // 学生答案stu, 学生成绩mark

int main()
{
    int n, m;
    cin>>n>>m;      // 学生人数n, 判断题数m
    for(int i = 0; i < m; i++) {         // 分值
        cin>>score[i];
    }
    for(int i = 0; i < m; i++) {         // 答案
        cin>>answ[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin>>temp;
            if(temp == answ[j]) {        // 正确
                mark[i] += score[j];
            } else {                     // 错误
                continue;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<mark[i]<<endl;
    }
    return 0;
}
