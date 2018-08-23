#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct Student {
    string name;
    double grade1, grade2, grade3, grade4;
    Student () {
        grade1 = -1;
        grade2 = -1;
        grade3 = -1;
        grade4 = -1;
    }
};
map<string, Student> table;     // table[name] = Student
map<string, bool> isPass;       // table[name] 是否通过
vector<Student> vec;            // 合格的stu

bool cmp(Student a, Student b) {
    if(a.grade4 != b.grade4) return a.grade4 > b.grade4;
    else return a.name < b.name;
}

int main()
{
    int n1, n2, n3;
    string name;
    double grade;
    cin>>n1>>n2>>n3;
    for(int i = 0; i < n1; i++) {   // 输入1
        cin>>name>>grade;
        if(grade >= 200) {    // 编程题大于等于200
            isPass[name] = true;
            table[name].name = name;
            table[name].grade1 = grade;
        }
    }
    for(int i = 0; i < n2; i++) {   // 输入2
        cin>>name>>grade;
        if(isPass[name]) {
            table[name].grade2 = grade;
        }
    }
    for(int i = 0; i < n3; i++) {   // 输入3
        cin>>name>>grade;
        if(isPass[name]) {
            table[name].grade3 = grade;
            if(table[name].grade2 > table[name].grade3) {   // 期中>期末
                table[name].grade4 = (int)(table[name].grade2 * 0.4 + table[name].grade3 * 0.6 + 0.5);
            } else {                // 期末>=期中
                table[name].grade4 = table[name].grade3;
            }
        }
    }
    for(map<string, Student>::iterator it = table.begin(); it != table.end(); it++) {   // 找出合格的stu
        name = it->first;
        if(table[name].grade4 >= 60) {      // 期末60以上合格
            vec.push_back(it->second);
        }
    }
    sort(vec.begin(), vec.end(), cmp);      // 排序
    for(int i = 0; i < vec.size(); i++) {   // 输出
        cout<<vec[i].name<<" "<<vec[i].grade1<<" "<<vec[i].grade2<<" "<<vec[i].grade3<<" "<<vec[i].grade4<<endl;
    }
    return 0;
}
