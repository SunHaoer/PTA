#include<stdio.h>
int main()
{
    int i,repeat;
    scanf("%d",&repeat);
    for(i=1;i<=repeat;i++){
        int a,b,c,d,m;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a<b&&a<c&&a<d){
            m=a;}
            else if(b<a&&b<c&&b<d){
            m=b;}
            else if(c<a&&c<b&&c<d){
            m=c;}
            else if(d<a&&d<b&&d<c){
            m=d;}
             printf("min is %d\n",m);
    }
    return 0;
}
