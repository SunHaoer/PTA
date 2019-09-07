#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 2018;

struct Num {
    int a, b;       // a * X^b
    Num() {
        a = 0; b = 0;
    }
} num1[MAX], num2[MAX], num3[MAX], num4[MAX];

void Print(Num num[]) {
    bool flag = false;
    for(int i = MAX - 1; i >= 0; i--) {
        if(num[i].a != 0) {
            if(flag) cout<<" ";
            cout<<num[i].a<<" "<<num[i].b;
            flag = true;
        }
    }
    if(flag) cout<<endl;
    else cout<<"0 0"<<endl;
}

int main()
{
    int n1, n2;
    Num temp;
    cin>>n1;
    for(int i = 0; i < n1; i++) {
        cin>>temp.a>>temp.b;
        num1[temp.b] = temp;
    }
    cin>>n2;
    for(int i = 0; i < n2; i++) {
        cin>>temp.a>>temp.b;
        num2[temp.b] = temp;
    }
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            num3[num1[i].b + num2[j].b].a += num1[i].a * num2[j].a;
            num3[num1[i].b + num2[j].b].b = num1[i].b + num2[j].b;
        }
    }
    Print(num3);
    for(int i = 0; i < MAX; i++) {
        num4[i].a = num1[i].a + num2[i].a;
        num4[i].b = i;
    }
    Print(num4);
    return 0;
}
