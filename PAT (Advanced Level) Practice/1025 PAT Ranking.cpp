#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct student{
    long long id;
    int mark;
    int room;
    int local_rank;
    int all_rank;
};
vector<student> stu;

bool cmp(student a, student b){
    if(a.mark!=b.mark) return a.mark>b.mark;
    else return a.id<b.id;
}

int main()
{
    int n;
    student peo;
    cin>>n;            //考场数量
    for(int i=1; i<=n; i++){
        int k;
        cin>>k;         //每个考场的人数
        for(int j=0; j<k; j++){
            cin>>peo.id>>peo.mark;
            peo.room = i;
            peo.local_rank = 0;
            stu.push_back(peo);
        }
        sort(stu.end()-k, stu.end(), cmp);
        stu[stu.size()-k].local_rank = 1;
        for(int j=stu.size()-k; j<stu.size(); j++){
            if(stu[j].mark==stu[j-1].mark&&stu[j].room==stu[j-1].room){              //同一个房间才行
                stu[j].local_rank = stu[j-1].local_rank;
            }
            else stu[j].local_rank = j + 1 - (stu.size() - k);
        }
    }
    sort(stu.begin(), stu.end(), cmp);
    stu[0].all_rank = 1;
    for(int i=1; i<stu.size(); i++){
        if(stu[i].mark==stu[i-1].mark){
            stu[i].all_rank = stu[i-1].all_rank;
        }
        else {
            stu[i].all_rank = i + 1;
        }
    }
    cout<<stu.size()<<endl;
    for(int i=0; i<stu.size(); i++){
        printf("%013lld", stu[i].id);
        cout<<' '<<stu[i].all_rank<<' '<<stu[i].room<<' '<<stu[i].local_rank<<endl;
    }
    return 0;
}
