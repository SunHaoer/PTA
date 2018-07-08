#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    char a[100001], b[100001];
    int repeat, j = 0, y = 0, p = 0;        // 甲, 乙, 平
    int js[3] = {0}, ys[3] = {0};           // 甲乙锤子, 剪刀, 布胜的次数
    cin>>repeat;
    for(int i = 0; i < repeat; i++){
        cin>>a[i]>>b[i];
        if(a[i] == 'C'){
            if(b[i] == 'C'){
                p++;
            }
            if(b[i] == 'J'){
                j++;
                js[1]++;
            }
            if(b[i] == 'B'){
                y++;
                ys[0]++;
            }
        }
        if(a[i] == 'J'){
            if(b[i] == 'C'){
                y++;
                ys[1]++;
            }
            if(b[i] == 'J'){
                p++;
            }
            if(b[i] == 'B'){
                j++;
                js[2]++;
            }
        }
        if(a[i] == 'B'){
            if(b[i] == 'C'){
                j++;
                js[0]++;
            }
            if(b[i] == 'J'){
                y++;
                ys[2]++;
            }
            if(b[i] == 'B'){
                p++;
            }
        }
    }
    cout<<j<<' '<<p<<' '<<y<<endl;
    cout<<y<<' '<<p<<' '<<j<<endl;
    int maxj = -1, jmax = -1, maxy = -1, ymax = -1;             // 计算甲乙胜利次数最多的手势
    string str = "BCJ";
    for(int i = 0; i < 3; i++){
        if(js[i] > maxj){
            maxj = js[i];
            jmax = i;
        }
    }
    for(int i = 0; i < 3; i++){
        if(ys[i] > maxy){
            maxy = ys[i];
            ymax = i;
        }
    }
    cout<<str[jmax]<<' '<<str[ymax]<<endl;
    return 0;
}
