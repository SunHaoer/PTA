#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Student{
    string name, id;
    int grade;
};
vector<Student> stu;

bool cmp(Student a, Student b){
    return a.grade > b.grade;
}

int main()
{
    int n, grade1, grade2;
    cin>>n;
    while(n--){
        Student temp;
        cin>>temp.name>>temp.id>>temp.grade;
        stu.push_back(temp);
    }
    cin>>grade1>>grade2;
    for(int i=0; i<stu.size(); i++){
        if(stu[i].grade<grade1||stu[i].grade>grade2){
            stu.erase(stu.begin()+i);
            i--;
        }
    }
    sort(stu.begin(), stu.end(), cmp);
    if(stu.empty()==true){
        cout<<"NONE"<<endl;
    }
    else{
        for(int i=0; i<stu.size(); i++){
            cout<<stu[i].name<<' '<<stu[i].id<<endl;
        }
    }
    return 0;
}
