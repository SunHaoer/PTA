#include<cstdio>
using namespace std;
const int MAX = 1010;

struct Book {
    int index, cntTime, lastTime;
    char ch;
    Book() {
        lastTime = 0;
    }
} book[MAX];

int main()
{
    int repeat, ans = 0, cnt = 0;
    scanf("%d", &repeat);
    while(repeat > 0) {
        int index, hh, mm;
        char ch;
        scanf("%d %c %d:%d", &index, &ch, &hh, &mm);
        if(index == 0) {
            repeat--;
            if(ans != 0) printf("%d %.0f\n", ans, (cnt * 1.0 / ans * 1.0));
            else printf("0 0\n");
            cnt = 0, ans = 0;
        } else {
            book[index].index = index;
            if(ch == 'S') {
                book[index].lastTime = hh * 60 + mm;
            }
            if(ch == 'E' && book[index].ch == 'S') {
                cnt += (hh * 60 + mm - book[index].lastTime);
                book[index].lastTime = 0;
                ans++;
            }
            book[index].ch = ch;
        }

    }
    return 0;
}
