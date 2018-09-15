#include<stdio.h>
int main()
{
    int i,repeat;
    scanf("%d",&repeat);
    for(i=1;i<=repeat;i++){
        int begin,end,Celsius,Fahrenheit;
        scanf("%d%d",&begin,&end);
        printf("Celsius Fahrenheit\n");
        for(Celsius=begin;Celsius<=end;Celsius++){
            Fahrenheit = 32 + Celsius * 9 / 5;
            printf("%d%10d\n",Celsius,Fahrenheit);
        }
    }
    return 0;
}
