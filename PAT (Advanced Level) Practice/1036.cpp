#include<iostream>
using namespace std;

struct Student{
    string name, sex, id;
    int grade;
};

int main()
{
    int n;
    cin>>n;
    Student stu, mstu, fstu;
    mstu.grade = 101;
    fstu.grade = -1;
    for(int i=0; i<n; i++){
        cin>>stu.name>>stu.sex>>stu.id>>stu.grade;
        if(stu.sex=="M"){
            if(stu.grade<mstu.grade){
                mstu = stu;
            }
        }
        else{
            if(stu.grade>fstu.grade){
                fstu = stu;
            }
        }
    }
    if(fstu.grade!=-1) cout<<fstu.name<<' '<<fstu.id<<endl;
    else cout<<"Absent"<<endl;
    if(mstu.grade!=101) cout<<mstu.name<<' '<<mstu.id<<endl;
    else cout<<"Absent"<<endl;
    if(fstu.grade!=-1&&mstu.grade!=101) cout<<fstu.grade-mstu.grade<<endl;
    else cout<<"NA"<<endl;
    return 0;
}
