#include<stdio.h>
int main()
{
    int repeat,t;
    scanf("%d",&repeat);
    for(t=0;t<repeat;t++){
        int i,n,sum;
        scanf("%d",&n);
        sum=0;
        for(i=0;i<=n;i++){
            sum=sum+i;
        }
        printf("%d\n",sum);
    }
    return 0;
}
