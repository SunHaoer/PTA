#include<iostream>
using namespace std;

int main()
{
    string str;
    int num[10] = {0};
    cin>>str;
    for(int i = 0; i < str.size(); i++) {
        num[str[i] - '0']++;
    }
    for(int i = 0; i < 10; i++) {
        if(num[i] == 0) continue;
        cout<<i<<':'<<num[i]<<endl;
    }
    return 0;
}
