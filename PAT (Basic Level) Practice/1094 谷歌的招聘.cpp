#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main()
{
    int l, k;
    string str;
    bool flag = false;
    cin>>l>>k>>str;
    for(int i = 0; i <= l - k; i++) {
        string temp = str.substr(i, k);
        if(isPrime(atoi(temp.c_str()))) {
            cout<<temp<<endl;
            flag = true;
            break;
        }
    }
    if(!flag) cout<<"404"<<endl;
    return 0;
}
