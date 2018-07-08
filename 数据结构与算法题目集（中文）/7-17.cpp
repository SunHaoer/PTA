#include<cstdio>
using namespace std;

void Move(char a, char c) {
    printf("%c -> %c\n", a, c);
}

void hanoi(int n, char a, char b, char c) {
    if(n == 1) {
        Move(a, c);
    } else {
        hanoi(n - 1, a, c, b);      // ��cΪ�н�, n-1�����ӷŵ�b
        Move(a, c);                 // �ƶ��������
        hanoi(n - 1, b, a, c);      // ��aΪ�н�, n-1�����ӷŵ�c
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
 *  ��cin/cout���Ե�3���г�ʱ(400ms), printf��ʱ148ms, ��ࡣ����
 */
