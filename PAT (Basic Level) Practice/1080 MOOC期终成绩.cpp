#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct Student {
    string name;
    int score1;         // 刷题成绩
    int score2;         // 期中考成绩
    int score3;         // 期末考成绩
    int score4;         // 总分
    Student() {
        score1 = -1;
        score2 = -1;
        score3 = -1;
        score4 = -1;
    }
};
map<string, Student> mp;
vector<Student> vt;

bool cmp(Student stu1, Student stu2) {
    if(stu1.score4 != stu2.score4) return stu1.score4 > stu2.score4;
    else return stu1.name < stu2.name;
}

int main()
{
    int p, m, n;        // 做题人数p, 期中考人数m, 期末考人数n
    cin>>p>>m>>n;
    for(int i = 0; i < p; i++) {        // score1及格
        Student temp;
        cin>>temp.name>>temp.score1;
        if(temp.score1 >= 200) {
            mp[temp.name] = temp;
        }
    }
    for(int i = 0; i < m; i++) {        // score2
        Student temp;
        cin>>temp.name>>temp.score2;
        if(mp[temp.name].score1 >= 200) {
            mp[temp.name].score2 = temp.score2;
        }
    }
    for(int i = 0; i < n; i++) {        // score3
        Student temp;
        cin>>temp.name>>temp.score3;
        if(mp[temp.name].score1 >= 200) {
            mp[temp.name].score3 = temp.score3;
            mp[temp.name].score4 = mp[temp.name].score2 * 0.4 + mp[temp.name].score3 * 0.6 + 0.5;
            if(mp[temp.name].score4 < mp[temp.name].score3) mp[temp.name].score4 = mp[temp.name].score3;
        }
    }
    for(map<string, Student>::iterator it = mp.begin(); it != mp.end(); it++) {     // mp->vt
        if(it->second.score4 >= 60) {
            vt.push_back(it->second);
        }
    }
    sort(vt.begin(), vt.end(), cmp);
    for(int i = 0; i < vt.size(); i++) {                                            // 输出
        cout<<vt[i].name<<" "<<vt[i].score1<<" "<<vt[i].score2<<" "<<vt[i].score3<<" "<<vt[i].score4<<endl;
    }
    return 0;
}







