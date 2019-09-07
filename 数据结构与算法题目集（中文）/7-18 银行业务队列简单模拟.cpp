#include<iostream>
#include<queue>
using namespace std;
queue<int> qA;
queue<int> qB;

int main()
{
    int n, id;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>id;
        if(id % 2 != 0) qA.push(id);
        else qB.push(id);
    }
    bool flag = false;
    while(!qA.empty() || !qB.empty()) {
        for(int i = 0; i < 2; i++) {        // ���������
            if(qA.empty()) break;           // û��ʱ����
            if(flag == true) cout<<" ";
            cout<<qA.front();
            qA.pop();
            flag = true;
        }
        if(!qB.empty()) {
            if(flag == true) cout<<" ";
            cout<<qB.front();
            qB.pop();
            flag = true;
        }
    }
    return 0;
}
