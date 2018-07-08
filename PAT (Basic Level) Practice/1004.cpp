#include<iostream>
using namespace std;

struct student {
    string name;
    string id;
    int mark;
};

int main()
{
    int n;
    cin>>n;
    student s, maxs, mins;
    int maxn = -1, minn = 101;
    for(int i = 0; i < n; i++){
        cin>>s.name>>s.id>>s.mark;
        if(s.mark > maxn){
            maxs = s;
            maxn = s.mark;
        }
        if(s.mark < minn){
            mins = s;
            minn = s.mark;
        }
    }
    cout<<maxs.name<<' '<<maxs.id<<endl;
    cout<<mins.name<<' '<<mins.id<<endl;
    return 0;
}
