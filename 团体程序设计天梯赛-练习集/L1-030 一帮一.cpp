#include<iostream>
#include<vector>
using namespace std;
const int MAX = 50;
int arr1[MAX], arr2[MAX];
int ans1 = 0, ans2 = 0;

struct Student {
    int sex;
    string name;
};
vector<Student> stu;

int main()
{
    int n;
    cin>>n;
    Student tempStu;
    for(int i = 0; i < n; i++) {
        cin>>tempStu.sex>>tempStu.name;
        stu.push_back(tempStu);
    }
    while(!stu.empty()) {
        cout<<stu[0].name<<" ";
        for(int i = stu.size() - 1; i >= 0; i--) {
            if(stu[i].sex != stu[0].sex) {
                cout<<stu[i].name<<endl;
                stu.erase(stu.begin() + i);
                stu.erase(stu.begin());
                break;
            }
        }
    }
    return 0;
}
