#include<iostream>
#include<cstdio>
using namespace std;
int n1 = 0, n2 = 0, n3 = 0;
string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

void fun1(string str1, string str2) {
    int i = 0;
    for(i = 0; i < str1.size() && i < str2.size(); i++) {            // 计算日期
        if( (str1[i] == str2[i]) && (str1[i] >= 'A') && (str1[i] <= 'G') ) {
            n1 = str1[i] - 'A';
            break;
        }
    }
    for(i = i + 1; i < str1.size() && i < str2.size(); i++) {        // 计算小时
        if( (str1[i] == str2[i]) && (str1[i] >= 'A') && (str2[i] <= 'N') ) {
            n2 = str1[i] - 'A' + 10;
            break;
        }
        if( (str1[i] == str2[i]) && (str1[i] >= '0') && (str2[i] <= '9') ) {
            n2 = str1[i] - '0';
            break;
        }
    }
    return;
}

void fun2(string str3, string str4) {                                 // 计算分钟
    for(int i = 0; i < str3.size() && i < str4.size(); i++){
        if(str3[i] == str4[i] && ((str3[i] >= 'A' && str4[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z'))){
            n3 = i;
            break;
        }
    }
    return;
}

int main()
{
    string str1, str2, str3, str4;
    cin>>str1>>str2>>str3>>str4;
    fun1(str1, str2);
    fun2(str3, str4);
    cout<<day[n1]<<' ';
    printf("%02d:%02d", n2, n3);
    return 0;
}
