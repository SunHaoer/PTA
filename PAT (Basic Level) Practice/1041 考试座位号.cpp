#include<iostream>
#include<map>
using namespace std;
const int MAX = 1010;

struct Student {
    long long id;
    int a, b;       // �Ի�, ����
} stu[MAX];

int main()
{
    int n, m;
    cin>>n;
    for(int i = 0; i < n; i++) {            // ������Ϣ
        Student temp;
        cin>>temp.id>>temp.a>>temp.b;
        stu[temp.a] = temp;
    }
    cin>>m;
    for(int i = 0; i < m; i++) {            // ��ѯ��Ϣ
        int a;
        cin>>a;
        cout<<stu[a].id<<" "<<stu[a].b<<endl;
    }
    return 0;
}
