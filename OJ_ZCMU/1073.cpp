#include<stdio.h>
int main()
{
    int i,repeat;
    scanf("%d",&repeat);
    for(i=0;i<repeat;i++){
        char c;
        c=getchar();
        if(c>='a'&&c<='z')
            printf("%c",c-32);
        else if(c>='A'&&c<='Z')
            printf("%c",c+32);
        else
            printf("%c",c);
    }
    return 0;
}
