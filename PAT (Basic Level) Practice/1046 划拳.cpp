#include<iostream>
using namespace std;
// 甲划 + 乙划 = 喊
struct event {
    int a, b, c, d, e;        // 甲喊 甲划 乙喊 乙划 喊数之和
} eve[101];

int main()
{
    int repeat, m=0, n=0;
    cin>>repeat;              // 输入划拳次数
    for(int i = 0; i < repeat; i++) {
        cin>>eve[i].a>>eve[i].b>>eve[i].c>>eve[i].d;
        eve[i].e = eve[i].a + eve[i].c;
        if(eve[i].b != eve[i].d) {           // 非共赢
            if(eve[i].e == eve[i].b) {       // 甲赢
                m++;                         // 乙喝酒
            }
            if(eve[i].e == eve[i].d) {       // 乙赢
                n++;                         // 甲喝酒
            }
        }
    }
    cout<<n<<' '<<m<<endl;
    return 0;
}
