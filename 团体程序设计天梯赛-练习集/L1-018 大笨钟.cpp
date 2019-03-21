#include<cstdio>
using namespace std;

int main()
{
    int hh, mm;
    scanf("%d:%d", &hh, &mm);
    if(mm != 0) hh++;
    if(hh > 12) {
        for(int i = 0; i < hh - 12; i++) {
            printf("Dang");
        }
    } else {
        if(mm != 0) hh--;
        printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
    }
    return 0;
}
