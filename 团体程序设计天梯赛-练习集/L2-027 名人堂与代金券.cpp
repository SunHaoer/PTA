#include<iostream>
#include<algorithm>
using namespace std;
const  int MAX = 10010;

struct Student {
    string name;
    int score, ranked;
} stu[MAX];

bool cmp(Student a, Student b) {
    if(a.score != b.score) return a.score > b.score;
    else return a.name < b.name;
}

int main()
{
    int n, g, k, cnt = 0;
    cin>>n>>g>>k;
    for(int i = 0; i < n; i++) {
        cin>>stu[i].name>>stu[i].score;
        if(stu[i].score >= g) cnt += 50;
        else if(stu[i].score >= 60) cnt += 20;
    }
    cout<<cnt<<endl;
    sort(stu, stu + n, cmp);
    stu[0].ranked = 1;
    for(int i = 1; i <= n; i++) {
        if(stu[i].score == stu[i - 1].score) stu[i].ranked = stu[i - 1].ranked;
        else stu[i].ranked = i + 1;
        if(stu[i].ranked > k) break;
    }
    for(int i = 0; i <= n; i++) {
        if(stu[i].ranked > k) break;
        cout<<stu[i].ranked<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
    }
    return 0;
}
