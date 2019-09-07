#include<iostream>
#include<map>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;

struct School {
    string name;
    double score;
    int cnt, ranked;
};
map<string, School> table1;
vector<School> table2;

bool cmp(School a, School b) {
    if(a.score != b.score) return a.score > b.score;
    else if(a.cnt != b.cnt) return a.cnt < b.cnt;
    else return a.name < b.name;
}

string strToLower(string str) {     // 转小写
    for(int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {    // 输入
        string id, name;
        double score;
        cin>>id>>score>>name;
        name = strToLower(name);
        if(id[0] == 'B') {
            score /= 1.5;
        }
        if(id[0] == 'T') {
            score *= 1.5;
        }
        table1[name].name = name;
        table1[name].score += score;
        table1[name].cnt++;
    }
    for(map<string, School>::iterator it = table1.begin(); it != table1.end(); it++) {    // map->vector
        it->second.score = int(it->second.score);
        table2.push_back(it->second);
    }
    sort(table2.begin(), table2.end(), cmp);
    cout<<table2.size()<<endl;                      // 输出
    for(int i = 0; i < table2.size(); i++) {
        if(i == 0) table2[i].ranked = 1;
        else if(table2[i].score == table2[i - 1].score) table2[i].ranked = table2[i - 1].ranked;
        else table2[i].ranked = i + 1;
        cout<<table2[i].ranked<<" "<<table2[i].name<<" "<<table2[i].score<<" "<<table2[i].cnt<<endl;
    }
    return 0;
}
