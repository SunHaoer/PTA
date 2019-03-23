#include<iostream>
using namespace std;

int main()
{
    char ch[4] = {'G', 'P', 'L', 'T'};
    int ans[4];
    fill(ans, ans + 4, 0);
    string str;
    cin>>str;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'G' || str[i] == 'g') ans[0]++;
        if(str[i] == 'P' || str[i] == 'p') ans[1]++;
        if(str[i] == 'L' || str[i] == 'l') ans[2]++;
        if(str[i] == 'T' || str[i] == 't') ans[3]++;
    }
    while(ans[0] + ans[1] + ans[2] + ans[3] != 0) {
        for(int i = 0; i < 4; i++) {
            if(ans[i] != 0) {
                cout<<ch[i];
                ans[i]--;
            }
        }
    }
    return 0;
}
