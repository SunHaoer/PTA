#include<stdio.h>
int main()
{
    int t,repeat;
    scanf("%d",&repeat);
    for(t=0;t<repeat;t++)
    {
        int n,x,m,c,d;
        scanf("%d",&m);
        c=m;
        d=m;
        scanf("%d",&x);
        while (c>0){
            for(n=0;n<m;n++)
            {
                printf("%d",x);
            }
            printf("\n");
            c--;
        }
        d--;
        if(d!=m){
            printf("\n");}
    }
    return 0;
}
