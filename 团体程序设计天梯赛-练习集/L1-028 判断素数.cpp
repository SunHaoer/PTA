#include<cstdio>
#include<cmath>
using namespace std;

bool fun1(int num) {
    if(num == 1) return false;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main()
{
    int n, num;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(fun1(num)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
