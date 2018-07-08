#include<iostream>
#include<cstdio>
using namespace std;

struct Problem {
    int score, num;     // 分值score, 正确答案个数num
    string answer;      // 答案
} pro[1010];

struct Student {
    int score;          // 分数
    string answer;      // 回答
} stu[1100];

bool check(string str1, string str2) {      // 判题
    if(str1 == str2) return true;
    else return false;
}

int main()
{
    int n, m;       // 学生数n, 试题数m
    cin>>n>>m;
    int error[1010] = { 0 };
    for(int i = 0; i < m; i++) {        // 试题信息
        int temp;
        cin>>pro[i].score>>temp>>pro[i].num;
        pro[i].answer = "";
        for(int j = 0; j < pro[i].num; j++) {       // 提取答案
            char ch;
            cin>>ch;
            pro[i].answer += ch;
        }
    }
    for(int i = 0; i < n; i++) {         // 学生答题
        string str;
        getchar();
        getline(cin, str);
        stu[i].answer = "";
        stu[i].score = 0;
        int ans = 0;                     // 题目计数
        for(int j = 0; j < str.size(); j++) {
            if(str[j] >= 'a' && str[j] <= 'z') {
                stu[i].answer += str[j];
            }
            if(str[j] == ')') {          // 一题结束
                if(check(pro[ans].answer, stu[i].answer) == true) {             // 答对
                    stu[i].score += pro[ans].score;
                } else {
                    error[ans]++;           // 统计错误
                }
                stu[i].answer = "";
                ans++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout<<stu[i].score<<endl;
    }
    int maxe = 0;       // 错误最多
    for(int i = 0; i < m; i++) {
        maxe = max(maxe, error[i]);
    }
    if(maxe == 0) {
        cout<<"Too simple"<<endl;
    } else {
        cout<<maxe;
        for(int i = 0; i < m; i++) {
            if(error[i] == maxe) {
                cout<<" "<<i + 1;
            }
        }
        cout<<endl;
    }
    return 0;
}
