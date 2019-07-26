#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
    int m;
    cin>>m;
    for(int i = 0; i < m; i++) {
        string str;
        bool flag = false;
        cin>>str;
        int len = str.length();
        int n = atoi(str.c_str());
        for(int j = 1; j < 10; j++) {
            if((j * n * n) % (int(pow(10, len) + 0.01)) == n) {
                cout<<j<<" "<<j * n * n<<endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout<<"No"<<endl;
    }
    return 0;
}
