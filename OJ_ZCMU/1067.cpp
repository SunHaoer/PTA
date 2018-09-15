#include<stdio.h>
int main()
{
    int repeat,t;
    int a;

    scanf("%d",&repeat);
    for(t=1;t<=repeat;t++)
    {

        scanf("%d",&a);
        if(a<60){
            printf("Fail\n");
        }
        else{
            printf("Pass\n");
        }

    }
    return 0;

}
