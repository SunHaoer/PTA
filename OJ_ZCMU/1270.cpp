#include<stdio.h>
int main()
{
    int n;
    int a,b,c,d;
    scanf("%d",&n);
    d=n%10+9-10;
    n=n/10;
    c=n%10+9-10;
    n=n/10;
    b=n%10+9-10;
    n=n/10;
    a=n%10+9-10;
    n=n/10;
    printf("The encrypted number is %d%d%d%d\n",c,d,a,b);
    return 0;
}
