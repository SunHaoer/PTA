#include<iostream>
#include<map>
#include<cctype>
using namespace std;
map<string, int> mp;

int main()
{
    string str;
    getline(cin, str);
    str += '.';
    string word = "";
    for(int i = 0; i < str.size(); i++) {
        if(isalnum(str[i])) {       // 是字母或数字
            str[i] = tolower(str[i]);
            word = word + str[i];
        } else {        // 一个单词结束
            if(word != "") mp[word]++;
            word = "";
        }
    }
    string maxWord;
    int maxCnt = -1;
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {     // 找最大值
        if((it->second > maxCnt) || (it->second == maxCnt && it->first < maxWord)) {
            maxCnt = it->second;
            maxWord = it->first;
        }
    }
    cout<<maxWord<<" "<<maxCnt<<endl;
    return 0;
}
