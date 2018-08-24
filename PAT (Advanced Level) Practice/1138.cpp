#include<cstdio>
using namespace std;
const int MAX = 50010;
int preOrder[MAX], inOrder[MAX], post[MAX];

int fun1(int preL, int preR, int inL, int inR) {
    int index = inL;
    while(inOrder[index] != preOrder[preL]) {
        index++;
    }
    if(index == preL) {     // 没有左子树
        return fun1(preL + 1, preR, inL + 1, inR);
    } else {
        return preOrder[index];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {    // 输入pre
        scanf("%d", &preOrder[i]);
    }
    for(int i = 0; i < n; i++) {    // 输入in
        scanf("%d", &inOrder[i]);
    }
    int num = fun1(0, n - 1, 0, n -  1);     // 求post
    printf("%d", num);      // 输出
    return 0;
}

