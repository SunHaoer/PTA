#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Student {
    long long id;
    int score;
    int room;       // 考场
    int rank1;      // 考场排名
    int rank2;      // 总排名
};
vector<Student> stu;

bool cmp(Student a, Student b) {
    if(a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}

int main()
{
    int n, k, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        ans += k;
        for(int j = 0; j < k; j++) {
            Student temp;
            scanf("%lld%d", &temp.id, &temp.score);
            temp.room = i + 1;
            stu.push_back(temp);
        }
        sort(stu.end() - k, stu.end(), cmp);
        stu[ans - k].rank1 = 1;
        for(int j = ans - k + 1; j < ans; j++) {
            if(stu[j].score == stu[j - 1].score) stu[j].rank1 = stu[j - 1].rank1;
            else stu[j].rank1 =  j - (ans - k) + 1;
        }
    }
    sort(stu.begin(), stu.end(), cmp);
    stu[0].rank2 = 1;
    for(int i = 1; i < stu.size(); i++) {
        if(stu[i].score == stu[i - 1].score) stu[i].rank2 = stu[i - 1].rank2;
        else stu[i].rank2 = i + 1;
    }
    printf("%d\n", ans);
    for(int i = 0; i < stu.size(); i++) {
        printf("%013lld %d %d %d\n", stu[i].id, stu[i].rank2, stu[i].room, stu[i].rank1);
    }
    return 0;
}
