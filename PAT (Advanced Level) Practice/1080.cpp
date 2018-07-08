#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
    int ge, gi, grade, r, id, cho[6];       //���Գɼ�ge, ���Գɼ�gi, �ܷ�grade, ����r, ���id, ־Ըcho[6]
}stu[40010];

struct School{
    int quota, stuNum, id[40010], lastAdmit;       //�����ܶ��quota, ��ǰ��������stuNum, ����ѧ�����id, ���һ��ѧ�����lastAdmit
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
    cin>>n>>m>>k;          //���뿼������n, ѧУ��m, ־Ը��k
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
    for(int i=0; i<n; i++){          //ÿ������
        for(int j=0; j<k; j++){       //������ÿ��־Ը
            int choice = stu[i].cho[j];       //����i�ĵ�j��־Ը
            int num = sch[choice].stuNum;       //��ѧУ��ǰ��������
            int last = sch[choice].lastAdmit;     //��ѧУ�����һ������
            if(num<sch[choice].quota||(last!=-1&&stu[i].r==stu[last].r)){           //¼ȡ
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
