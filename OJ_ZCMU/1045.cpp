#include<cstdio>
using namespace std;

int main()
{
    int m, n;
    while(scanf("%d%d", &m, &n)!=EOF){
        double x = 100 - (28*n*100) / (m * 1.0);
        if(x<0){
            printf("impossible\n");
        }
        else {
            printf("%.2f%%\n", x);
        }
    }
    return 0;
}
