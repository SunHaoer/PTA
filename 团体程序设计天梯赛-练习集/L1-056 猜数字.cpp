#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX = 10010;

struct Student {
    string name;
    int num;
    double ans;
    Student() {
        num = 0;
        ans = 0;
    }
} stu[MAX];

bool cmp(Student a, Student b) {
    return a.ans < b.ans;
}

int main()
{
    int n;
    double cnt = 0;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>stu[i].name>>stu[i].num;
        cnt += stu[i].num;
    }
    cnt = cnt / n / 2;
    for(int i = 0; i < n; i++) {
        stu[i].ans = abs(cnt - stu[i].num);
    }
    sort(stu, stu + n, cmp);
    cout<<int(cnt)<<" "<<stu[0].name<<endl;
    return 0;
}
