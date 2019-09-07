#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
const int MAX = 50;
int pre[MAX], in[MAX], post[MAX];
int n, num = 0;

struct Node{
    int data;
    Node* lchild;
    Node* rchild;
};

void print(Node* root){
    printf("%d", root->data);
    num++;
    if(num<n) printf(" ");
    else printf("\n");
    return;
}

Node* create(int preL, int preR, int inL, int inR) {
    if(preL>preR) return NULL;
    Node* root = new Node;
    root->data = pre[preL];
    int k;
    for(k=inL; k<=inR; k++) {
        if(in[k]==pre[preL]) break;
    }
    int numLeft = k - inL;
    root->lchild = create(preL+1, preL+numLeft, inL, k-1);
    root->rchild = create(preL+numLeft+1, preR, k+1, inR);
    return root;
}

void postOrder(Node* root){
    if(root==NULL) return;
    if(root->lchild!=NULL) postOrder(root->lchild);
    if(root->rchild!=NULL) postOrder(root->rchild);
    print(root);
    return;
}

int main()
{
    scanf("%d", &n);
    char str[5];
    stack<int> st;
    int x, preIndex = 0, inIndex  = 0;
    for(int i=0; i<2*n; i++) {
        scanf("%s", str);
        if(strcmp(str, "Push")==0) {        // ÈëÕ»
            scanf("%d", &x);
            pre[preIndex++] = x;
            st.push(x);
        }
        else {                              // ³öÕ»
            in[inIndex++] = st.top();
            st.pop();
        }
    }
    Node* root = create(0, n-1, 0, n-1);
    postOrder(root);
    return 0;
}
