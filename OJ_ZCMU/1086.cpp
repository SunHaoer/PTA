#include<stdio.h>
int main()
{
    int t,repeat;
    scanf("%d",&repeat);
    for(t=1;t<=repeat;t++){
       int i,m;

       scanf("%d",&m);
       for(i=2;i<=m/2;i++)
        if(m%i==0)
        break;
       if(i>m/2&&m!=1)
        printf("YES\n");
       else
        printf("NO\n");
    }
    return 0;
}
