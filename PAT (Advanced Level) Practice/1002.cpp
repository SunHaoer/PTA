#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Anum{
    int n1, flag;
    double n2;
}A[15];

struct Bnum{
    int n1, flag;
    double n2;
}B[15];

struct Cnum{
    int n1;
    double n2;
}C[25];

bool cmp(Cnum a, Cnum b){
    return a.n1>b.n1;
}

int main()
{
    int k1, k2, ans = 0;
    cin>>k1;
    for(int i=0; i<k1; i++){
        cin>>A[i].n1>>A[i].n2;
        A[i].flag = 1;
    }
    cin>>k2;
    for(int i=0; i<k2; i++){
        cin>>B[i].n1>>B[i].n2;
        B[i].flag = 1;
    }
    for(int i=0; i<k1; i++){
        for(int j=0; j<k2; j++){
            if(A[i].n1==B[j].n1){
                C[ans].n1 = A[i].n1;
                C[ans].n2 = A[i].n2 + B[j].n2;
                A[i].flag = -1;
                B[j].flag = -1;
                if(C[i].n2==0) continue;
                ans++;
            }
        }
    }
    for(int i=0; i<k1; i++){
        if(A[i].flag==-1) continue;
        C[ans].n1 = A[i].n1;
        C[ans].n2 = A[i].n2;
        ans++;
    }
    for(int i=0; i<k2; i++){
        if(B[i].flag==-1) continue;
        C[ans].n1 = B[i].n1;
        C[ans].n2 = B[i].n2;
        ans++;
    }
    sort(C, C+ans, cmp);
    cout<<ans;
    for(int i=0; i<ans; i++){
        cout<<' '<<C[i].n1<<' ';
        printf("%.1f", C[i].n2);
    }
    return 0;
}
