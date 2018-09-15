#include<stdio.h>
int main()
{
    int i,repeat;
    scanf("%d",&repeat);
    for(i=0;i<repeat;i++){
        double a,b,c,sum;
        int t,n;
        scanf("%d",&n);
        a=1.00;
        b=2.00;
        sum=0;
        for(t=0;t<n;t++){
            sum=sum+b/a;
            b=a+b;
            a=b-a;
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
