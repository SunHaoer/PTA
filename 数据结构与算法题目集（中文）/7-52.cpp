#include<iostream>
using namespace std;
const int MAX = 10000010;
int hashTable[MAX];
bool flag = false;

int main()
{
    int data;
    while(cin>>data) {
        if(data == -1) break;
        hashTable[data]++;
    }
    while(cin>>data) {
        if(data == -1) break;
        if(hashTable[data] != 0) {
            if(flag == true) cout<<" ";
            cout<<data;
            hashTable[data]--;          // ���˺ܾ�, ����©�˴ʾ�, ������
            flag = true;
        }
    }
    if(flag == false) cout<<"NULL";
    cout<<endl;
    return 0;
}
