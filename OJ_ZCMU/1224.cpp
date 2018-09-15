#include <stdio.h>
int main()
{
    int n,i;
    float sum,x,m,max,min;
    while((scanf("%d",&n))!=EOF)
    {
        scanf("%f",&m);
        max=min=sum=m;
        for (i=1; i<n; i++)
        {
            scanf("%f",&m);
            sum=sum+m;
            if (m>max)
            {
                max=m;
            }
            else if (m<min)
            {
                min=m;
            }
        }
        x=(sum-max-min)/(n-2);
        printf("%1.2f\n",x);
    }
    return 0;
}
