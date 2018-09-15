#include<stdio.h>
#include<math.h>
int main()
{
    int i,repeat;
    scanf("%d",&repeat);
    for(i=0;i<repeat;i++){
        double a,b,c,sum;
        int f=1;
        double k;
        scanf("%lf",&k);
        sum=0;
        a=1.0;
        c=1.0;
        while(fabs(c)>=k){
            sum=sum+c;
            f=-f;
            a=a+2.0;
            c=f*1.0/a;
        }
        printf("%.6lf\n",sum);
    }
    return 0;
}
