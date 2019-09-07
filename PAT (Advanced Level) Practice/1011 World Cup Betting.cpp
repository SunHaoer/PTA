#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    double num, n[3] = {0};
    string flag[3], str[3] = {"W", "T", "L"};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>num;
            if(num>n[i]){
                n[i] = num;
                flag[i] = str[j];
            }
        }
    }
    for(int i=0; i<3; i++){
        cout<<flag[i]<<' ';
    }
    printf("%.2f", (n[0] * n[1] * n[2] * 0.65 - 1) * 2);
    return 0;
}
