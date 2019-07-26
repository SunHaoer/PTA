#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
const int MAX = 100010;

struct School {
    string name;
    double score;
    int num;
    int ranked;
};

bool cmp(School a, School b) {
    if(a.score != b.score) return a.score > b.score;
    else if(a.num != b.num) return a.num < b.num;
    else return a.name < b.name;
}
map<string, School> school;
vector<School> ans;

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        string stuSchool, id;
        double score;
        cin>>id>>score>>stuSchool;
        for(int i = 0; i < stuSchool.size(); i++) {
            stuSchool[i] = tolower(stuSchool[i]);
        }
        if(id[0] == 'T') score = score * 1.5;
        else if(id[0] == 'A') score = score * 1.0;
        else if(id[0] == 'B') score = score / 1.5;
        school[stuSchool].score += score;
        school[stuSchool].name = stuSchool;
        school[stuSchool].num++;
    }
    cout<<school.size()<<endl;
    for(map<string, School>::iterator it = school.begin(); it != school.end(); it++) {
        ans.push_back(it -> second);
    }
    for(int i = 0; i < ans.size(); i++) {
        ans[i].score = (int)(ans[i].score);
    }
    sort(ans.begin(), ans.end(), cmp);
    ans[0].ranked = 1;
    for(int i = 1; i < ans.size(); i++) {
        if(ans[i].score == ans[i - 1].score) ans[i].ranked = ans[i - 1].ranked;
        else ans[i].ranked = i + 1;
    }
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i].ranked<<" "<<ans[i].name<<" "<<(int)ans[i].score<<" "<<ans[i].num<<endl;
    }
    return 0 ;
}
