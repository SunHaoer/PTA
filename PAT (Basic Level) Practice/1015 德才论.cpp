#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct student {
    int id;
    int a;      //��
    int b;      //��
    int c;      //��
};

vector<student> stu[4];

bool cmp(student a, student b) {
    if(a.c != b.c) return a.c > b.c;
    else if(a.a != b.a) return a.a > b.a;
    else return a.id < b.id;
}

int main()
{
    int N, L, H, n = 0;
    student s;
    scanf("%d%d%d", &N, &L, &H);                       // ���뿼����N,¼ȡ��L,�����H
    for(int i = 0; i < N; i++) {
        scanf("%d%d%d", &s.id, &s.a, &s.b);
        s.c = s.a + s.b;
        if(s.a < L || s.b < L) continue;               // ��¼ȡ
        else if( (s.a >= H) && (s.b >= H) ) {          // �²ż汸
            stu[0].push_back(s);
        } else if( (s.a >= H) && (s.b < H) ) {         // ��ʤ��
            stu[1].push_back(s);
        } else if( (s.a < H) && (s.b < H) && (s.a >= s.b) ) {       // �ŵ¼���
            stu[2].push_back(s);
        } else {
            stu[3].push_back(s);
        }
        n++;
    }
    for(int i = 0; i < 4; i++) {
        sort(stu[i].begin(), stu[i].end(), cmp);
    }
    printf("%d\n", n);
    for(int j = 0; j < 4; j++) {
        for(int i = 0; i < stu[j].size(); i++) {
            printf("%d %d %d\n", stu[j][i].id, stu[j][i].a, stu[j][i].b);
        }
    }
    return 0;
}
