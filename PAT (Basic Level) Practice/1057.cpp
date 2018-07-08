#include<iostream>
using namespace std;

int change(string str) {
    int num = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {              // 小写字母
            str[i] = str[i] - 'a' + 1;
        } else if(str[i] >= 'A' && str[i] <= 'Z') {       // 大写字母
            str[i] = str[i] - 'A' + 1;
        }
        else continue;
        num = num + str[i];
    }
    return num;
}

int main()
{
    string str;
    getline(cin,str);
    int ans[2] = { 0 };      // 统计0,1个数
    int num = change(str);
    while(num) {
        if(num % 2 == 0) ans[0]++;
        else if(num % 2 == 1) ans[1]++;
        num = num / 2;
    }
    cout<<ans[0]<<' '<<ans[1]<<endl;
    return 0;
}
