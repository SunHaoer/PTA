#include<stdio.h>
int main()
{
    int repeat,i,u;

    scanf("%d",&repeat);
    for(i=1;i<=repeat;i++){
        double sum,n;
        sum=0;
        scanf("%lf",&n);
        for(u=1;u<=n;u++){
            if(u%2==0){
                sum=sum-1.0/u;
            }
            else{
                sum=sum+1.0/u;
            }
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
