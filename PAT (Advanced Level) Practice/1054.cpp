#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
map<string, int> mp;

int main()
{
    int m, n;
    string color, maxColor;
    int maxNum = -1;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++) {        // 输入
        for(int j = 0; j < m; j++) {
            color.resize(15);
            scanf("%s", &color[0]);
            mp[color.c_str()]++;
        }
    }
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {     // 找最大值
        if(it->second > maxNum) {
            maxNum = it->second;
            maxColor = it->first;
        }
    }
    printf("%s\n", maxColor.c_str());
    return 0;
}
