#include<stdio.h>
int main()
{
    int repeat;
    int t;
    int a;
    double b;
    scanf("%d",&repeat);
    for(t=1;t<=repeat;t++)
    {

        scanf("%d",&a);

        switch(a){
        case 1: b=3.00;break;
        case 2: b=2.50;break;
        case 3: b=4.10;break;
        case 4: b=10.20;break;
        default : b=0.00;break;
        }
        printf("price=%.2f\n",b);
    }
    return 0;

}
