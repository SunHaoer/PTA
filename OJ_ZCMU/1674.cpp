#include<stdio.h>
int main(){
    double x,y,z;
    double jia,yi,bing;
    while(scanf("%lf %lf %lf",&x,&y,&z)!=EOF){
    bing=(x-y)/2;
    jia=(x-bing+z)/2;
    yi=jia-z;
    if(bing<0||jia<0||yi<0)
        printf("wangwangwang\n");
    else if(bing-(int)bing!=0||jia-(int)jia!=0||yi-(int)yi!=0)
        printf("wangwangwang\n");
    else
        printf("%.f %.f %.f\n",jia,yi,bing);
    }
return 0;
}
