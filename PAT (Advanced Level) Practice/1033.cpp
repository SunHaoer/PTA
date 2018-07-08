#include<cstdio>
#include<algorithm>
using namespace std;

struct Station{
    double price, dis;      //�۸�, ��������
}sta[510];

bool cmp(Station a, Station b){
    return a.dis < b.dis;
}

int main()
{
    int n;
    double Cmax, D, Davg;
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);        //�������, ���յ����, ��λ���;���
    for(int i=0; i<n; i++){
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    }
    sta[n].price = 0;       //sta[n]�����յ�
    sta[n].dis = D;
    sort(sta, sta+n, cmp);
    if(sta[0].dis!=0){      //���û�м���վ
        printf("The maximum travel distance = 0.00\n");
    }
    else{
        int now = 0;        //��ǰ����վ���
        double ans = 0, nowTank = 0, MAX = Cmax * Davg;     //�ܻ���, ��ǰ����, ��󺽳�
        while(now<n){
            //ѡ����һ���ȵ�ǰ���˵ļ���վ, ��û����ѡ����˵�
            int k = -1;         //����˵ļ���վ���
            double priceMin = 1024;
            for(int i=now+1; i<=n&&sta[i].dis-sta[now].dis<=MAX; i++){
                if(sta[i].price<priceMin){
                    priceMin = sta[i].price;
                    k = i;
                    if(priceMin<sta[now].price){        //�ҵ����˵ļ���վ, ����Ѱ��
                        break;
                    }
                }
            }
            if(k==-1) break;        //û�м���վ��
            double need = (sta[k].dis - sta[now].dis ) / Davg;      //��now��k�ļ�����
            if(priceMin<sta[now].price){        //����վk���ڵ�ǰ�ͼ�, ֻ�赽����վk
                if(nowTank<need){            //��ǰ��������need
                    ans += (need - nowTank ) * sta[now].price;      //����need
                    nowTank = 0;
                }
                else{               //��������, ֱ��ȥk
                    nowTank -= need;
                }
            }
            else {          //����վk���ڵ�ǰ����վ, ����
                ans += (Cmax - nowTank) * sta[now].price;
                nowTank = Cmax - need;
            }
            now = k;
        }
        if(now==n){     //�ܵ��յ�
            printf("%.2f", ans);
        }
        else {      //���ܵ��յ�
            printf("The maximum travel distance = %.2f", sta[now].dis+MAX);
        }
    }
    return 0;
}
