#include <stdio.h>
#include <math.h>
int main()
{
    int n,k,i;
    while(~scanf("%d",&n))
    {
        k=(int)sqrt(n);
        for(i=2; i<=k; i++)
        {
            if(n%i==0)
            {
                break;
            }
        }
        if(i>k&&n!=1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
