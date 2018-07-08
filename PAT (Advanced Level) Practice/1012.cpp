#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int sub;       //��Ŀ
int Rank[10000000][4];       //rank[id][sub]=rank
char course[4] = { 'A', 'C', 'M', 'E' };

struct Student{
    int id, grade[4];
}stu[2010];

bool cmp(Student a, Student b){
    return a.grade[sub]>b.grade[sub];
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>stu[i].id>>stu[i].grade[1]>>stu[i].grade[2]>>stu[i].grade[3];
        stu[i].grade[0] = ( stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3] ) / 3.0 + 0.5;
    }
    for(sub=0; sub<4; sub++){
        sort(stu, stu+n, cmp);        //����
        Rank[stu[0].id][sub] = 1;        //��һ��
        for(int i=1; i<n; i++){
            if(stu[i].grade[sub]==stu[i-1].grade[sub]){            //��ǰһ��������ͬ
                Rank[stu[i].id][sub] = Rank[stu[i-1].id][sub];
            }
            else{
                Rank[stu[i].id][sub] = i + 1;
            }
        }
    }
    for(int i=0; i<m; i++){       //��ѯ
        int id, k=0;
        cin>>id;
        for(sub=0; sub<4; sub++){
            if(Rank[id][sub]<Rank[id][k]){
                k = sub;
            }
        }
        if(Rank[id][k]==0){
            cout<<"N/A"<<endl;
        }
        else{
            cout<<Rank[id][k]<<' '<<course[k]<<endl;
        }
    }
    return 0;
}
