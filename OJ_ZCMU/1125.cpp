#include<cstdio>
using namespace std;

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF){
        int a[N];
        a[0]=97;
        for(int i=1;i<N;i++){
            a[i]=a[i-1]+1;
        }
        for(int i=0;i<N;i++){
            printf("a");
            for(int j=0;j<N-i-1;j++){
                printf(" ");
            }
            for(int j=0;j<i+1;j++){
                printf("%c",a[i]+j-i);
            }
            printf("\n");
        }
        printf("\n");
    };
    return 0;
}
