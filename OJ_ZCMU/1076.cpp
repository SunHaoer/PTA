#include<stdio.h>
#include<math.h>
int main()
{
    int i,repeat;
    scanf("%d",&repeat);
    for(i=1;i<=repeat;i++){
        double x,n,m;
        scanf("%lf%lf",&x,&n);
        m=pow(x,n);
        printf("%.2f\n",m);
    }
    return 0;
}
