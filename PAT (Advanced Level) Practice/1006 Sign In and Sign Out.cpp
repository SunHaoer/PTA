#include<iostream>
#include<algorithm>
using namespace std;

struct student{
    string id;
    string time1;
    string time2;
}stu[101];

bool cmp1(student a, student b){
    return a.time1<b.time1;
}

bool cmp2(student a, student b){
    return a.time2>b.time2;
}

int main()
{
    int repeat;
    cin>>repeat;
    for(int i=0; i<repeat; i++){
        cin>>stu[i].id>>stu[i].time1>>stu[i].time2;
    }
    sort(stu, stu+repeat, cmp1);
    cout<<stu[0].id<<' ';
    sort(stu, stu+repeat, cmp2);
    cout<<stu[0].id;
    return 0;
}
