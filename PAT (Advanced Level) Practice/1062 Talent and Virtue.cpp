#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Student{
    int id, t, v, grade;          //Talent, Virtue
};

vector<Student> stu[4];

bool cmp(Student a, Student b){
    if(a.grade!=b.grade) return a.grade>b.grade;
    else if(a.v!=b.v) return a.v>b.v;
    else return a.id<b.id;
}

int main()
{
    int n, l, h;
    scanf("%d%d%d", &n, &l, &h);         //总人数n, low, high
    for(int i=0; i<n; i++){
        Student temp;
        scanf("%d%d%d", &temp.id, &temp.v, &temp.t);
        temp.grade = temp.t + temp.v;
        if(temp.t<l||temp.v<l)      continue;       //不及格
        if(temp.t>=h&&temp.v>=h){               //t>h, v>h
            stu[0].push_back(temp);
        }
        else if(temp.t<h&&temp.v>=h){          //t<h, v>h
            stu[1].push_back(temp);
        }
        else if(temp.t<h&&temp.v<h&&temp.v>=temp.t){            //t<h, v<h, v>=t
            stu[2].push_back(temp);
        }
        else {
            stu[3].push_back(temp);
        }
    }
    printf("%d\n", stu[0].size()+stu[1].size()+stu[2].size()+stu[3].size());
    for(int i=0; i<4; i++){
        sort(stu[i].begin(), stu[i].end(), cmp);
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<stu[i].size(); j++){
            printf("%d %d %d\n", stu[i][j].id, stu[i][j].v, stu[i][j].t);
        }
    }
    return 0;
}
