#include<iostream>
#include<map>
using namespace std;

int main()
{
    int k;
    string str;
    map<char, bool> isBreak, notBreak, isPrint;
    cin>>k>>str;
    str = "#" + str + "#";
    int cnt = 1;
    for(int i = 0; i < str.size(); i++) {       // ¼ì²â»µ¼ü
        if(str[i] == str[i - 1]) {      // ÏàÍ¬
            cnt++;
            if(cnt % k == 0) {      // »µÁË
                isBreak[str[i]] = true;
            }
        } else {       // Ã»»µ
            if( (str[i] != str[i - 1] && str[i] != str[i + 1])) {
                notBreak[str[i]] = true;
            }
            if(cnt % k != 0) {              // 3 aaaa  Ã»»µ
                notBreak[str[i - 1]] = true;
            }
            cnt = 1;
        }
    }
    for(int i = 1; i < str.size() - 1; i++) {           // Êä³ö»µ¼ü

        if(notBreak[str[i]]) {
            isBreak[str[i]] = false;
        }

        if(isBreak[str[i]] && !isPrint[str[i]]) {
            cout<<str[i];
            isPrint[str[i]] = true;
        }
    }
    cout<<endl;
    for(int i = 1; i < str.size() - 1; i++) {           // Êä³ö
        cout<<str[i];
        if(isBreak[str[i]]) {
            i = i + k - 1;
        }
    }
    return 0;
}
