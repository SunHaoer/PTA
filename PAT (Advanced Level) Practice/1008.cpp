#include<iostream>
using namespace std;

int main()
{
    int num, next = 0, floor = 0, temp = 0, time = 0;
    cin>>num;
    for(int i=0; i<num; i++){
        cin>>next;
        floor = next - temp;
        if(floor>0){
            time = time + floor * 6 + 5;
        }
        else {
            time = time - floor * 4 + 5;
        }
        temp = next;
    }
    cout<<time<<endl;
    return 0;
}
