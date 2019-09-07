#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct number{
    int a;
    double b;
}A[15], B[15], C[110], D[110];

bool cmp(number n1, number n2){
    return n1.a>n2.a;
}

int main()
{
    int k1, k2, ans = 0, num = 0;
    cin>>k1;
    for(int i=0; i<k1; i++){
        cin>>A[i].a>>A[i].b;
    }
    cin>>k2;
    for(int i=0; i<k2; i++){
        cin>>B[i].a>>B[i].b;
        for(int j=0; j<k1; j++){
            C[ans].a = B[i].a + A[j].a;
            C[ans].b = B[i].b * A[j].b;
            ans++;
        }
    }
    for(int i=0; i<ans; i++){
        for(int j=i+1; j<ans; j++){
            if(C[i].a==C[j].a){
                C[i].b = C[i].b + C[j].b;
                C[j].a = -1;
            }
        }
    }
    for(int i=0; i<ans; i++){
        if(C[i].a==-1||C[i].b==0) continue;
        else{
            D[num++] = C[i];
        }
    }
    sort(D, D+num, cmp);
    cout<<num;
    for(int i=0; i<num; i++){
        printf(" %d %.1f", D[i].a, D[i].b);
    }
    return 0;
}
