#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
    int ge, gi, grade, r, id, cho[6];       //初试成绩ge, 面试成绩gi, 总分grade, 排名r, 编号id, 志愿cho[6]
}stu[40010];

struct School{
    int quota, stuNum, id[40010], lastAdmit;       //招生总额度quota, 当前招生人数stuNum, 招收学生编号id, 最后一个学生编号lastAdmit
}sch[110];

bool cmpStu(Student a, Student b){
    if(a.grade!=b.grade) return a.grade > b.grade;
    else return a.ge > b.ge;
}

bool cmpID(int a, int b){
    return stu[a].id<stu[b].id;
}

int main()
{
    int n, m, k;
    cin>>n>>m>>k;          //输入考生人数n, 学校数m, 志愿数k
    for(int i=0; i<m; i++){
        cin>>sch[i].quota;
        sch[i].stuNum = 0;
        sch[i].lastAdmit = -1;
    }
    for(int i=0; i<n; i++){
        stu[i].id = i;
        cin>>stu[i].ge>>stu[i].gi;
        stu[i].grade = stu[i].ge + stu[i].gi;
        for(int j=0; j<k; j++){
            cin>>stu[i].cho[j];
        }
    }
    sort(stu, stu+n, cmpStu);
    for(int i=0; i<n; i++){
        if(i>0&&stu[i].grade==stu[i-1].grade&&stu[i].ge==stu[i-1].ge){
            stu[i].r = stu[i-1].r;
        }
        else {
            stu[i].r = i;
        }
    }
    for(int i=0; i<n; i++){          //每个考生
        for(int j=0; j<k; j++){       //考生的每个志愿
            int choice = stu[i].cho[j];       //考生i的第j个志愿
            int num = sch[choice].stuNum;       //该学校当前招生人数
            int last = sch[choice].lastAdmit;     //该学校的最后一个考生
            if(num<sch[choice].quota||(last!=-1&&stu[i].r==stu[last].r)){           //录取
                sch[choice].id[num] = i;
                sch[choice].lastAdmit = i;
                sch[choice].stuNum++;
                break;
            }
        }
    }
    for(int i=0; i<m; i++){
        if(sch[i].stuNum>0){
            sort(sch[i].id, sch[i].id+sch[i].stuNum, cmpID);
            for(int j=0; j<sch[i].stuNum; j++){
                cout<<stu[sch[i].id[j]].id;
                if(j<sch[i].stuNum-1){
                    cout<<' ';
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
