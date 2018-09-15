#include<stdio.h>
#include<math.h>
int main()
{
    int i,repeat,j;
    double a,n,sum,b,c;
    scanf("%d",&repeat);
    for(i=1;i<=repeat;i++){
        scanf("%lf%lf",&a,&n);
        c=0;
        sum=0;
        for(j=1;j<=n;j++){
            b=pow(10,j-1);
            c=a*b+c;
            sum=c+sum;
        }
        printf("%.f\n",sum);
    }
    return 0;
}
