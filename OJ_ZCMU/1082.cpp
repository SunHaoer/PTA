#include<stdio.h>
int main()
{
    int i,repeat;
    scanf("%d",&repeat);
    for(i=0; i<repeat; i++)
    {
        int n,t,max;
        scanf("%d",&n);
        scanf("%d",&max);
        while(n>1)
        {
            scanf("%d",&t);
            if(t>=max)
            {
                max=t;
            }
            n--;

        }
        printf("%d\n",max);
    }
    return 0;
}
