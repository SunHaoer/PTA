#include <stdio.h>
int main()
{
    int t,repeat;
    scanf("%d",&repeat);
    for(t=0;t<repeat;t++){
        int i,temp,flag,j=0;
    int m,n;
    long sum=0;
    scanf("%d%d",&m,&n);
    for(temp=m;temp<n;temp++)
    {
        if(temp==1)
            temp++;
        flag=1;
        for(i=2;i<temp;i++)
        {
            if(temp%i==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            sum+=temp;
            j++;
        }
    }
    printf("count=%d,sum=%d\n",j,sum);
    }

    return 0;
}
