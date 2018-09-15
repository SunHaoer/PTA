#include<iostream>
using namespace std;

int main()
{
    cout<<"#include <stdio.h>"<<endl;
    cout<<"int main()"<<endl;
    cout<<"{"<<endl;
    cout<<"    int a,b;"<<endl;
    cout<<"    while(scanf("<<'"'<<"%d%d"<<'"'<<",&a,&b) != EOF)"<<endl;
    cout<<"        printf("<<'"'<<"%d\\n"<<'"'<<",a+b);"<<endl;
    cout<<"    return 0;"<<endl;
    cout<<"}"<<endl;
    return 0;
}
