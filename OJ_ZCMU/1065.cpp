#include<stdio.h>
int main()
{

        int a,b,c,d,m;
        int w,e,r;
        scanf("%d",&m);
        d=(m%10+9)%10;
        r=m/10;
        c=(r%10+9)%10;
        e=r/10;
        b=(e%10+9)%10;
        w=e/10;
        a=(w%10+9)%10;
        printf("The encrypted number is %d%d%d%d",c,d,a,b);

    return 0;
}
