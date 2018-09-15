#include<stdio.h>
int main()
{
    int t,m,n,x1,x2,judge;
    scanf("%d",&t);
    while(t--)
    {
        x1=1;
        x2=0;
        judge=0;
        scanf("%d%d",&m,&n);
        for(int i=1; i<=n; i++)
        {
            if( x1<=n && x1>=m )
                if(judge==0)
                {
                    printf("%d",x1);
                    judge=1;
                }
                else
                {
                    printf(" %d",x1);
                }
            x1=x1+x2;
            x2=x1-x2;
        }
        printf("\n");
    }
    return 0;
}
