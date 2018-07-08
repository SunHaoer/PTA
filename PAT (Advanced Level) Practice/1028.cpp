#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int c;

struct Student{
    char name[9];
    int id, grade;
}stu[maxn];

bool cmp(Student a, Student b){
    if(c==1) {
        return a.id<b.id;
    }
    if(c==2) {
        int s = strcmp(a.name, b.name);
        if(s!=0) return s<0;
        else return a.id<b.id;
    }
    if(c==3) {
        if(a.grade!=b.grade) return a.grade<b.grade;
        else a.id<b.id;
    }
}

int main()
{
    int n;
    scanf("%d%d", &n, &c);
    for(int i=0; i<n; i++){
        scanf("%d%s%d", &stu[i].id, &stu[i].name, &stu[i].grade);
    }
    sort(stu, stu+n, cmp);
    for(int i=0; i<n; i++){
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    }
    return 0;
}
