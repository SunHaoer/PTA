#include<iostream>
using namespace std;

int main()
{
    string str1, str2 = "";
    int num, temp = 0, i = 0, j = 0;
    cin>>str1>>num;
    for(i = 0; i < str1.size(); i++) {
        int n = str1[i] - '0' + 10 * temp;
        str2 += ((n / num) + '0');
        temp = n % num;
    }
    for(int i = 0; i < str2.size(); i++) {
        if(i == 0 && str2[i] == '0' && str2.size() != 1) continue;
        cout<<str2[i];
    }
    cout<<' '<<temp<<endl;
    return 0;
}
