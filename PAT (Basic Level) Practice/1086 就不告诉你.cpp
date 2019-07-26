#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

int main()
{
	int a, b, c;
	string str;
	cin>>a>>b;
	c = a * b;
	stringstream stream;
	stream<<c;
	stream>>str;
	reverse(str.begin(), str.end());
	while(str[0] == '0') {
        str.erase(str.begin());
	}
    if(str != "") cout<<str<<endl;
    else cout<<"0"<<endl;
	return 0;
}
