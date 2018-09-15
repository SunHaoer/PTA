#include<stdio.h>
int main()
{
    int repeat,t;
    scanf("%d",&repeat);
    for(t=0; t<repeat; t++)
    {
        int t,n,m;
        int chicken,rabbit;
        scanf("%d%d",&n,&m);
        chicken=rabbit=-1;
        if((4*n-m)%2==0)
        {
            chicken=(4*n-m)/2;
        }
        if(chicken>=0)
            rabbit=n-chicken;
        if(chicken<0 || rabbit<0)
            printf("No answer\n");
        else
            printf("%d %d\n",chicken,rabbit);
    }
    return 0;
}
