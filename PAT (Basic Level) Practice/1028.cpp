#include<iostream>
using namespace std;
int ans = 0;      //��¼����

struct people{
    string name;    //����
    string date;      //������
}maxn, minn, peo;

int check(people peo){
    if(peo.date < "1814/09/06" || peo.date > "2014/09/06") {         //�����������
        return 0;
    }
    if(peo.date < maxn.date){                       // ���������
        maxn.name = peo.name;
        maxn.date = peo.date;
    }
    if(peo.date > minn.date){                       // ������С��
        minn.name = peo.name;
        minn.date = peo.date;
    }
    ans++;
    return 0;
}

int main()
{
    int N;          // N����
    cin>>N;
    maxn.date = "20151332";
    minn.date = "00000000";
    for(int i = 0; i < N; i++) {
        cin>>peo.name;       // ��������
        cin>>peo.date;       // ��������
        check(peo);
    }
    if(ans == 0) cout<<'0'<<endl;
    else cout<<ans<<' '<<maxn.name<<' '<<minn.name;
    return 0;
}
