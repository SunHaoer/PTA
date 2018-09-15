#include<stdio.h>
int main(void)
{
    int n,ri;
    double mask;
    double sum;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        sum=0;
        for(ri=1;ri<=n;ri++)
        {
            scanf("%lf",&mask);
             sum=sum+mask;
        }
        printf("%.2f\n",sum/n);
    }
        return 0;
}
