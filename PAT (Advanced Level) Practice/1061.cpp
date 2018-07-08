#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;

int main()
{
    string day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string str1, str2, str3, str4;
    bool flag = false;
    cin>>str1>>str2>>str3>>str4;
    for(int i = 0; i < str1.size() && i < str2.size(); i++) {
        if(flag == false && isupper(str1[i]) && str1[i] <= 'G' && str1[i] == str2[i] ) {
            cout<<day[str1[i] - 'A']<<" ";
            flag = true;
        } else if(flag == true && isdigit(str1[i]) && str1[i] == str2[i]) {
            cout<<"0"<<str1[i]<<":";
            break;
        } else if(flag == true && isupper(str1[i]) && str1[i] <= 'N' && str1[i] == str2[i]) {
            cout<<(str1[i] - 'A' + 10)<<":";
            break;
        }
    }
    for(int i = 0; i < str3.size() && i < str4.size(); i++) {
        if((islower(str3[i]) || isupper(str3[i])) && str3[i] == str4[i]) {
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}
