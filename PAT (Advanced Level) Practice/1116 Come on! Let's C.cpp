#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAX = 10000;
string table[MAX];
int prime[MAX];

bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    fill(table, table + MAX, "Are you kidding?");
    int n, k;
    cin>>n;
    int tempId;
    cin>>tempId;
    table[tempId] = "Mystery Award";
    for(int i = 2; i <= n; i++) {        // ����
        cin>>tempId;
        if(isPrime(i)) {        // ������
            table[tempId] = "Minion";
        } else {                        // ����
            table[tempId] = "Chocolate";
        }
    }
    cin>>k;
    for(int i = 0; i < k; i++) {        // ��ѯ
        cin>>tempId;
        printf("%04d: ", tempId);
        cout<<table[tempId]<<endl;
        if(table[tempId] != "Are you kidding?") {
            table[tempId] = "Checked";
        }
    }
    return 0;
}
