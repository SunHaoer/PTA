#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 50;
int preOrder[MAX], postOrder[MAX];
vector<int> inOrder;
bool isUnique = true;

void getIn(int preL, int preR, int postL, int postR) {
    if(preL == preR) {         // 完了
        inOrder.push_back(preOrder[preL]);
        return;
    }
    if(preOrder[preL] == postOrder[postR]) {
        int index = preL + 1;
        while(index <= preR && preOrder[index] != postOrder[postR - 1]) {   // postOrder[postR - 1]为下一根节点
            index++;
        }
        if(index - preL > 1) {
            getIn(preL + 1, index - 1, postL, postL + (index - preL - 1) - 1);
        } else {            // 这个根下不止一个节点, 故无法判断是左孩子还是右孩子
            isUnique = false;
        }
        inOrder.push_back(postOrder[postR]);
        getIn(index, preR, postL + (index - preL - 1), postR - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {    // 输入pre[] 根左右
        scanf("%d", &preOrder[i]);
    }
    for(int i = 0; i < n; i++) {    // 输入post[] 左右根
        scanf("%d", &postOrder[i]);
    }
    getIn(0, n - 1, 0, n - 1);
    if(isUnique) {          // 输出
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for(int i = 0; i < inOrder.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", inOrder[i]);
    }
    printf("\n");
    return 0;
}
