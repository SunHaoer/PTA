#include<stdio.h>
int main()
{
    int i,repeat;
    double sum;
    scanf("%d",&repeat);
    for(i=0;i<repeat;i++){
        double n,t;
        scanf("%lf",&n);
        sum=1;
        for(t=1;t<=n;t++){
            sum=sum*t;
        }
        printf("%.0f\n",sum);
    }
    return 0;
}
