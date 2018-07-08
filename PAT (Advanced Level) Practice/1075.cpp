#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Student{
    int id, score[6], mark, ac, rankn;
    bool flag;
    Student(){
        id = 0;
        for(int i=0; i<6; i++){            //��ʼ����Ϊ-1
            score[i] = -1;
        }
        mark = 0;
        ac = 0;
    }
}stu[maxn];

bool cmp(Student a, Student b){
    if(a.flag!=b.flag) return a.flag > b.flag;          //��flag==true�ķ���ǰ��
    else if(a.mark!=b.mark) return a.mark > b.mark;
    else if(a.ac!=b.ac) return a.ac > b.ac;
    else return a.id < b.id;
}

int main()
{
    int n, k, m, ans = 0, score[6];
    scanf("%d%d%d", &n, &k, &m);    //��������n, ������k, ���ύ��m
    for(int i=1; i<=k; i++){
        scanf("%d", &score[i]);
    }
    for(int i=0; i<m; i++){
        int id1, id2, temp;
        scanf("%d%d%d", &id1, &id2, &temp);         //ѧ��id1, ��Ŀid2, ����temp
        stu[id1].id = id1;
        if(temp!=-1) stu[id1].flag = true;          //�гɼ�
        if(temp==-1) temp = 0;
        if(temp>stu[id1].score[id2]){               //��߷��滻, �����ܷ�
            if(stu[id1].score[id2]!=-1){
                stu[id1].mark -= stu[id1].score[id2];
            }
            stu[id1].score[id2] = temp;
            stu[id1].mark += stu[id1].score[id2];
            if(stu[id1].score[id2]==score[id2]){
                stu[id1].ac++;
            }
        }
    }
    for(int i=0; i<maxn; i++){
        if(stu[i].flag==true) ans++;        //ͳ������������
    }
    sort(stu, stu+maxn, cmp);
    stu[0].rankn = 1;
    for(int i=1; i<ans; i++){
        if(stu[i].mark==stu[i-1].mark) {
            stu[i].rankn = stu[i-1].rankn;
        }
        else{
            stu[i].rankn = i + 1;
        }
    }
    for(int i=0; i<ans; i++){
        printf("%d %05d %d", stu[i].rankn, stu[i].id, stu[i].mark);
        for(int j=1; j<=k; j++){
            if(stu[i].score[j]!=-1){
                printf(" %d", stu[i].score[j]);
            }
            else {
                printf(" -");
            }
        }
        printf("\n");
    }
    return 0;
}

