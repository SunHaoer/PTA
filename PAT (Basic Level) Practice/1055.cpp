#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
const int MAX1 = 10, MAX2 = 10100;

struct Student {
    string name;
    int high;
} stu[100010];
Student table[MAX1][MAX2];

bool cmp(Student a, Student b) {
    if(a.high != b.high) return a.high < b.high;
    else return a.name > b.name;
}

int main()
{
    int n, k, num, ans = 0;       // ����n, ����k
    cin>>n>>k;
    num = n / k;                  // ÿ��num��
    for(int i = 0; i < n; i++) {
        cin>>stu[i].name>>stu[i].high;
    }
    sort(stu, stu + n, cmp);
    for(int i = 0; i < k; i++) {        // �ܹ���k��
        int flag = 1;
        if(i == k - 1) num = n / k + n % k;
        else num = n / k;
        if(num % 2 == 0) flag = -1;         // ż������, ������ʽ����
        for(int j = 0; j < num; j++) {      // ÿ��num��
            if(flag == 1) table[k - 1 - i][num - 1 - j / 2] = stu[ans++];
            else table[k - 1 - i][j / 2] = stu[ans++];
            flag = -flag;
        }
    }
    for(int i = 0; i < k; i++) {
        if(i == 0) num = n / k + n % k;
        else num = n / k;
        for(int j = 0; j < num; j++) {
            if(j != 0) cout<<" ";
            cout<<table[i][j].name;
        }
        cout<<endl;
    }
    return 0;
}


