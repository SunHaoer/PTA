#include<stdio.h>
int main()
{
    int repeat,t;
    scanf("%d",&repeat);
    for(t=0;t<repeat;t++){
         int a,b,c,t;
         scanf("%d%d%d",&a,&b,&c);
         if(a>b) {
             t=a;a=b;b=t;}
        if(b>c) {
            t=b;b=c;c=t;}
        if(a>b) {
            t=a;a=b,b=t;}
        printf("%d %d %d\n",c,b,a);
    }
    return 0;
}
