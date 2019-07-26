#include<iostream>
#include<cstdio>
using namespace std;

struct Problem {
    int score, num;     // ��ֵscore, ��ȷ�𰸸���num
    string answer;      // ��
} pro[1010];

struct Student {
    int score;          // ����
    string answer;      // �ش�
} stu[1100];

bool check(string str1, string str2) {      // ����
    if(str1 == str2) return true;
    else return false;
}

int main()
{
    int n, m;       // ѧ����n, ������m
    cin>>n>>m;
    int error[1010] = { 0 };
    for(int i = 0; i < m; i++) {        // ������Ϣ
        int temp;
        cin>>pro[i].score>>temp>>pro[i].num;
        pro[i].answer = "";
        for(int j = 0; j < pro[i].num; j++) {       // ��ȡ��
            char ch;
            cin>>ch;
            pro[i].answer += ch;
        }
    }
    for(int i = 0; i < n; i++) {         // ѧ������
        string str;
        getchar();
        getline(cin, str);
        stu[i].answer = "";
        stu[i].score = 0;
        int ans = 0;                     // ��Ŀ����
        for(int j = 0; j < str.size(); j++) {
            if(str[j] >= 'a' && str[j] <= 'z') {
                stu[i].answer += str[j];
            }
            if(str[j] == ')') {          // һ�����
                if(check(pro[ans].answer, stu[i].answer) == true) {             // ���
                    stu[i].score += pro[ans].score;
                } else {
                    error[ans]++;           // ͳ�ƴ���
                }
                stu[i].answer = "";
                ans++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout<<stu[i].score<<endl;
    }
    int maxe = 0;       // �������
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
