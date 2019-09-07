#include<iostream>
using namespace std;
const int MAX = 10010;
int arr[MAX] = { 0 }, ans = 0;

void fun1(int num, int n){
    do{
        arr[ans++] = num % n;
        num /= n;
    } while(num!=0);
    return;
}

bool fun2(){
    for(int i=0; i<=ans/2; i++){
        if(arr[i]!=arr[ans-i-1]){
            return false;
        }
    }
    return true;
}

int main()
{
    int num, n;
    cin>>num>>n;
    fun1(num, n);
    if (fun2()==true){      // 回文
        cout<<"Yes"<<endl;
    }
    else {          // 非回文
        cout<<"No"<<endl;
    }
    for(int i=ans-1; i>0; i--){
        cout<<arr[i]<<' ';
    }
    cout<<arr[0]<<endl;
    return 0;
}
