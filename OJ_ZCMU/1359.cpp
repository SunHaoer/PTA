#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=-1){
    if(n>100){
        printf("We have HAMBERGS\n");
        scanf("%d",&n);
    }
    else if(n<100){
        printf("NO\n");
        scanf("%d",&n);
    }
    else if(n=100){
        printf("Hamburg time\n");
        scanf("%d",&n);
    }
    }
    return 0;
}
