#include<stdio.h>
int main()
{
    int repeat;
    int t;
    scanf("%d",&repeat);
    for(t=0;t<repeat;t++)
    {
        int x,y;
        scanf("%d",&x);
        if(x>0)
        {
            y=1;
        }
        else if(x==0)
        {
            y=0;
        }
        else
        {
            y=-1;
        }
        printf("%d\n",y);
    }
    return 0;
}
