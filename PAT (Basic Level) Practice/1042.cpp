#include<iostream>
#include<cctype>
using namespace std;
int hashTable[26] = { 0 };

int main()
{
    string str;
    int maxn = 0;
    char maxc;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++) {           // ͳ���ַ�
        str[i] = tolower(str[i]);
        if(str[i] >= 'a' && str[i] <= 'z') {
            hashTable[str[i] - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++) {                   // Ѱ�����ֵ
        if(hashTable[i] > maxn) {
            maxn = hashTable[i];
            maxc = 'a' + i;
        }
    }
    cout<<maxc<<' '<<maxn<<endl;
    return 0;
}
