#include<iostream>
#include<set>
using namespace std;

int main()
{
    int repeat, n, num = 0;
    set<int> s;
    cin>>repeat;
    for(int i = 0; i < repeat; i++) {
        cin>>n;
        num  = 0;
        while(n != 0) {
            num += n % 10;
            n /= 10;
        }
        s.insert(num);
    }
    cout<<s.size()<<endl;
    bool flag = false;
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
        if(flag == true) cout<<" ";
        cout<<*it;
        flag = true;
    }
    return 0;
}

/*
*  set集合是一个内部自动有序且不含重复元素的容器
*/
