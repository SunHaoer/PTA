#include<iostream>
#include<vector>
using namespace std;
vector<string> vt1, vt2;

int main()
{
    int n;
    cin>>n;
    for(int j = 0; j < n; j++) {
        string str, str1, str2;
        cin>>str1>>str2;
        str = str2;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '1') {
                str[i] = '@';
            } else if(str[i] == '0') {
                str[i] = '%';
            } else if(str[i] == 'l') {
                str[i] = 'L';
            } else if(str[i] == 'O') {
                str[i] = 'o';
            } else {        // Ã»ÎÊÌâ

            }
        }
        if(str != str2) {
            vt1.push_back(str1);
            vt2.push_back(str);
        }
    }
    if(vt1.size() != 0) {
        cout<<vt1.size()<<endl;
        for(int i = 0; i < vt1.size(); i++) {
            cout<<vt1[i]<<" "<<vt2[i]<<endl;
        }
    } else if(n == 1) {
        cout<<"There is 1 account and no account is modified"<<endl;
    } else {
        cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    }
    return 0;
}
