#include<stdio.h>
double fact(int n);
int main()
{
    int i,repeat;
    scanf("%d",&repeat);
    for(i=0;i<repeat;i++){
        int n,t;
        double s;
        scanf("%d",&n);
        s=0;
        for(t=1;t<=n;t++){
            s=s+fact(t);
        }
        printf("%.4lf\n",s);
    }
    return 0;
}

double fact (int n)
{
     double t,sum,result;
     sum=1;
     for(t=1;t<=n;t++){
         sum=sum*t;
     }
     result=1.0/sum;
     return result;
}
