#include<stdio.h>
#include<math.h>
int main()
{
    int repeat,t,a,b,c;
    double s,p;
    scanf("%d",&repeat);
    for(t=1;t<=repeat;t++){
        scanf("%d%d%d",&a,&b,&c);
        if(a+b>c&&a+c>b&&c+b>a)
    {p=(a+b+c)/2.0;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("area=%.2f; ",s);
    printf("perimeter=%.2f\n",p*2);}
        else
            printf("These sides do not correspond to a valid triangle\n");
    }
    return 0;
}
