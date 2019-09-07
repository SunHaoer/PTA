#include<cstdio>
#include<algorithm>
using namespace std;

struct Station{
    double price, dis;      //价格, 与起点距离
}sta[510];

bool cmp(Station a, Station b){
    return a.dis < b.dis;
}

int main()
{
    int n;
    double Cmax, D, Davg;
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);        //最大油量, 与终点距离, 单位汽油距离
    for(int i=0; i<n; i++){
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    }
    sta[n].price = 0;       //sta[n]放置终点
    sta[n].dis = D;
    sort(sta, sta+n, cmp);
    if(sta[0].dis!=0){      //起点没有加油站
        printf("The maximum travel distance = 0.00\n");
    }
    else{
        int now = 0;        //当前加油站编号
        double ans = 0, nowTank = 0, MAX = Cmax * Davg;     //总花费, 当前油量, 最大航程
        while(now<n){
            //选出第一个比当前便宜的加油站, 若没有则选最便宜的
            int k = -1;         //最便宜的加油站编号
            double priceMin = 1024;
            for(int i=now+1; i<=n&&sta[i].dis-sta[now].dis<=MAX; i++){
                if(sta[i].price<priceMin){
                    priceMin = sta[i].price;
                    k = i;
                    if(priceMin<sta[now].price){        //找到便宜的加油站, 不再寻找
                        break;
                    }
                }
            }
            if(k==-1) break;        //没有加油站了
            double need = (sta[k].dis - sta[now].dis ) / Davg;      //从now到k的加油量
            if(priceMin<sta[now].price){        //加油站k低于当前油价, 只需到加油站k
                if(nowTank<need){            //当前油量不足need
                    ans += (need - nowTank ) * sta[now].price;      //不足need
                    nowTank = 0;
                }
                else{               //油量充足, 直接去k
                    nowTank -= need;
                }
            }
            else {          //加油站k高于当前加油站, 加满
                ans += (Cmax - nowTank) * sta[now].price;
                nowTank = Cmax - need;
            }
            now = k;
        }
        if(now==n){     //能到终点
            printf("%.2f", ans);
        }
        else {      //不能到终点
            printf("The maximum travel distance = %.2f", sta[now].dis+MAX);
        }
    }
    return 0;
}
