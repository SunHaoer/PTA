#include<stdio.h>
int main()
{
    int n;
    int a,b,c;
    scanf("%d",&n);
    while (n!=0){
        if(n/100>0&&n/100<10){
     a=n%10;
    b=n/10%10;
    c=n/100;
    if(n==a*a*a+b*b*b+c*c*c){
        printf("YES\n");
    }
    else
        printf("NO\n");
    }
    scanf("%d",&n);
    }
    return 0;
}
