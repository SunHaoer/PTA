#include<iostream>
using namespace std;
// �׻� + �һ� = ��
struct event {
    int a, b, c, d, e;        // �׺� �׻� �Һ� �һ� ����֮��
} eve[101];

int main()
{
    int repeat, m=0, n=0;
    cin>>repeat;              // ���뻮ȭ����
    for(int i = 0; i < repeat; i++) {
        cin>>eve[i].a>>eve[i].b>>eve[i].c>>eve[i].d;
        eve[i].e = eve[i].a + eve[i].c;
        if(eve[i].b != eve[i].d) {           // �ǹ�Ӯ
            if(eve[i].e == eve[i].b) {       // ��Ӯ
                m++;                         // �ҺȾ�
            }
            if(eve[i].e == eve[i].d) {       // ��Ӯ
                n++;                         // �׺Ⱦ�
            }
        }
    }
    cout<<n<<' '<<m<<endl;
    return 0;
}
