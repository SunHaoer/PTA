#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 500;
string strs[MAX];


int main()
{
    int n;
    bool flag = true;
    string str = "";
    cin>>n;
    getchar();
    for(int i = 0; i < n; i++){     // ����
        getline(cin, strs[i]);
    }
    for(int i = 0; i < MAX; i++) {    // �����׺
        if(i == strs[0].size()) break;
        char ch1 = strs[0][strs[0].size() - 1 - i];
        for(int j = 1; j < n; j++) {    // ���ȵ���
            if(i == strs[j].size()) {
                flag = false;
                break;
            }
            char ch2 = strs[j][strs[j].size() - 1 - i];
            if(ch1 != ch2) {            // ��һ��
                flag = false;
                break;
            }
        }
        if(flag) str += ch1;          // ����
        else break;            // ����ѭ��
    }
    reverse(str.begin(), str.begin() + str.size());     // ��ת
    if(str != "") cout<<str<<endl;
    else cout<<"nai"<<endl;
    return 0;
}
