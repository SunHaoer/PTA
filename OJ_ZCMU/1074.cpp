#include<stdio.h>
int main()
{
    int i,repeat;
    scanf("%d",&repeat);
    for(i=0;i<repeat;i++){
        int n;
        float a,b,sum;
        scanf("%d",&n);
        a=1;
        sum=0;
        while(n>0){
            b=1/a;
            sum=sum+b;
            a++;
            n--;
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
