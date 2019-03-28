#include<cstdio>
#include<algorithm>
using namespace std;
int year, n;

bool existed[10];
bool fun1() {
    int ans = 0, tempYear = year;
    fill(existed, existed + 10, false);
    if(tempYear < 1000) {
        existed[0] = true;
        ans++;
    }
    while(tempYear != 0) {
        int temp = tempYear % 10;
        if(!existed[temp]) {
            ans++;
        }
        existed[temp] = true;
        tempYear /= 10;
    }
    return ans == n;
}

int main()
{
    scanf("%d %d", &year, &n);
    int saveYear = year;
    while(true) {
        if(fun1()) {
            printf("%d %04d\n", year - saveYear, year);
            break;
        }
        year++;
    }
    return 0;
}
