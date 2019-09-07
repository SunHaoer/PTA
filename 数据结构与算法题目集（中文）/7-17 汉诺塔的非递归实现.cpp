#include<cstdio>
using namespace std;

void Move(char a, char c) {
    printf("%c -> %c\n", a, c);
}

void hanoi(int n, char a, char b, char c) {
    if(n == 1) {
        Move(a, c);
    } else {
        hanoi(n - 1, a, c, b);      // 以c为中介, n-1个盘子放到b
        Move(a, c);                 // 移动最大盘子
        hanoi(n - 1, b, a, c);      // 以a为中介, n-1个盘子放到c
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 'a', 'b', 'c');
    return 0;
}


/*
 *  用cin/cout测试点3运行超时(400ms), printf耗时148ms, 差距。。。
 */
