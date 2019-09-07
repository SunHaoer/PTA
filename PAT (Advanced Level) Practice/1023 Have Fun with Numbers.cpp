#include<iostream>
#include<algorithm>
using namespace std;
int arr1[10] = { 0 }, arr2[10] = { 0 };

void init(int arr[]) {      // ��ʼ������
    for(int i = 0; i < 10; i++) {
        arr[i] = 0;
    }
}

string fun1(string str) {                       // str1 * 2
    string result = "";
    int a = 0, b = 0;
    for(int i = str.size() - 1; i >= 0; i--) {
        a = str[i] - '0';
        if(a * 2 < 10) {
            result += (a * 2 + b) + '0';
            b = 0;
        } else {
            result += (a * 2 + b- 10) + '0';
            b = 1;
        }
    }
    if(b != 0) {
        result += (b + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}

void fun2(string str, int arr[]) {             // ͳ��ÿ���ַ���
    for(int i = 0; i < str.size(); i++) {
        arr[str[i] - '0']++;
    }
    return;
}

bool fun3(int arr1[], int arr2[]) {         // �Ƚ�arr1, arr2
    for(int i = 0; i < 10; i++) {
        if(arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    string str, str1, str2;
    int len1 = 0, len2 = 0;
    bool flag = false;          // �ж��Ƿ��н�
    cin>>str1;
    str = str1;
    while(len1 == len2) {
        init(arr1);
        init(arr2);
        len1 = str1.size();     // ԭ����
        fun2(str1, arr1);       // ͳ��str1���ַ�
        str2 = fun1(str1);
        len2 = str2.size();     // �ı������
        fun2(str2, arr2);       // ͳ��str2���ַ�
        if(fun3(arr1, arr2) == true) {
            flag = true;
            break;
        }
        str1 = str2;
    }
    if(flag == true) {
        cout<<"Yes"<<endl;
        cout<<str2<<endl;
    } else {
        cout<<"No"<<endl;
        cout<<fun1(str)<<endl;
    }
    return 0;
}
